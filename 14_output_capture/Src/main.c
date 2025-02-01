/*STM32F411CEU6-WeAct Blackpill Delay Configuration (Using Systick Timer)
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

int timestamp = 0;

/*Set up : Connect a jumper wire from PA5 to PA6*/

int main(void){

  pa5_af_mode();
  tim2_output_compare();

  pa6_af_mode();
  tim3_input_capture();

  
  while (1)
  {
    /*Wait until edge is capture*/
    while(!(TIM3 ->SR & SR_CC1IF));
    /*Read capture Value*/
    timestamp = TIM3 ->CCR1;

  }

}


