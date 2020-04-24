/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
 */
/*******************************************************************************
 * @file mss_mpu.c
 * @author Microchip-FPGA Embedded Systems Solutions
 * @brief PolarFire SoC MSS MPU driver for configuring access regions for the
 * external masters.
 *
 * SVN $Revision: 12296 $
 * SVN $Date: 2019-09-30 14:30:02 +0100 (Mon, 30 Sep 2019) $
 */
/*=========================================================================*//**
  
 *//*=========================================================================*/
#include <stdio.h>
#include <string.h>
#include "mss_hal.h"



/**
 * \brief L2 waymask configuration settings from Libero
 *
 */
const uint64_t    way_mask_values[] = {
    LIBERO_SETTING_WAY_MASK_M0,
    LIBERO_SETTING_WAY_MASK_M1,
    LIBERO_SETTING_WAY_MASK_M2,
    LIBERO_SETTING_WAY_MASK_M3,
    LIBERO_SETTING_WAY_MASK_M4
};



/***************************************************************************//**
 * \brief L2 waymask configuration from Libero
 *
 * @return
 */
uint8_t L2_Cache_config(void)
{
    uint8_t * way_mask_en;
    uint64_t * way_mask;
    way_mask_en = (uint8_t *) (U5CP_CACHE_CTRL_PORT_BASE+\
            CACHE_CTRL_WAYENB_OFFSET);
    way_mask = (uint64_t *) (U5CP_CACHE_CTRL_PORT_BASE+\
            CACHE_CTRL_MASTER0_WAY_OFFSET);

    /*
     * Set the ways you wish to enable
     */
    *way_mask_en = LIBERO_SETTING_WAY_ENABLE;

    /*
     * set the mask registers for each master
     */
    memcpy((void *)(way_mask), &(way_mask_values)\
               , sizeof(way_mask_values));
    return(0);
}


