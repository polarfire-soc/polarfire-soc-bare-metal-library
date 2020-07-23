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
 * Platform definitions
 * Version based on requirements of MPFS MSS
 *
 */
 /*========================================================================*//**
  @mainpage Sample file detailing how mss_sw_config.h should be constructed for
    the MPFS MSS

    @section intro_sec Introduction
    The mss_sw_config.h is to be located in the project
    ./src/platform/config/software/mpfs_hal directory.
    This file must be hand crafted when using the MPFS MSS.


    @section

*//*==========================================================================*/

#ifndef USER_CONFIG_MSS_USER_CONFIG_H_
#define USER_CONFIG_MSS_USER_CONFIG_H_

#define MPFS_HAL_HW_CONFIG

/*------------------------------------------------------------------------------
 * MPFS_HAL_FIRST_HART and MPFS_HAL_LAST_HART defines used to specify which
 * harts to actually start.
 * Set MPFS_HAL_FIRST_HART to a value other than 0 if you do not want your code
 * to start and execute code on the E51 hart.
 * Set MPFS_HAL_LAST_HART to a value smaller than 4 if you do not wish to use
 * all U54 harts.
 * Harts that are not started will remain in an infinite WFI loop unless used
 * through some other method
 */
#ifndef MPFS_HAL_FIRST_HART
#define MPFS_HAL_FIRST_HART  0
#endif

#ifndef MPFS_HAL_LAST_HART
#define MPFS_HAL_LAST_HART   4
#endif

/*------------------------------------------------------------------------------
 * Markers used to indicate startup status of hart
 */
#define HLS_DATA_IN_WFI                     0x12345678U
#define HLS_DATA_PASSED_WFI                 0x87654321U

/*------------------------------------------------------------------------------
 * Define the size of the HLS used
 * In our HAL, we are using Hart Local storage for debug data storage only
 * as well as flags for wfi instruction management.
 * The TLS will take memory from top of the stack if allocated
 *
 */
#define HLS_DEBUG_AREA_SIZE     64

/* define the required tick rate in Milliseconds */
/* if this program is running on one hart only, only that particulars hart value
 * will be used */
#define HART0_TICK_RATE_MS  5UL
#define HART1_TICK_RATE_MS  5UL
#define HART2_TICK_RATE_MS  5UL
#define HART3_TICK_RATE_MS  5UL
#define HART4_TICK_RATE_MS  5UL

#define H2F_BASE_ADDRESS 0x20126000     /* or 0x28126000 */

/*
 * define how you want the Bus Error Unit configured
 */
#define BEU_ENABLE                  0x0ULL
#define BEU_PLIC_INT                0x0ULL
#define BEU_LOCAL_INT               0x0ULL

/*
 * If not using item, comment out line below
 */
#define SGMII_SUPPORT
// #define DDR_SUPPORT
#define MSSIO_SUPPORT
#define MSSIO_TOGGLE_TEST
#define SIMULATION_TEST_FEEDBACK

/*
 * You can over write any on the settings coming from Libero here
 *
 * e.g. Define how you want SEG registers configured, if you want to change from
 * the default settings
 */

#define LIBERO_SETTING_SEG0_0     (-(0x0080000000LL >> 24u))
#define LIBERO_SETTING_SEG0_1     (-(0x1000000000LL >> 24u))
#define LIBERO_SETTING_SEG1_2     (-(0x00C0000000LL >> 24u))
#define LIBERO_SETTING_SEG1_3     (-(0x1400000000LL >> 24u))
#define LIBERO_SETTING_SEG1_4     (-(0x00D0000000LL >> 24u))
#define LIBERO_SETTING_SEG1_5     (-(0x1800000000LL >> 24u))

#if 0
/*
 * Turn off DDR, bits 0:3 == 0x7
 */
//#define LIBERO_SETTING_DDRPHY_MODE    0x04000127UL

/*
 *
 */

/* Fabric GEM 0 MDIO
 * #define LIBERO_SETTING_IOMUX0_CR    0x00001000UL */
