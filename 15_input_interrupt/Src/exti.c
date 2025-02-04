#include "exti.h"

#define GPIOBEN   (1UL << 1)

void pb13_exti_init(void)
{
    /*Disable global interrupt*/
    __disable_irq();

    /*Enable clock access for GPIOB */
    RCC->AHB1ENR |= GPIOBEN;
    
    /*Enable clock access to SYSCFG*/
    
    /*Select PORTB for EXTI13*/
    /*Unmask EXTI13*/
    /*Select falling edge trigger*/
    /*Enable EXTI line in NVIC*/
    /*Enable global interrupt*/
    __enable_irq();
}
