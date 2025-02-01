/*STM32F411CEU6-WeAct Blackpill ADC Configuration 
  For ADC1 (PA1)*/


#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
#include "adc.h"

#define GPIOAEN			(1UL <<0)
#define ADC1EN          (1UL <<8)

#define ADC_CH1         (1UL <<0)
#define ADC_SEQ_LEN_1    0x00
#define CR2_ADON        (1UL <<0)
#define CR2_SWSTART     (1UL <<30)
#define SR_EOC          (1UL <<1)
#define CR2_CONT        (1UL <<1)



void pa1_adc_init(void)
{
	/***Configure the GPIO pin***/

	/*Enable clock access to GPIOA*/
	RCC ->AHB1ENR |= GPIOAEN;

	/*Set the mode of PA1 to analog*/
    GPIOA ->MODER |= (3UL << 2); // Set bit 2 and 3 to 1

    // GPIOA ->MODER |= (1UL << 2); // Set bit 2 to 1
    // GPIOA ->MODER |= (1UL << 3); // Set bit 3 to 1



	/***Configure the ADC module***/

	/*Enable clock access to ADC*/
    RCC ->APB2ENR |= ADC1EN;

    /*Conversion sequence start*/
    ADC1 ->SQR3 = ADC_CH1; // Set the first conversion to channel 1

    /*Conversion sequence length*/
    ADC1 ->SQR1 = ADC_SEQ_LEN_1;

    /*Enable ADC module*/
    ADC1 ->CR2 |= CR2_ADON;

}

void start_conversion(void)
{
    /*Enable continuous conversion*/
    ADC1 ->CR2 |= CR2_CONT;
    /*Start ADC Conversion*/
    ADC1 ->CR2 |= CR2_SWSTART;

}

uint32_t adc_read(void)
{
    /*Wait for conversion to be complete*/
    while(!(ADC1 ->SR & SR_EOC)){}

    /*Read converted result*/ 
    return ADC1 ->DR;

}