/* Fabric GEM 0 MSSIO
 * #define LIBERO_SETTING_IOMUX0_CR    0x00000000UL */
#if defined(GEM0_MDIO_MSS) || defined(GEM0_MDIO_MSS)
#if defined(GEM0_MDIO_MSS) && defined(GEM0_MDIO_MSS)

/* Both are MSSIO - need to add GEM1...*/
#define LIBERO_SETTING_IOMUX0_CR    0x00002000UL
#define LIBERO_SETTING_IOMUX5_CR    0xF88F3333UL

/*
 *    3322 2222 2222 1111 1111 1100 0000 0000
 *    1098 7654 3210 9876 5432 1098 7654 3210
 *    ----+----+----+----+----+----+----+----
 *    1111 0000 0000 0000 0101 0000 1100 1100
 *
 *    0000 0000 0000 0000 0010 1100 0011 0000
 *
 */


#define LIBERO_SETTING_CLK_CNTL          0xF00050CCUL
    /* REG_REFCLK_EN_TERM_P              [0:2]   RW value= 0x0 */
    /* REG_REFCLK_EN_RXMODE_P            [2:2]   RW value= 0x3 */
    /* REG_REFCLK_EN_TERM_N              [4:2]   RW value= 0x0 */
    /* REG_REFCLK_EN_RXMODE_N            [6:2]   RW value= 0x3 */
    /* REG_REFCLK_CLKBUF_EN_PULLUP       [8:1]   RW value= 0x0 */
    /* REG_CLKMUX_FCLK_SEL               [9:3]   RW value= 0x0 */
    /* REG_CLKMUX_PLL0_RFCLK0_SEL        [12:2]  RW value= 0x1 */
    /* REG_CLKMUX_PLL0_RFCLK1_SEL        [14:2]  RW value= 0x1 */
    /* REG_CLKMUX_SPARE0                 [16:16] RW value= 0xf000 */


#define LIBERO_SETTING_SGMII_CLK_XCVR    0x000002C30L
    /* EN_UDRIVE_P                       [0:1]   RW value= 0x1 */
    /* EN_INS_HYST_P                     [1:1]   RW value= 0x0 */
    /* EN_TERM_P                         [2:2]   RW value= 0x0 */
    /* EN_RXMODE_P                       [4:2]   RW value= 0x1 */
    /* EN_UDRIVE_N                       [6:1]   RW value= 0x0 */
    /* EN_INS_HYST_N                     [7:1]   RW value= 0x0 */
    /* EN_TERM_N                         [8:2]   RW value= 0x0 */
    /* EN_RXMODE_N                       [10:2]  RW value= 0x0 */
    /* CLKBUF_EN_PULLUP                  [12:1]  RW value= 0x0 */
    /* EN_RDIFF                          [13:1]  RW value= 0x1 */
    /* RESERVED                          [14:18] RW value= 0x0 */

//#define LIBERO_SETTING_SGMII_PLL_CTRL    0x0100003EUL


#if 0
#define LIBERO_SETTING_SGMII_MODE   0x08C0E6CFUL
#define LIBERO_SETTING_DYN_CNTL     0x00000000UL
#define LIBERO_SETTING_CH1_CNTL     0x37F07770UL

#define LIBERO_SETTING_SGMII_PLL_CTRL    0x0100013FUL
#define LIBERO_SETTING_SGMII_PLL_REF_FB    0x00000108UL
#define LIBERO_SETTING_SGMII_PLL_DIV_0_1    0x01000080UL
#define LIBERO_SETTING_SGMII_PLL_DIV_2_3    0x01000080UL
#endif

#elif defined(GEM0_MDIO_MSS)
/* GEM1 is fabric */
#define LIBERO_SETTING_IOMUX0_CR    0x00002000UL
#else
/* GEM 0 is fabric */
#define LIBERO_SETTING_IOMUX0_CR    0x00001000UL
#define LIBERO_SETTING_IOMUX5_CR    0xF9FF3333UL
#endif
#else
/* Both are fabric  - need to add GEM1...*/
#define LIBERO_SETTING_IOMUX0_CR    0x00003000UL
#define LIBERO_SETTING_IOMUX5_CR    0xF9FF3333UL
#endif



