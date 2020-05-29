/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
 */
/***************************************************************************//**
 * 
 * Legacy interrupt control functions for the Microsemi driver library hardware
 * abstraction layer.
 *
 * SVN $Revision: 11483 $
 * SVN $Date: 2019-06-19 17:14:00 +0530 (Wed, 19 Jun 2019) $
 */
#include "hal.h"
#include <stdio.h>
#include "mpfs_hal/atomic.h"
#include "mpfs_hal/encoding.h"
#include "mpfs_hal/mss_util.h"
#include "mpfs_hal/mcall.h"
#include "mpfs_hal/mtrap.h"

/*------------------------------------------------------------------------------
 * 
 */
void HAL_enable_interrupts(void) {
    __enable_irq();
}

/*------------------------------------------------------------------------------
 * 
 */
psr_t HAL_disable_interrupts(void) {
    psr_t psr;
    psr = read_csr(mstatus);
    __disable_irq();
    return(psr);
}

/*------------------------------------------------------------------------------
 * 
 */
void HAL_restore_interrupts(psr_t saved_psr) {
    write_csr(mstatus, saved_psr);
}

