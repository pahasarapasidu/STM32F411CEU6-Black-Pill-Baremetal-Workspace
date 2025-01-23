/**
  ******************************************************************************
  * @file    uart.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackphill UART_RXTX Configuration 
  *
  *          This file contains:
  *           - uart2_init_config
  *           - uart2_baudrate_config
  *           - uart2_write
  *           - uart2_read
  *           - uart2_tx_init
  *           - uart2_rxtx_init
  *           - __io_putchar
  *           - compute_uart_bd
  *
  ******************************************************************************
  *@attention All functions are tested with WeAct STM32F411CEU6 Blackpill board
              Function definitions are in uart.c file
  ******************************************************************************

  */


#ifndef UART_H_
#define UART_H_

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)


void uart2_rxtx_init(void);
void uart2_write(int ch);
void uart2_tx_init(void);
char uart2_read(void);



#endif /* UART_H_ */
