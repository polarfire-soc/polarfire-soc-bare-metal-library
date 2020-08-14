/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software example
 *
 */
/*******************************************************************************
 *
 * Code running on E51
 *
 */

#include <stdio.h>
#include <string.h>
#include "inc/common.h"
#include "mpfs_hal/mss_hal.h"

#ifndef SIFIVE_HIFIVE_UNLEASHED
#include "drivers/mss_uart/mss_uart.h"
#include "ymodem/ymodem.h"
#include "drivers/mss_envm/mss_envm.h"
#else
#include "drivers/FU540_uart/FU540_uart.h"
#endif

/*******************************************************************************
 * Instruction message. This message will be transmitted over the UART to
 * HyperTerminal when the program starts.
 ******************************************************************************/
#ifdef DEBUG_DDR_INIT
const uint8_t g_message[] =
        "\r\n\r\n\r\n\
MPFS HAL DDR example version 0.3.3\r\n\
This program is run from E51\r\n\
This program can load a program to DDR using ymodem\r\n\
and has option to run the image using hart1 \r\n\
Type 0  Show this menu\r\n\
Type 1  Show ddr training values\r\n\
Type 2  Raise sw int hart 2\r\n\
Type 3  Raise sw int hart 3\r\n\
Type 4  Raise sw int hart 4\r\n\
Type 5  Print debug messages from hart0\r\n\
Type 6  load image to DDR\r\n\
Type 7  Start U54_1 running image in DDR\r\n\
";
#else
const uint8_t g_message[] =
        "\r\n\r\n\r\n\
MPFS HAL DDR example version 0.3.3\r\n\
This program is run from E51\r\n\
This program can load a program to DDR using ymodem\r\n\
and has option to run the image using hart1 \r\n\
Type 0  Show this menu\r\n\
Type 1  Not used\r\n\
Type 2  Raise sw int hart 2\r\n\
Type 3  Raise sw int hart 3\r\n\
Type 4  Raise sw int hart 4\r\n\
Type 5  Print debug messages from hart0\r\n\
Type 6  load image to DDR\r\n\
Type 7  Start U54_1 running image in DDR\r\n\
";
#endif

#define MAX_BUFFER_SIZE 128

static volatile uint32_t count_sw_ints_h0 = 0U;
volatile uint32_t g_10ms_count;
uint8_t data_block[256];
uint64_t hart1_jump_ddr = 0U;
mss_uart_instance_t *g_uart= &g_mss_uart0_lo ;
mss_uart_instance_t *g_debug_uart= &g_mss_uart0_lo ;
uint64_t uart_lock;
MEM_TYPE mem_area = E51_DDR_START_CACHE;

/*
 * Local functions
 */
__attribute__((section(".ram_codetext"))) \
        static void loop_in_dtim(void);

/*
 * Extern functions
 */
extern uint32_t tip_register_status (mss_uart_instance_t *g_mss_uart_debug_pt);

/**
 * Simple jump to application
 * @param mem_area
 */
void jump_to_application( MEM_TYPE mem_area)
{
    /* Restore PLIC to known state: */
    __disable_irq();
    PLIC_init();

    /* Disable all interrupts: */
    write_csr(mie, 0);

    switch(mem_area)
    {
        default:
        case E51_DDR_START_NON_CACHE:
            /* Start executing from the top of DDR memory: */
            __asm volatile("lui ra,0x0C000");
            __asm volatile("slli ra, ra,0x4");
            break;
        case E51_DDR_START_CACHE:
            /* Start executing from the top of DDR memory: */
            __asm volatile("lui ra,0x08000");
            __asm volatile("slli ra, ra,0x4");
            break;
    }
    __asm volatile("ret");
    /*User application execution should now start and never return here.... */
}

/* Main function for the HART0(E51 processor).
 * Application code running on HART0 is placed here.
 */
