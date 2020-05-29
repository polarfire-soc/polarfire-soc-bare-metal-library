 /*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * Register bit offsets and masks definitions for PolarFire SoC MSS Timer
 *
 * SVN $Revision$
 * SVN $Date$
 */

#ifndef __PSE_TIMER_REG_H_
#define __PSE_TIMER_REG_H_

#ifdef __cplusplus
extern "C" {
#endif
/*----------------------------------------------------------------------------*/
/*--------------------------PSE MSS Timer register map------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
	/*Timer 1 register declaration*/
    const volatile  uint32_t TIM1_VAL;
    volatile uint32_t TIM1_LOADVAL;
    volatile uint32_t TIM1_BGLOADVAL;
    volatile uint32_t TIM1_CTRL;
    volatile uint32_t TIM1_RIS;
    const volatile  uint32_t TIM1_MIS;

    /*Timer 2 register declaration*/
    const volatile  uint32_t TIM2_VAL;
    volatile uint32_t TIM2_LOADVAL;
    volatile uint32_t TIM2_BGLOADVAL;
    volatile uint32_t TIM2_CTRL;
    volatile uint32_t TIM2_RIS;
    const volatile  uint32_t TIM2_MIS;

    /*Timer 64 register declaration*/
    const volatile  uint32_t TIM64_VAL_U;
    const volatile  uint32_t TIM64_VAL_L;
    volatile uint32_t TIM64_LOADVAL_U;
    volatile uint32_t TIM64_LOADVAL_L;
    volatile uint32_t TIM64_BGLOADVAL_U;
    volatile uint32_t TIM64_BGLOADVAL_L;
    volatile uint32_t TIM64_CTRL;
    volatile uint32_t TIM64_RIS;
    const volatile  uint32_t TIM64_MIS;
    volatile uint32_t TIM64_MODE;
} TIMER_TypeDef;

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
#define TIMER_BASE         0x20125000

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define TIMER                          ((volatile TIMER_TypeDef *) TIMER_BASE)

#define SYSREG_TIMER_SOFTRESET_MASK    ((uint32_t)0x01u << 6u)

#ifdef __cplusplus
}
#endif

#endif  /* __PSE_TIMER_REG_H_ */
