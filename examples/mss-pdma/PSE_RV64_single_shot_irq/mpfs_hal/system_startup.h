/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
*/

/***********************************************************************************
 *
 * SVN $Revision: 11438 $
 * SVN $Date: 2019-06-12 20:45:35 +0100 (Wed, 12 Jun 2019) $
 */

#ifndef SYSTEM_STARTUP_H_
#define SYSTEM_STARTUP_H_

typedef enum WFI_SM_
{
    INIT_THREAD_PR                      = 0x00,         /*!< 0 initi pointer                        */
    CHECK_WFI                           = 0x01,         /*!< is hart in wfi?                        */
    SEND_WFI                            = 0x02,         /*!< seperate state to add a little delay   */
    CHECK_WAKE                          = 0x03,         /*!< has hart left wfi                      */
} WFI_SM;

typedef struct HLS_DATA_
{
    volatile uint32_t in_wfi_indicator;
} HLS_DATA;

/*------------------------------------------------------------------------------
 * Symbols from the linker script used to locate the text, data and bss sections.
 */

extern unsigned int __stack_top_h1$;
extern unsigned int __stack_bottom_h1$;

extern unsigned int __data_load;
extern unsigned int __data_start;
extern unsigned int __data_end;

extern unsigned int __sbss_start;
extern unsigned int __sbss_end;

extern unsigned int __bss_start;
extern unsigned int __bss_end;

extern unsigned int __sdata_load;
extern unsigned int __sdata_start;
extern unsigned int __sdata_end;

#endif /* SYSTEM_STARTUP_H_ */