void e51(void)
{
    int8_t info_string[100];
    uint64_t mcycle_start = 0U;
    uint64_t mcycle_end = 0U;
    uint64_t delta_mcycle = 0U;
    uint8_t rx_buff[1];
    uint64_t hartid = read_csr(mhartid);
    uint8_t rx_size = 0;
    uint8_t debug_hart0 = 0U;
    uint8_t rcv_buff[MAX_BUFFER_SIZE] = {0};
    uint8_t erase_sector_buff[MAX_BUFFER_SIZE] = {0};
    volatile uint32_t  received = 0;

    uint8_t *bin_base = (uint8_t *)0xC0000000;
    uint32_t g_rx_size = 1024 * 128;
    uint8_t buffer[256];

    /* Turn on UART0 clock */
    SYSREG->SUBBLK_CLOCK_CR |= (SUBBLK_CLOCK_CR_MMUART0_MASK |\
            SUBBLK_CLOCK_CR_MMUART1_MASK |\
            SUBBLK_CLOCK_CR_MMUART2_MASK |\
            SUBBLK_CLOCK_CR_MMUART3_MASK |\
            SUBBLK_CLOCK_CR_MMUART4_MASK);
    /* Remove soft reset */
    SYSREG->SOFT_RESET_CR   &= ~(SUBBLK_CLOCK_CR_MMUART0_MASK |\
            SUBBLK_CLOCK_CR_MMUART1_MASK |\
            SUBBLK_CLOCK_CR_MMUART2_MASK |\
            SUBBLK_CLOCK_CR_MMUART3_MASK |\
            SUBBLK_CLOCK_CR_MMUART4_MASK);

    /*This mutex is used to serialize accesses to UART0 when all harts want to
     * TX/RX on UART0. This mutex is shared across all harts.*/
    mss_init_mutex((uint64_t)&uart_lock);

    MSS_UART_init( &g_mss_uart0_lo,
            MSS_UART_115200_BAUD,
            MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
//#define debug_uarts
#ifdef debug_uarts
    MSS_UART_init( &g_mss_uart1_lo,
        MSS_UART_115200_BAUD,
        MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
    MSS_UART_init( &g_mss_uart2_lo,
        MSS_UART_115200_BAUD,
        MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
    MSS_UART_init( &g_mss_uart3_lo,
        MSS_UART_115200_BAUD,
        MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
    MSS_UART_init( &g_mss_uart4_lo,
        MSS_UART_115200_BAUD,
        MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
#endif

    MSS_UART_polled_tx_string (&g_mss_uart0_lo, g_message);
#ifdef debug_uarts
    MSS_UART_polled_tx_string (&g_mss_uart1_lo, g_message);
    MSS_UART_polled_tx_string (&g_mss_uart2_lo, g_message);
    MSS_UART_polled_tx_string (&g_mss_uart3_lo, g_message);
    MSS_UART_polled_tx_string (&g_mss_uart4_lo, g_message);
#endif

    SysTick_Config();

    /* Parameter is whole MHz */
    envm_set_clock(LIBERO_SETTING_MSS_SYSTEM_CLK / 1000000 );

    /* Start the other harts with appropriate UART input from user*/
    while (1)
    {
        mcycle_start = readmcycle();

        if (1u == debug_hart0)
        {
          debug_hart0 = 0U;
          sprintf(info_string,"Hart %ld, %ld delta_mcycle %ld mtime\r\n",
          hartid, delta_mcycle, readmtime());
          mss_take_mutex((uint64_t)&uart_lock);
          MSS_UART_polled_tx(&g_mss_uart0_lo, info_string,strlen(info_string));
          mss_release_mutex((uint64_t)&uart_lock);
        }

        mss_take_mutex((uint64_t)&uart_lock);
        rx_size = MSS_UART_get_rx(&g_mss_uart0_lo, rx_buff, sizeof(rx_buff));
        mss_release_mutex((uint64_t)&uart_lock);

        if (rx_size > 0)
        {
            switch(rx_buff[0])
            {
                case '0':
                    mss_take_mutex((uint64_t)&uart_lock);
                    MSS_UART_polled_tx_string (&g_mss_uart0_lo, g_message );
                    mss_release_mutex((uint64_t)&uart_lock);
                    break;
                case '1':
#ifdef DEBUG_DDR_INIT
                    tip_register_status (&g_mss_uart0_lo);
#endif
                    break;
                case '2':
                    raise_soft_interrupt(2u);
                    break;
                case '3':
                    raise_soft_interrupt(3u);
                    break;
                case '4':
                    raise_soft_interrupt(4u);
                    break;
                case '5':
                    debug_hart0 = 1;
                    break;
                case '6':
                    mss_take_mutex((uint64_t)&uart_lock);
                    MSS_UART_polled_tx_string(&g_mss_uart0_lo, (const uint8_t *)"\r\nsend .bin file using ymodem\r\n");
                    mss_release_mutex((uint64_t)&uart_lock);
                    bin_base = (uint8_t *)LIBERO_SETTING_DDR_32_CACHE;
                    received = ymodem_receive(bin_base, g_rx_size);
                    mss_take_mutex((uint64_t)&uart_lock);
                    MSS_UART_polled_tx_string (&g_mss_uart0_lo, "\n\rNow choose option 7\n\r" );
                    mss_release_mutex((uint64_t)&uart_lock);
                    break;
                case '7':
                    raise_soft_interrupt(1u);
                    hart1_jump_ddr = 1U;
#ifdef E51_ENTER_SLEEP_STATE
                    SysTick_off();
                    loop_in_dtim();
#endif
                    break;

                default:
                    /* echo input */
                    mss_take_mutex((uint64_t)&uart_lock);
                    MSS_UART_polled_tx_string(&g_mss_uart0_lo, rx_buff);
                    mss_release_mutex((uint64_t)&uart_lock);
                    break;
            }
        }

        mcycle_end    = readmcycle();
        delta_mcycle = mcycle_end - mcycle_start;
    }
}

/* HART0 Software interrupt handler */
void Software_h0_IRQHandler(void)
{
    uint64_t hart_id = read_csr(mhartid);
    count_sw_ints_h0++;
}

#if defined(TARGET_RENODE)
#define TIMER_INCREMENT 35 /* Adjust this to get the C prompt from YMODEM giving
                            * one C every second or so */
#else
#define TIMER_INCREMENT 1
#endif

void SysTick_Handler_h0_IRQHandler(void)
{
    g_10ms_count += TIMER_INCREMENT;
    if(g_10ms_count < TIMER_INCREMENT)
        g_10ms_count = 0;
}

/**
 * idle in DTIM
 * Note. Switch code is copied to DTIM on start-up.
 */
__attribute__((section(".ram_codetext"))) \
        static void loop_in_dtim(void)
{
    /*Put this hart into WFI.*/
    while(1U)
    {
        do
        {
            __asm("wfi");
        }while(0 == (read_csr(mip) & MIP_MSIP));
    }
}

/**
 * Setup serial port if DDR debug required during start-up
 * @param uart Ref to uart you want to use
 * @return
 */
uint32_t setup_ddr_debug_port(mss_uart_instance_t * uart)
{
#ifdef DEBUG_DDR_INIT
    /* Turn on UART0 clock */
    SYSREG->SUBBLK_CLOCK_CR |= (SUBBLK_CLOCK_CR_MMUART0_MASK);
    /* Remove soft reset */
    SYSREG->SOFT_RESET_CR   &= ~(SUBBLK_CLOCK_CR_MMUART0_MASK);
    MSS_UART_init( uart,
        MSS_UART_115200_BAUD,
            MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);
#endif
    return(0U);
}
