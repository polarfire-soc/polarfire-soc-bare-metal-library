/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * MPFS HAL Embedded Software
 *
 */

/*******************************************************************************
 * @file mss_hal.h
 * @author Microchip FPGA Embedded Systems Solutions
 * @brief MPFS HAL include file. This is the file intended for application to
 * include so that all the other MPFS files are then accessible to it.
 *
 *
 */

#ifndef MSS_HAL_H
#define MSS_HAL_H

#include "atomic.h"
#include "bits.h"
#include "encoding.h"
#include "mss_clint.h"
#include "mss_coreplex.h"
#include "mss_h2f.h"
#include "mss_hart_ints.h"
#include "mss_ints.h"
#include "mss_mpu.h"
#include "mss_peripheral_base_add.h"
#include "mss_plic.h"
#include "mss_prci.h"
#include "mss_seg.h"
#include "mss_sysreg.h"
#include "mss_util.h"
#include "mtrap.h"
#include "system_startup.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t SysTick_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* MSS_HAL_H */
