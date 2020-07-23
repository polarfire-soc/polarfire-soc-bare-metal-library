/***********************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * code running on U54 second hart
 *
 */

#include "mpfs_hal/mss_util.h"
#include <stdbool.h>
#include "mpfs_hal/mss_plic.h"
#include "drivers/mss_mac/mss_ethernet_registers.h"
#include "drivers/mss_mac/mss_ethernet_mac_user_config.h"
#include "drivers/mss_mac/mss_ethernet_mac_regs.h"
#include "drivers/mss_mac/mss_ethernet_mac.h"

volatile uint64_t dummy_h2 = 0;
#if !(MSS_MAC_HW_PLATFORM == MSS_MAC_DESIGN_EMUL_GMII_LOCAL)

void u54_2(void)
{
    volatile int ix;
    volatile uint64_t * dummy_addr = (volatile uint64_t *)DDR_BASE;
    uint32_t hartid = read_csr(mhartid);

    /* add code here */
    while(1)
        ix++;
}

#endif

