/*STM32F411CEU6-WeAct Blackpill UART_RXTX Configuration   
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include <stdio.h>//Include the standard input/output header file
#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
#include "uart.h"//Include the UART header file
#include "adc.h"//Include the ADC header file

uint32_t sensor_value;

int main(void){

  uart2_rxtx_init();
  pa1_adc_init();
  start_conversion();
  
  while (1)
  {
	start_conversion();

	sensor_value = adc_read();
	printf("ADC Value: %d\n\r", (int)sensor_value);

    for(volatile int i = 0; i < 100000; i++);

  }

}
