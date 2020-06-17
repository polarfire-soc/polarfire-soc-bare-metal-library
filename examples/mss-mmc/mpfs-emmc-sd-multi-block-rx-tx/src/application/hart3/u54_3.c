/***********************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * code running on U54 third hart
 *
 */

#include "mpfs_hal/mss_util.h"

void u54_3(void)
{
    volatile int ix = 0u;
    uint32_t hartid = read_csr(mhartid);

    /* add code here */
    while(1)
        ix++;
}

