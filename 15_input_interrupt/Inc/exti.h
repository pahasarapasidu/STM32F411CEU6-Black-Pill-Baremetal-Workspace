/**
  ******************************************************************************
  * @file    exti.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackphill ADC Configuration 
  *
  *          This file contains:
  *           - pb13_exti_init
  *           
  *
  ******************************************************************************
  *@attention All functions are tested with WeAct STM32F411CEU6 Blackpill board
              Function definitions are in adc.c file
  ******************************************************************************

  */

#ifndef EXTI_H_
#define EXTI_H_


#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)

void pb13_exti_init(void);

#endif /* EXTI_H_ */
