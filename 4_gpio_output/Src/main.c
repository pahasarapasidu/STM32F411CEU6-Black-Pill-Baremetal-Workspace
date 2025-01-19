/*STM32F411CEU6-WeAct Blackphill User Button Configuration 1  (in build switch)
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
 
#define GPIOAEN     (1UL << 0)
#define GPIOCEN     (1UL << 2)

#define PIN0         (1UL << 0)
#define PIN13       (1UL << 13)

#define BTN_PIN     PIN0
#define LED_PIN     PIN13




int main(void){

    /*Enable clock access to GPIOA and GPIOC*/
    RCC ->AHB1ENR |= GPIOCEN; // Enable clock for GPIOC
    RCC ->AHB1ENR |= GPIOAEN; // Enable clock for GPIOA

    /*Set PC13 as output pin*/
    GPIOC ->MODER |= (1UL << 26); // Set 26th bit to 1
    GPIOC ->MODER &= ~(1UL << 27); // Set 27th bit to 0

    /*Set PA0 as input pin*/
    GPIOA ->MODER &= ~(1UL << 0); // Set 0th bit to 0
    GPIOA ->MODER &= ~(1UL << 1); // Set 1st bit to 0



    while (1)
    {
        /*Check if BTN is pressed*/
        if (GPIOA ->IDR & BTN_PIN) // Check if 0th bit is set
        {
            /*Turn on LED*/
          GPIOC ->BSRR = ~LED_PIN;
        }
        else
        {
            /*Turn off LED*/
          GPIOC ->BSRR = ~(1UL << 29);
        }     

        
    }
    
}
