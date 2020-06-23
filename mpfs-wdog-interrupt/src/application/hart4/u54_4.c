/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software example
 *
 * Code running on U54 fourth hart
 */

#include "mpfs_hal/mss_clint.h"
#include "mpfs_hal/mss_hal.h"

volatile uint32_t count_sw_ints_h4 = 0U;

/* Main function for the HART4(U54_4 processor).
 * Application code running on HART4 is placed here
 *
 * The HART4 goes into WFI. HART0 brings it out of WFI when it raises the first
 * Software interrupt to this HART
 */
void u54_4(void)
{
    uint8_t info_string[100];
    uint64_t hartid = read_csr(mhartid);
    volatile uint32_t icount = 0U;

    /*Clear pending software interrupt in case there was any.
     Enable only the software interrupt so that the E51 core can bring this core
     out of WFI by raising a software interrupt.*/
    clear_soft_interrupt();
    set_csr(mie, MIP_MSIP);

    /*put this hart into WFI.*/
    do
    {
        __asm("wfi");
    }while(0 == (read_csr(mip) & MIP_MSIP));

    /*The hart is out of WFI, clear the SW interrupt. Hear onwards Application
     *can enable and use any interrupts as required*/
    clear_soft_interrupt();

    __enable_irq();

    while (1U)
    {
        icount++;
        if (0x100000U == icount)
        {
            icount = 0U;
        }
    }
    /* never return */
}

/* HART4 Software interrupt handler */
void Software_h4_IRQHandler(void)
{
    uint64_t hart_id = read_csr(mhartid);
    count_sw_ints_h4++;
}
