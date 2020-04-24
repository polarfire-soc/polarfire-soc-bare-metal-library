/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
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
 * SVN $Revision: 10516 $
 * SVN $Date: 2018-11-08 18:09:23 +0000 (Thu, 08 Nov 2018) $
 */

#include <stdio.h>
#include <string.h>
#include "mpfs_hal/mss_hal.h"

#ifndef SIFIVE_HIFIVE_UNLEASHED
#include "drivers/mss_uart/mss_uart.h"
#else
#include "drivers/FU540_uart/FU540_uart.h"
#endif

uint64_t get_SysTick(void);
uint64_t get_secs_since_start(void);

static volatile uint32_t count_sw_ints_h0 = 0U;

/*******************************************************************************
 * Instruction message. This message will be transmitted over the UART to
 * HyperTerminal when the program starts.
 ******************************************************************************/
const uint8_t g_message[] =
    "\r\n\r\n\r\n\
MPFS HAL example version 0.3.1\r\n\
This program is run from E51\r\n\
Type 0  Show this menu\r\n\
Type 1  Raise sw int hart 1\r\n\
Type 2  Raise sw int hart 2\r\n\
Type 3  Raise sw int hart 3\r\n\
Type 4  Raise sw int hart 4\r\n\
Type 5  Print debug messages from hart0\r\n\
Type 6  Start/Stop tick test hart0\r\n\
";

uint64_t uart_lock;

/* Main function for the HART0(E51 processor).
 * Application code running on HART0 is placed here.
 */
void e51(void)
{
    int8_t info_string[100];
    uint64_t mcycle_start = 0U;
    uint64_t mcycle_end = 0U;
    uint64_t delta_mcycle = 0U;
    uint64_t hartid = read_csr(mhartid);
    uint64_t current_sec;
    uint64_t last_sec;
    uint8_t rx_buff[1];
    uint8_t rx_size = 0;
    uint8_t debug_hart0 = 0U;
    uint8_t debug_tick = 0U;

    /*This mutex is used to serialize accesses to UART0 when all harts want to
     * TX/RX on UART0. This mutex is shared across all harts.*/
    mss_init_mutex((uint64_t)&uart_lock);
    MSS_FU540_UART_init(&g_mss_FU540_uart0,
    0,
    0); /* note-serial port baud = 57600 */
    PLIC_SetPriority(USART0_PLIC_4, 1);
    /* Enable UART Interrupt on PLIC */
    PLIC_EnableIRQ(USART0_PLIC_4);

    MSS_FU540_UART_polled_tx(&g_mss_FU540_uart0, g_message, sizeof(g_message));
    /* Start the tick timer */
    (void)SysTick_Config();
    /* Start the other harts with appropriate UART input from user*/
    while (1)
    {
        mcycle_start = readmcycle();

        if (1u == debug_hart0)
        {
            debug_hart0 = 0U;
            sprintf(info_string,"Hart %ld, %ld delta_mcycle %ld mtime %ld tick\r\n",
            hartid, delta_mcycle, readmtime(), get_SysTick());
            mss_take_mutex((uint64_t)&uart_lock);
            MSS_FU540_UART_polled_tx(&g_mss_FU540_uart0, info_string,strlen(info_string));
            mss_release_mutex((uint64_t)&uart_lock);
        }

        if (1u == debug_tick)
        {
            current_sec = get_secs_since_start();
            if(current_sec >= last_sec + 10U)
            {
                sprintf(info_string,"Seconds %ld\r\n",current_sec);
                MSS_FU540_UART_polled_tx(&g_mss_FU540_uart0, info_string, sizeof(info_string));
                last_sec = current_sec;
            }
        }

        mss_take_mutex((uint64_t)&uart_lock);
        rx_size = MSS_FU540_UART_get_rx(&g_mss_FU540_uart0, rx_buff,sizeof(rx_buff));
        mss_release_mutex((uint64_t)&uart_lock);

        if (rx_size > 0)
        {
            switch(rx_buff[0])
            {
                case '0':
                    mss_take_mutex((uint64_t)&uart_lock);
                    MSS_FU540_UART_polled_tx(&g_mss_FU540_uart0, g_message, sizeof(g_message));
                    mss_release_mutex((uint64_t)&uart_lock);
                    break;
                case '1':
                    raise_soft_interrupt(1u);
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
                    debug_hart0 = 1U;
                    break;
                case '6':
                    if (debug_tick == 1U)
                    {
                        debug_tick = 0U;
                    }
                    else
                    {
                        debug_tick = 1U;
                    }
                    break;

                default:
                    /* echo input */
                     mss_take_mutex((uint64_t)&uart_lock);
                     MSS_FU540_UART_polled_tx(&g_mss_FU540_uart0, rx_buff, 1);
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


uint64_t systick_h0 = 0ULL;
/* example tick timer */
void SysTick_Handler_h0_IRQHandler(void)
{
    systick_h0++;
}

/* get systick */
uint64_t get_SysTick(void)
{
    return systick_h0;
}

/* get systick */
uint64_t get_secs_since_start(void)
{
    return systick_h0 / (1000UL/HART0_TICK_RATE_MS);
}

