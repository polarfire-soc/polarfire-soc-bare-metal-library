/***********************************************************************************
 * (c) Copyright 2018 Microsemi-PRO Embedded Systems Solutions. All rights reserved.
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
#include "../mpfs_hal/mss_ints.h"
#include "../common/common.h"
#include "../mpfs_config/hw_config/hw_platform.h"
#include "mss_timer.h"
#include "mss_uart.h"

uint64_t uart_lock;

void e51(void)
{
    uint32_t timer1_load_value;
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

    /*Configure Timer1 for 1sec periodic interrupt*/
    timer1_load_value = 83000000;
    MSS_TIM1_init(MSS_TIMER_PERIODIC_MODE);
    MSS_TIM1_load_immediate(timer1_load_value);
    MSS_TIM1_start();
    MSS_TIM1_enable_irq();

	for(;;)
	{
		;
	}
}

uint8_t timer1_plic_IRQHandler()
{

    /*Print informative message on UART terminal for each interrupt occurrence*/
    MSS_UART_polled_tx_string(&g_mss_uart0_lo, "PSE_Timer Periodic interrupt example\r\n");

    /* Clear TIM1 interrupt */
    MSS_TIM1_clear_irq();

    return EXT_IRQ_KEEP_ENABLED;
}
