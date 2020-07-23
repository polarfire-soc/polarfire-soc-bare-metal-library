/***********************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * code running on U54 third hart
 *
 */

#include "mpfs_hal/mss_util.h"
#include <stdbool.h>
#include "mpfs_hal/mss_plic.h"
#include "drivers/mss_mac/mss_ethernet_registers.h"
#include "drivers/mss_mac/mss_ethernet_mac_user_config.h"
#include "drivers/mss_mac/mss_ethernet_mac_regs.h"
#include "drivers/mss_mac/mss_ethernet_mac.h"

/* 
 * Enable this and add your own application specific code if you wish to
 * override the default HAL code.
 */
#if 0
void u54_3(void)
{
    volatile int ix;
    uint32_t hartid = read_csr(mhartid);

    /* add code here */
    while(1)
        ix++;
}
#endif

