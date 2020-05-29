 /*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
 */

/*******************************************************************************
 *
 * @file mss_clint.h
 * @author Microsemi-PRO Embedded Systems Solutions
 * @brief MPFS PLIC and PRCI access data structures and functions.
 *
 * PRCI: Power, Reset, Clock, Interrupt
 *
 * SVN $Revision: 11431 $
 * SVN $Date: 2019-06-12 21:59:15 +0530 (Wed, 12 Jun 2019) $
 */

#ifndef MSS_PRCI_H
#define MSS_PRCI_H

#include <stdint.h>

#include "encoding.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "encoding.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================================================
 * PRCI: Power, Reset, Clock, Interrupt
 */
//#define PRCI_BASE   0x44000000UL
#define PRCI_BASE   0x10000000UL	/* FU540-C000 on unleashed board- 0x10000000UL	*/


#ifdef __cplusplus
}
#endif


#endif /* MSS_PRCI_H_ */
