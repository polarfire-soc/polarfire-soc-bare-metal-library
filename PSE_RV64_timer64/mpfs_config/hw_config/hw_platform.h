/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software example
 *
 */
/*******************************************************************************
 *
 * Platform definitions
 * Version based on requirements of MPFS MSS
 *
 */
 /*=========================================================================*//**
  @mainpage Sample file detailing how hw_platform.h should be constructed for
    the MPFS MSS

    @section intro_sec Introduction
    The  hw_platform.h is to be located in the project ./config/hw_config/ directory.
    Currently this file must be hand crafted when using the MPFS MSS.

    You can use this file as sample.
    hw_platform.h must be copied to
    the ./config/hw_config/ folder of your project. Then customize it per your HW design.

    @section driver_configuration Project configuration Instructions
    1. Change MPFS MSS CLOCK DEFINITIONS to match design used.

*//*=========================================================================*/

#ifndef HW_PLATFORM_H
#define HW_PLATFORM_H

/***************************************************************************//**
 * MPFS MSS CLOCK DEFINITIONS
 */
#ifndef SIFIVE_HIFIVE_UNLEASHED
#define MSS_COREPLEX_CPU_CLK            83000000UL
#define MSS_SYSTEM_CLK                  25000000UL   /* PLIC,CLINT,DEBUG,PORTS  */
#define MSS_RTC_TOGGLE_CLK              10000000UL   /* RTC clk input, must run at less than 1/2 rate of MSS_SYSTEM_CLK  */
#define MSS_AXI_SWITCH_CLK              20000000UL
#define MSS_AHB_APB_CLK                 10000000UL
#else
#define MSS_COREPLEX_CPU_CLK            50000000UL
#define MSS_RTC_TOGGLE_CLK              10000000UL   /* RTC clk input, must run at less than 1/2 rate of MSS_SYSTEM_CLK  */
#define MSS_AXI_SWITCH_CLK              25000000UL
#endif


/*******************************************************************************
 * End of user edit section
 */
#endif /* HW_PLATFORM_H */


