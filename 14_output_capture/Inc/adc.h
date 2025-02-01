/**
  ******************************************************************************
  * @file    adc.h
  * @author  pahasarapasidu
  * @brief   STM32F411CEU6-WeAct Blackphill ADC Configuration 
  *
  *          This file contains:
  *           - pa1_adc_ini
  *           - start_conversion
  *           - adc_read
  *
  ******************************************************************************
  *@attention All functions are tested with WeAct STM32F411CEU6 Blackpill board
              Function definitions are in adc.c file
  ******************************************************************************

  */


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void pa1_adc_init(void);
uint32_t adc_read(void);
void start_conversion(void);



#endif /* ADC_H_ */
