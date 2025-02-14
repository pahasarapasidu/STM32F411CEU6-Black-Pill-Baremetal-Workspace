/**
  ******************************************************************************
  * @file    tim.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackphill ADC Configuration 
  *
  *          This file contains:
  *           - TIM2 1Hz configuration
  *          
  *           
  *
  ******************************************************************************
  *@attention All functions are tested with WeAct STM32F411CEU6 Blackpill board
              Function definitions are in adc.c file
  ******************************************************************************

  */

#ifndef TIM_H_
#define TIM_H_

void tim2_1hz_init(void);


#define SR_UIF              (1UL<<0)

#endif /* TIM_H_ */
