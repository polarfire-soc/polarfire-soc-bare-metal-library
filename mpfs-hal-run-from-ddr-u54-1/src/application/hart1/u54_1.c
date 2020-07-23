/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solution.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software example
 *
 */
/*******************************************************************************
 *
 * Code running on U54 first hart
 *
 */
#include <stdio.h>
#include <string.h>
#include "mpfs_hal/mss_hal.h"

#ifndef SIFIVE_HIFIVE_UNLEASHED
#include "drivers/mss_mmuart/mss_uart.h"
#else
#include "drivers/FU540_uart/FU540_uart.h"
#endif

volatile uint32_t count_sw_ints_h1 = 0U;

extern uint64_t uart_lock;

/* Main function for the HART1(U54_1 processor).
 * Application code running on HART1 is placed here
 *
 * The HART1 goes into WFI. HART0 brings it out of WFI when it raises the first
 * Software interrupt to this HART
 */
void u54_1(void)
{
    uint8_t info_string[100];
    uint64_t hartid = read_csr(mhartid);
    volatile uint32_t icount = 0U;

    /* Clear pending software interrupt in case there was any.
       Enable only the software interrupt so that the E51 core can bring this
       core out of WFI by raising a software interrupt. */
    clear_soft_interrupt();
    set_csr(mie, MIP_MSIP);

#ifndef MPFS_HAL_BOOT2
    /*Put this hart into WFI.*/
    do
    {
        __asm("wfi");
    }while(0 == (read_csr(mip) & MIP_MSIP));
#endif

    /* The hart is out of WFI, clear the SW interrupt. Hear onwards Application
       can enable and use any interrupts as required */
    clear_soft_interrupt();

    __enable_irq();

    /* Turn on UART0 clock */
    SYSREG->SUBBLK_CLOCK_CR |= SUBBLK_CLOCK_CR_MMUART1_MASK;
    /* Remove soft reset */
    SYSREG->SOFT_RESET_CR   &= ~SOFT_RESET_CR_MMUART1_MASK;

    /* This mutex is used to serialize accesses to UART0 when all harts want to
       TX/RX on UART0. This mutex is shared across all harts. */
    //fixme:does not like being called twice- to resolve  mss_init_mutex((uint64_t)&uart_lock);

    MSS_UART_init( &g_mss_uart1_lo,
    MSS_UART_115200_BAUD,
    MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);

    //fixme:does not like being called twice- to resolve mss_take_mutex((uint64_t)&uart_lock);
    MSS_UART_polled_tx_string(&g_mss_uart1_lo,
            "Hello World from u54 core 1 - hart1 running from DDR\r\n");
    //fixme:does not like being called twice- to resolve mss_release_mutex((uint64_t)&uart_lock);

    while (1U)
    {
        icount++;
        if (0x7FFFFFFFU == icount)
        {
            icount = 0U;
            sprintf(info_string,"Hart = %d, Readtime = %d  running from DDR\r\n"\
                    , hartid, readmtime());
            mss_take_mutex((uint64_t)&uart_lock);
            MSS_UART_polled_tx(&g_mss_uart1_lo, info_string,strlen(info_string));
            mss_release_mutex((uint64_t)&uart_lock);
        }
    }
    /* never return */
}

/* HART1 Software interrupt handler */
void Software_h1_IRQHandler(void)
{
    uint64_t hart_id = read_csr(mhartid);
    count_sw_ints_h1++;
}
