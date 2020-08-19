/*******************************************************************************
 * Copyright 2019-2020 Microchip FPGA Embedded Systems Solutions.
 * 
 * SPDX-License-Identifier: MIT
 * 
 * @file hw_ddr_io_bank.h
 * @author Microchip-FPGA Embedded Systems Solutions
 * 
 * Generated using Libero version: 12.900.0.16-PFSOC_MSS:2.0.108
 * Libero design name: ICICLE_MSS
 * MPFS part number used in design: MPFS250T_ES
 * Date generated by Libero: 06-26-2020_16:47:44
 * Format version of XML description: 0.3.8
 * PolarFire SoC Configuration Generator version: 0.4.1
 * 
 * Note 1: This file should not be edited. If you need to modify a parameter,
 * without going through the Libero flow or editing the associated xml file,
 * the following method is recommended:
 *   1. edit the file platform//config//software//mpfs_hal//mss_sw_config.h
 *   2. define the value you want to override there. (Note: There is a 
 *      commented example in mss_sw_config.h)
 * Note 2: The definition in mss_sw_config.h takes precedence, as 
 * mss_sw_config.h is included prior to the hw_ddr_io_bank.h in the hal 
 * (see platform//mpfs_hal//mss_hal.h)
 *
 */ 

#ifndef HW_DDR_IO_BANK_H_
#define HW_DDR_IO_BANK_H_


#ifdef __cplusplus
extern  "C" {
#endif

#if !defined (LIBERO_SETTING_DPC_BITS)
/*DPC Bits Register */ 
#define LIBERO_SETTING_DPC_BITS    0x0004C422UL
    /* DPC_VS                            [0:4]   RW value= 0x2 */ 
    /* DPC_VRGEN_H                       [4:6]   RW value= 0x2 */ 
    /* DPC_VRGEN_EN_H                    [10:1]  RW value= 0x1 */ 
    /* DPC_MOVE_EN_H                     [11:1]  RW value= 0x0 */ 
    /* DPC_VRGEN_V                       [12:6]  RW value= 0xC */ 
    /* DPC_VRGEN_EN_V                    [18:1]  RW value= 0x1 */ 
    /* DPC_MOVE_EN_V                     [19:1]  RW value= 0x0 */ 
    /* RESERVE01                         [20:12] RSVD */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_DQ)
/*Need to be set by software in all modes but OFF mode. Decoding options should 
follow ODT_STR table, depends on drive STR setting */ 
#define LIBERO_SETTING_RPC_ODT_DQ    0x00000006UL
    /* RPC_ODT_DQ                        [0:32]  RW value= 0x6 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_DQS)
/*Need to be set by software in all modes but OFF mode. Decoding options should 
follow ODT_STR table, depends on drive STR setting */ 
#define LIBERO_SETTING_RPC_ODT_DQS    0x00000006UL
    /* RPC_ODT_DQS                       [0:32]  RW value= 0x6 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_ADDCMD)
/*Need to be set by software in all modes but OFF mode. Decoding options should 
follow ODT_STR table, depends on drive STR setting */ 
#define LIBERO_SETTING_RPC_ODT_ADDCMD    0x00000002UL
    /* RPC_ODT_ADDCMD                    [0:32]  RW value= 0x2 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_CLK)
/*Need to be set by software in all modes but OFF mode. Decoding options should 
follow ODT_STR table, depends on drive STR setting */ 
#define LIBERO_SETTING_RPC_ODT_CLK    0x00000002UL
    /* RPC_ODT_CLK                       [0:32]  RW value= 0x2 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_STATIC_DQ)
/*0x2000 73A8 (rpc10_ODT) */ 
#define LIBERO_SETTING_RPC_ODT_STATIC_DQ    0x00000005UL
    /* RPC_ODT_STATIC_DQ                 [0:32]  RW value= 0x5 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_STATIC_DQS)
/*0x2000 73AC (rpc11_ODT) */ 
#define LIBERO_SETTING_RPC_ODT_STATIC_DQS    0x00000005UL
    /* RPC_ODT_STATIC_DQS                [0:32]  RW value= 0x5 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_STATIC_ADDCMD)
/*0x2000 739C (rpc7_ODT) */ 
#define LIBERO_SETTING_RPC_ODT_STATIC_ADDCMD    0x00000007UL
    /* RPC_ODT_STATIC_ADDCMD             [0:32]  RW value= 0x7 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_STATIC_CLKP)
/*0x2000 73A4 (rpc9_ODT) */ 
#define LIBERO_SETTING_RPC_ODT_STATIC_CLKP    0x00000007UL
    /* RPC_ODT_STATIC_CLKP               [0:32]  RW value= 0x7 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_ODT_STATIC_CLKN)
/*0x2000 73A0 (rpc8_ODT) */ 
#define LIBERO_SETTING_RPC_ODT_STATIC_CLKN    0x00000007UL
    /* RPC_ODT_STATIC_CLKN               [0:32]  RW value= 0x7 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_IBUFMD_ADDCMD)
/*0x2000 757C (rpc95) */ 
#define LIBERO_SETTING_RPC_IBUFMD_ADDCMD    0x00000003UL
    /* RPC_IBUFMD_ADDCMD                 [0:32]  RW value= 0x3 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_IBUFMD_CLK)
/*0x2000 7580 (rpc96) */ 
#define LIBERO_SETTING_RPC_IBUFMD_CLK    0x00000004UL
    /* RPC_IBUFMD_CLK                    [0:32]  RW value= 0x4 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_IBUFMD_DQ)
/*0x2000 7584 (rpc97) */ 
#define LIBERO_SETTING_RPC_IBUFMD_DQ    0x00000003UL
    /* RPC_IBUFMD_DQ                     [0:32]  RW value= 0x3 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_IBUFMD_DQS)
/*0x2000 7588 (rpc98) */ 
#define LIBERO_SETTING_RPC_IBUFMD_DQS    0x00000004UL
    /* RPC_IBUFMD_DQS                    [0:32]  RW value= 0x4 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_SPARE0_DQ)
/*bits 15:14 connect to pc_ibufmx DQ/DQS/DM bits 13:12 connect to pc_ibufmx 
CA/CK Check at ioa pc bit */ 
#define LIBERO_SETTING_RPC_SPARE0_DQ    0x00008000UL
    /* RPC_SPARE0_DQ                     [0:32]  RW value= 0x8000 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_EN_ADDCMD1_OVRT10)
/*0x2000 7428 OVRT10 - physical configurations of LPDDR4, given the twindie 
architecture */ 
#define LIBERO_SETTING_RPC_EN_ADDCMD1_OVRT10    0x00000000UL
    /* RPC_EN_ADDCMD1_OVRT10             [0:32]  RW value= 0x0 */ 
#endif
#if !defined (LIBERO_SETTING_RPC_EN_ADDCMD2_OVRT11)
/*0x2000 742C OVRT11 - physical configurations of LPDDR4, given the twindie 
architecture */ 
#define LIBERO_SETTING_RPC_EN_ADDCMD2_OVRT11    0x00000120UL
    /* RPC_EN_ADDCMD2_OVRT11             [0:32]  RW value= 0x120 */ 
#endif

#ifdef __cplusplus
}
#endif


#endif /* #ifdef HW_DDR_IO_BANK_H_ */

