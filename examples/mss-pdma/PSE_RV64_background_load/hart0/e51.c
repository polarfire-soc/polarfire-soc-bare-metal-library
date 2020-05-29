/***********************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * code running on e51
 *
 * SVN $Revision$
 * SVN $Date$
 */

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../mpfs_hal/mss_hal.h"
#include "../mpfs_hal/mss_plic.h"
#include "../common/common.h"

#include "../drivers/mss_timer/mss_timer.h"
#include "../drivers/mss_uart/mss_uart.h"

volatile uint32_t count_sw_ints_h0 = 0U;
volatile uint8_t g_interrupt_occoured;
uint64_t uart_lock;

/* Sequence of delays */
#define SEQUENCE_LENGTH                         5

static const uint32_t g_sequence_delays[SEQUENCE_LENGTH] =
{
        25000000,
        83000000,
        166000000,
        25000000,
        166000000
};

void e51(void)
{
    uint32_t hartid = read_csr(mhartid);
    int8_t info_string[100];
    SYSREG->SUBBLK_CLOCK_CR = 0xffffffff;

    /*MMUART0, TIMER out of reset*/
    SYSREG->SOFT_RESET_CR &= ~( (1u << 0u) | (1u << 4u) | (1u << 5u) |
                                (1u << 19u) | (1u << 23u) | (1u << 28u)) ;

    SYSREG->IOMUX0_CR = 0xfffffe7f;  // connect MMUART0 to GPIO, QSPI to pads
    SYSREG->IOMUX1_CR = 0x05500000U;  // pad5,6 = mux 5 (mmuart 0)

    // IOMUX configurations to allow QSPI pins to the pads
    SYSREG->IOMUX2_CR = 0U;
    SYSREG->IOMUX3_CR = 0U;
    SYSREG->IOMUX4_CR = 0U;
    SYSREG->IOMUX5_CR = 0U;

    PLIC_init();
    PLIC_SetPriority(MMUART0_PLIC_77, 2);

    __enable_irq();
    MSS_UART_init( &g_mss_uart0_lo,
            MSS_UART_115200_BAUD,
            MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT);

    sprintf(info_string,"Hart %ld\n\r", hartid);
    mss_take_mutex((uint64_t)&uart_lock);
    MSS_UART_polled_tx(&g_mss_uart0_lo, info_string,strlen(info_string));
    mss_release_mutex((uint64_t)&uart_lock);

	/*Configure Timer1*/
	MSS_TIM1_init(MSS_TIMER_PERIODIC_MODE);
	MSS_TIM1_load_immediate(g_sequence_delays[0]);
	MSS_TIM1_start();
	MSS_TIM1_enable_irq();

	for(;;)
	{
	    ;
	}
}

uint8_t timer1_plic_IRQHandler()
{
    static uint32_t delay_idx = 0;

    /* Move to next delay in sequence. */
    ++delay_idx;

    if(delay_idx >= SEQUENCE_LENGTH)
    {
        delay_idx = 0;
    }

    MSS_TIM1_load_background(g_sequence_delays[delay_idx]);

    MSS_UART_polled_tx_string(&g_mss_uart0_lo, "Timer interrupt\r\n");

    /* Clear TIM1 interrupt */
    MSS_TIM1_clear_irq();

    return EXT_IRQ_KEEP_ENABLED;
}
