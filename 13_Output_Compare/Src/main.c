/*STM32F411CEU6-WeAct Blackpill Toggling PC13 LED every 1 second using TIM2
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
#include "uart.h"//Include the UART header file
#include "adc.h"//Include the ADC header file
#include "systick.h"//Include the Systick header file
#include "tim.h"//Include the Timer header file



#define GPIOCEN				(1UL << 2) //0b 0000 0000 0000 0000 0000 0000 0000 0100

#define PIN13               (1UL << 13)
#define LED_PIN             PIN13

int main(void){

	pa5_af_mode();
	tim2_output_compare();

  
  while (1)
  {
    
  }

}


