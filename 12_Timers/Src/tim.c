#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)

#define TIM2EN              (1UL<<0)

void tim2_1hz_init(void)
{
    /*Enable Clock access to tim2*/
    RCC ->APB1ENR |= TIM2EN;

    /*Set prescaler value*/
    /*Set auto-reload value*/
    /*Enable timer*/
}