#include "exti.h"

#define GPIOBEN   (1UL << 1)
#define SYSCFGEN  (1UL << 14)

void pb13_exti_init(void)
{
    /*Disable global interrupt*/
    __disable_irq();

    /*Enable clock access for GPIOB */
    RCC->AHB1ENR |= GPIOBEN;

    /*Set PB13 as input*/
    GPIOB ->MODER &= ~(1UL <<26);
    GPIOB ->MODER &= ~(1UL <<27);
    
    /*Enable clock access to SYSCFG*/
    RCC ->APB1ENR |= SYSCFGEN;

    /*Select PORTB for EXTI13*/
    SYSCFG ->EXTICR[3] |= (1UL << 4);

    /*Unmask EXTI13*/
    EXTI ->IMR |= (1UL << 13);

    /*Select falling edge trigger*/
    EXTI ->FTSR |= (1UL << 13);

    /*Enable EXTI line in NVIC*/
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    
    /*Enable global interrupt*/
    __enable_irq();
}
