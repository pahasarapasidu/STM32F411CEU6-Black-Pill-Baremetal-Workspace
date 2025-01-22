/*STM32F411CEU6-WeAct Blackphill UART_RXTX Configuration 
  For UART2 (PA2, PA3)*/

#include "uart.h"

#define GPIOAEN     (1UL << 0)
#define UART2EN     (1UL << 17)

#define CR1_TE      (1UL << 3)
#define CR1_RE      (1UL << 2)

#define CR1_UE      (1UL << 13) 
#define SR_TXE      (1UL << 7)
#define SR_RXNE     (1UL << 5)

#define SYS_FREQ    16000000U
#define APB1_CLK    SYS_FREQ

#define UART_BAUDRATE 115200U

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);


void uart2_write(int ch);

int __io_putchar(int ch)
{
  uart2_write(ch);
  return ch;
}

void uart2_rxtx_init(void)
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

     /*Set PA3 mode to alternate function mode*/
    GPIOA ->MODER |= (1UL << 7);
    GPIOA ->MODER &= ~(1UL << 6);

     /*Ser PA3 alternate function type to UART_TX (AF07)*/
    GPIOA ->AFR[0] &= ~(1UL << 15);
    GPIOA ->AFR[0] |= (1UL << 14);
    GPIOA ->AFR[0] |= (1UL << 13);
    GPIOA ->AFR[0] |= (1UL << 12);


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
    USART2 ->CR1 = (CR1_TE | CR1_RE);

    /*Enable uart module*/
    USART2 ->CR1 |= CR1_UE;

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

char uart2_read(void)
{
  /*Make sure the receive data register is not empty*/
  while(!(USART2 ->SR & SR_RXNE)){}

  /*Read Data*/
  return USART2 ->DR;
}

void uart2_write(int ch)
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
