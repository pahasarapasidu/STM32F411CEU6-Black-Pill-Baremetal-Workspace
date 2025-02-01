#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)

#define TIM2EN              (1UL<<0)
#define TIM3EN              (1UL<<1)

#define CR1_CEN             (1UL<<0)
#define OC_TOGGLE           (3UL<<4) // (1UL<<4) | (1UL<<5)
#define CCER_CC1E           (1UL<<0)

#define AFR5_TIM            (1UL<<20)
#define AFR6_TIM            (1UL<<25)


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

void tim2_output_compare(void)
{
    /*Enable Clock access to tim2*/
    RCC ->APB1ENR |= TIM2EN;

    /*Set prescaler value*/
    TIM2 ->PSC = 1600 - 1; //16 000 000/1 600 = 10 000

    /*Set auto-reload value*/
    TIM2 ->ARR = 10000 - 1; //10000/10 000 = 1Hz

    /*Set output compare toggle mode*/
    TIM2 ->CCMR1 = OC_TOGGLE;

    /*Enable tim2 ch1 in compare mode*/
    TIM2 ->CCER |= CCER_CC1E;

    /*Clear counter*/
    TIM2 ->CNT = 0;


    /*Enable timer*/
    TIM2 ->CR1 |= CR1_CEN;

}

void tim3_input_capture(void)
{
    /*Enable Clock access to tim3*/
    RCC ->APB1ENR |= TIM3EN;

    /*Set prescaler value*/
    TIM2 ->PSC = 16000  - 1; //16 000 000/16 000 = 10 00

    /*Set CH1 to capture at every edge*/
    
    /*Set CH1 to capture at rising edge*/
    /*Enable tim3*/


    /*Set auto-reload value*/
    TIM2 ->ARR = 10000 - 1; //10000/10 000 = 1Hz

    /*Set output compare toggle mode*/
    TIM2 ->CCMR1 = OC_TOGGLE;

    /*Enable tim2 ch1 in compare mode*/
    TIM2 ->CCER |= CCER_CC1E;

    /*Clear counter*/
    TIM2 ->CNT = 0;


    /*Enable timer*/
    TIM2 ->CR1 |= CR1_CEN;

    

}

void pa5_af_mode(void)
{
    /*Enable clock access to GPIOA*/
    RCC ->AHB1ENR |= (1UL<<0);

    /*Set PA5 as alternate function mode*/
    GPIOA ->MODER &= ~(1UL<<10);
    GPIOA ->MODER |= (1UL<<11);

    /*Set PA5 as AF01*/
    GPIOA ->AFR[0] |= AFR5_TIM;
}

void pa6_af_mode(void)
{
    /*Enable clock access to GPIOA*/
    RCC ->AHB1ENR |= (1UL<<0);

    /*Set PA6 as alternate function mode*/
    GPIOA ->MODER &= ~(1UL<<12);
    GPIOA ->MODER |= (1UL<<13);

    /*Set PA6 as AF02*/
    GPIOA ->AFR[0] |= AFR6_TIM;
}
