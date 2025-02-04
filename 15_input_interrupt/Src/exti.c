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

    /*Unmask EXTI13*/
    /*Select falling edge trigger*/
    /*Enable EXTI line in NVIC*/
    /*Enable global interrupt*/
    __enable_irq();
}
