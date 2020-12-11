/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
 */

/***************************************************************************
 * @file mss_l2_cache.h
 * @author Microchip-FPGA Embedded Systems Solutions
 * @brief MACROs defines and prototypes associated with L2 Cache
 *
 */
#ifndef MSS_L2_CACHE_H
#define MSS_L2_CACHE_H

#include <stdint.h>
#include "encoding.h"

#ifdef __cplusplus
extern "C" {
#endif


#if !defined (LIBERO_SETTING_WAY_MASK_M0)
/*Way mask register master 0 (hart0) */
#define LIBERO_SETTING_WAY_MASK_M0    0x00000000UL
#endif
#if !defined (LIBERO_SETTING_WAY_MASK_M1)
/*Way mask register master 1 (hart1) */
#define LIBERO_SETTING_WAY_MASK_M1    0x00000000UL
#endif
#if !defined (LIBERO_SETTING_WAY_MASK_M2)
/*Way mask register master 2 (hart2) */
#define LIBERO_SETTING_WAY_MASK_M2    0x00000000UL
#endif
#if !defined (LIBERO_SETTING_WAY_MASK_M3)
/*Way mask register master 3 (hart3) */
#define LIBERO_SETTING_WAY_MASK_M3    0x00000000UL
#endif
#if !defined (LIBERO_SETTING_WAY_MASK_M4)
/*Way mask register master 4 (hart4) */
#define LIBERO_SETTING_WAY_MASK_M4    0x00000000UL
#endif

void config_l2_cache(void);

#ifdef __cplusplus
}
#endif

#endif  /* MSS_L2_CACHE_H */
