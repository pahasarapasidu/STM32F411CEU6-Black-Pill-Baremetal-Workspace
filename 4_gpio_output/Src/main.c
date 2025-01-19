/*STM32F411CEU6-WeAct Blackphill User LED Configuration 4
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
  & using Bit set/rest register*/

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
    GPIOC ->MODER |= (1UL << 26); //
    GPIOC ->MODER &= ~(1UL << 27); 



    while (1)
    {
        GPIOC ->BSRR =~LED_PIN; // Set pin 13
        for (int i = 0; i < 100000; i++); // Delay
        //GPIOC ->BSRR &=LED_PIN; // Set pin 13

        GPIOC ->BSRR =~(1UL << 26); // Reset pin 13
        for (int i = 0; i < 100000; i++); // Delay
        //GPIOC ->BSRR &=(1UL << 26); // Reset pin 13
    }
    
}
