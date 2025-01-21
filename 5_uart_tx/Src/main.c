/*STM32F411CEU6-WeAct Blackphill UART_TX Configuration   
  BareMetal Programming with STM Header Files(https://github.com/STMicroelectronics/STM32CubeF4)
 */

#include "stm32f4xx.h" //Include the STM32F4xx header file(Standard peripheral library)
#include "stm32f411xe.h"//Include the STM32F411 header file(Standard peripheral library)
 
#define GPIOAEN     (1UL << 0)
#define UART6EN     (1UL << 5)

#define CR1_TE      (1UL << 3)
#define CR1_UE      (1UL << 13) 
#define SR_TXE      (1UL << 7)

#define SYS_FREQ    16000000U
#define APB2_CLK    SYS_FREQ

#define UART_BAUDRATE 115200U

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);

void uart6_tx_init(void);
void usart6_write(int ch);

int main(void){

  uart6_tx_init();


    while (1)
    {
        usart6_write('S'); 
    }
    
}

void uart6_tx_init(void)
{
    /**************Configure uart gpio pin**************/
    /*Enable clock access to gpioA*/
    RCC ->AHB1ENR |= GPIOAEN;
    /*Set PA11 mode to alternate function mode*/
    GPIOA ->MODER |= (1UL << 23);
    GPIOA ->MODER &= ~(1UL << 22);

    /*Ser PA11 alternate function type to UART_TX (AF08)*/
    GPIOA ->AFR[1] |= (1UL << 15);
    GPIOA ->AFR[1] &= ~(1UL << 14);
    GPIOA ->AFR[1] &= ~(1UL << 13);
    GPIOA ->AFR[1] &= ~(1UL << 12);

    /**************Configure uart module**************/
    /*Enable clock access to uart6*/
    RCC ->APB2ENR |= UART6EN;

    /*Configure baudrate*/
    uart_set_baudrate(USART6, APB2_CLK, UART_BAUDRATE);

    /*Configure the transfer direction*/
    USART6 ->CR1 = CR1_TE;

    /*Enable uart module*/
    USART6 ->CR1 |= CR1_UE;

}


void usart6_write(int ch)
{
    /*****Write Data to transmit*****/
    
  /*Make sure the transmit data register is empty*/
  while(!(USART6 ->SR & SR_TXE)){}

  /*Write to transmit data register*/ 
  USART6 ->DR = (ch & 0xFF);




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