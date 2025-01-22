/**
  ******************************************************************************
  * @file    uart.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackpill UART_TX Configuration 
  *
  *          This file contains:
  *           - uart2_init_config
  *           - compute_uart_bd
  *           - uart2_baudrate_config
  *           - uart2_write
  *           - uart2_tx_init
  *           - __io_putchar
  *
  ******************************************************************************
  */


#ifndef UART_H_
#define UART_H_

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)

void uart2_tx_init(void);


#endif /* UART_H_ */
