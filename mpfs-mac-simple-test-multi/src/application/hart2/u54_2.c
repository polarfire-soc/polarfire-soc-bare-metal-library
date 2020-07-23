/***********************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * code running on U54 second hart
 *
 */

#include "mpfs_hal/mss_util.h"

volatile uint64_t dummy_h2 = 0;

void u54_2(void)
{
    volatile int ix;
    volatile uint64_t * dummy_addr = (volatile uint64_t *)DDR_BASE;
    uint32_t hartid = read_csr(mhartid);

    /* add code here */
    while(1)
        ix++;
}



