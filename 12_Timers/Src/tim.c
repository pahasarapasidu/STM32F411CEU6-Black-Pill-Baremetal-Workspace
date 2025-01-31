#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)

#define TIM2EN              (1UL<<0)
#define CR1_CEN             (1UL<<0)

void tim2_1hz_init(void)
{
    /*Enable Clock access to tim2*/
    RCC ->APB1ENR |= TIM2EN;

    /*Set prescaler value*/
    TIM2 ->PSC = 1600 - 1; //16 000 000/1 600 = 10 000

    /*Set auto-reload value*/ 
    TIM2 ->ARR = 10000 - 1; //10000/10 000 = 1Hz

    /*Clear counter*/
    TIM2 ->CNT = 0;


    /*Enable timer*/
    TIM2 ->CR1 |= CR1_CEN;

}