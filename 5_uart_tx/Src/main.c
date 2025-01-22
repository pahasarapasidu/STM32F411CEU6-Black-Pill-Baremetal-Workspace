/*STM32F411CEU6-WeAct Blackphill UART_TX Configuration   
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include <stdint.h> //Include the standard integer header file
#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
 
#define GPIOAEN     (1UL << 0)
#define UART2EN     (1UL << 17)

#define CR1_TE      (1UL << 3)
#define CR1_UE      (1UL << 13) 
#define SR_TXE      (1UL << 7)

#define SYS_FREQ    16000000U
#define APB1_CLK    SYS_FREQ

#define UART_BAUDRATE 9600U

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);

void uart2_tx_init(void);
void usart2_write(int ch);

int main(void){

  uart2_tx_init();


  while (1)
  {
    usart2_write('Y');

    for(volatile int i = 0; i < 1000000; i++);
  }
    
}

void uart2_tx_init(void)
{
    /**************Configure uart gpio pin**************/
    /*Enable clock access to gpioA*/
    RCC ->AHB1ENR |= GPIOAEN;
    /*Set PA2 mode to alternate function mode*/
    GPIOA ->MODER |= (1UL << 5);
    GPIOA ->MODER &= ~(1UL << 4);

     /*Ser PA2 alternate function type to UART_TX (AF07)*/
     GPIOA ->AFR[0] &= ~(1UL << 11);
     GPIOA ->AFR[0] |= (1UL << 10);
     GPIOA ->AFR[0] |= (1UL << 9);
     GPIOA ->AFR[0] |= (1UL << 8);

//    /*Set PA2 alternate function type to UART_TX (AF07)*/
//    // Clear the bits first
//    GPIOA->AFR[0] &= ~(0xFU << 8);  // Clear bits 8-11
//    // Set to AF7 (0111)
//    GPIOA->AFR[0] |= (7U << 8);     // Set to AF7

    /**************Configure uart module**************/
    /*Enable clock access to uart2*/
    RCC ->APB1ENR |= UART2EN;

    /*Configure baudrate*/
    uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    /*Configure the transfer direction*/
    USART2 ->CR1 = CR1_TE;

    /*Enable uart module*/
    USART2 ->CR1 |= CR1_UE;

}


void usart2_write(int ch)
{
    /*****Write Data to transmit*****/

  /*Make sure the transmit data register is empty*/
  while(!(USART2 ->SR & SR_TXE)){}

  /*Write to transmit data register*/ 
  USART2 ->DR = (ch & 0xFF);




}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
    /****Write Calculated Baudrate to any USARTx BRR****/
  USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
    /****USART BaudRate devident factor(N) Calculation
                      SYS_CLK/BR = N                  ****/
  return ((PeriphClk + (BaudRate/2U))/BaudRate);

}
