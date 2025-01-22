/*STM32F411CEU6-WeAct Blackphill UART_TX Configuration   
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
#include "uart.h"


#define GPIOCEN				(1UL << 2) //0b 0000 0000 0000 0000 0000 0000 0000 0100

#define PIN13               (1UL << 13)
#define LED_PIN             PIN13

char key;


int main(void){

  uart2_rxtx_init();
  /*1. Enable clock access to GPIOC*/
  RCC ->AHB1ENR |= GPIOCEN;
  /*2. Set PC13 as output pin*/
  GPIOC ->MODER|= (1UL << 26); // Set bit 26 to 1
  GPIOC ->MODER &=~(1UL << 27); // Set bit 27 to 0

  

  while (1)
  {

    
    key = uart2_read();
    if (key == '1')
    {
      GPIOC ->ODR &= LED_PIN; // Set PC13 LOW(Turn on user LED for WeactStudio blackphill)
    }
    else{
      GPIOC ->ODR |= LED_PIN; // Set PC13 HIGH(Turn off user LED for WeactStudio blackphill)
    }
    


    
  }
    
}