// for GPIO "B"

#if 0
#define LIBERO_SETTING_IOMUX0_CR   0xFFFFFFFFUL /* Selects whether the peripheral is connected to
                                 the Fabric or IOMUX structure. */
#define     LIBERO_SETTING_IOMUX1_CR   0x0550000BUL /* BNK4 SDV PAD 0 to 7, each IO has 4 bits   */
#define     LIBERO_SETTING_IOMUX2_CR   0x0UL /* BNK4 SDV PAD 8 to 13     */
#define     LIBERO_SETTING_IOMUX3_CR   0xBUL /* BNK2 SDV PAD 14 to 21    */
#define     LIBERO_SETTING_IOMUX4_CR   0x0UL /* BNK2 SDV PAD 22 to 29    */
#define     LIBERO_SETTING_IOMUX5_CR   0x0UL /* BNK2 PAD 30 to 37        */
#define     LIBERO_SETTING_IOMUX6_CR   0x0UL /* Sets whether the MMC/SD Voltage select lines
                                 are inverted on entry to the IOMUX structure */



#define LIBERO_SETTING_IOMUX0_CR   0xffffffffUL /* Selects whether the peripheral is connected to
                                 the Fabric or IOMUX structure. */
#define     LIBERO_SETTING_IOMUX1_CR   0xffffffffUL /* BNK4 SDV PAD 0 to 7, each IO has 4 bits   */
#define     LIBERO_SETTING_IOMUX2_CR   0xffffffffUL /* BNK4 SDV PAD 8 to 13     */
#define     LIBERO_SETTING_IOMUX3_CR   0xffffffffUL /* BNK2 SDV PAD 14 to 21    */
#define     LIBERO_SETTING_IOMUX4_CR   0xffffffffUL /* BNK2 SDV PAD 22 to 29    */
#define     LIBERO_SETTING_IOMUX5_CR   0xffffffffUL /* BNK2 PAD 30 to 37        */
#define     LIBERO_SETTING_IOMUX6_CR   0xffffffffUL /* Sets whether the MMC/SD Voltage select lines
                                 are inverted on entry to the IOMUX structure */


/*
 * Bank 4 and 2 settings, the 38 MSSIO.
 */

#define    LIBERO_SETTING_MSSIO_BANK4_IO_CFG_0_1_CR   0x0UL
#define    LIBERO_SETTING_MSSIO_BANK4_IO_CFG_2_3_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK4_IO_CFG_4_5_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK4_IO_CFG_6_7_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK4_IO_CFG_8_9_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK4_IO_CFG_10_11_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK4_IO_CFG_12_13_CR   0x0UL
    /* LIBERO_SETTING_mssio_bank2_cfg_cr
         bank_pcode                        [0:6]   RW value= 0x0
         bank_ncode                        [6:6]   RW value= 0x0
         vs                                [12:4]  RW value= 0x0 */
#define     LIBERO_SETTING_MSSIO_BANK2_CFG_CR   0x0UL
    /* LIBERO_SETTING_mssio_bank4_io_cfg_0_cr
        x_vddi Ratio Rx<0-2> == 001
        drv<3-6> == 1111
        7:clamp   == 0
        enhyst   == 0
        lockdn_en == 1
        10:wpd  == 0
        atp_en`== 0
        lpmd_ibuf  == 0
        lpmd_obuf == 0
        persist == 0
        */
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_0_1_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_2_3_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_4_5_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_6_7_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_8_9_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_10_11_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_12_13_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_14_15_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_16_17_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_18_19_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_20_21_CR   0x0UL
#define     LIBERO_SETTING_MSSIO_BANK2_IO_CFG_22_23_CR   0x0UL
#endif

#endif
#endif /* USER_CONFIG_MSS_USER_CONFIG_H_ */
