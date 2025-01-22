/*STM32F411CEU6-WeAct Blackphill UART_TX Configuration   
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
#include "uart.h"



int main(void){

  uart2_tx_init();


  while (1)
  {
    printf("Hello from STM32F411CEU6 Blackpill....\n\r");

    for(volatile int i = 0; i < 1000000; i++);
  }
    
}




