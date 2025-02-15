/**
  ******************************************************************************
  * @file    tim.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackphill ADC Configuration 
  *
  *          This file contains:
  *          **TIM2 1Hz configuration**
  *           - PA5 AF mode
  *           - TIM2 1Hz initialization
  *          **TIM2 Output Compare configuration**
  *           - PA5 AF mode
  *           - TIM2 Output Compare initialization
  *         **TIM3 Input Capture configuration**
  *           - PA6 AF mode
  *           - TIM3 Input Capture initialization
  * 
  *  
  *          
  *           
  *
  ******************************************************************************
  *@attention All functions are tested with WeAct STM32F411CEU6 Blackpill board
              Function definitions are in tim.c file
  ******************************************************************************

  */
#ifndef TIM_H_
#define TIM_H_

void pa5_af_mode(void);
void pa6_af_mode(void);

void tim2_1hz_init(void);
void tim2_output_compare(void);
void tim3_input_capture(void);

#define SR_UIF              (1UL<<0)
#define SR_CC1IF             (1UL<<1)

#endif /* TIM_H_ */
