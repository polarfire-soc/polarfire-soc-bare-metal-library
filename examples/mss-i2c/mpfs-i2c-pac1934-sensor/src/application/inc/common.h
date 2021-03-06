/*******************************************************************************
 * Copyright 2019-2021 Microchip FPGA Embedded Systems Solution.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include "drivers/mss/mss_mmuart/mss_uart.h"

typedef enum COMMAND_TYPE_
{
    CLEAR_COMMANDS                  = 0x00,       /*!< 0 default behavior */
    START_HART1_U_MODE              = 0x01,       /*!< 1 u mode */
    START_HART2_S_MODE              = 0x02,       /*!< 2 s mode */
}   COMMAND_TYPE;


typedef enum MODE_CHOICE_
{
    M_MODE              = 0x00,       /*!< 0 m mode */
    S_MODE              = 0x01,       /*!< s mode */
}   MODE_CHOICE;

typedef struct _UART_LOCK
{
    volatile long uart0 ;
    volatile long uart1 ;
    volatile long uart2 ;
    volatile long uart3 ;
    volatile long uart4 ;
} UART_LOCK;


/**
 * extern variables
 */


#endif /* COMMON_H_ */
