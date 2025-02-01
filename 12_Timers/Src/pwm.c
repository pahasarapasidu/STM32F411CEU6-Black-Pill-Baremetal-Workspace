/*STM32F411CEU6-WeAct Blackpill PWM Configuration (Using TIM2)
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

/** 
 *   Modify the code to vary the duty cycle of the PWM signal, you can dynamically update the Capture/Compare Register (CCR1) of the timer.
 *   This allows you to change the duty cycle during runtime. 
 *   Below is the modified code with a mechanism to vary the duty cycle from 0% to 100% and back to 0% in a loop
 *   This USE TIM2 and PA5
 * */

void TIM2_PWM_Init(void) {
    // 1. Enable GPIOA and TIM2 clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;  // Enable TIM2 clock

    // 2. Configure PA0 as alternate function (TIM2_CH1)
    GPIOA->MODER &= ~(1UL << 10);         // Clear mode bits for PA5
    GPIOA->MODER |= (1UL << 11);          // Set PA0 to alternate function mode
    //GPIOA->AFR[0] &= ~(0xFUL << 20);      // Clear alternate function bits for PA5
    GPIOA->AFR[0] |= (1UL << 20);         // Set PA0 to AF1 (TIM2_CH1)

    // 3. Configure TIM2 for PWM
    // Set prescaler for 16 MHz / 16 = 1 MHz timer clock
    TIM2->PSC = 16 - 1;

    // Set auto-reload register for 1 kHz PWM frequency
    // ARR = (Timer Clock / PWM Frequency) - 1
    TIM2->ARR = 1000 - 1;

    // Set capture/compare register for 50% duty cycle
    // CCR1 = (ARR + 1) * Duty Cycle
    TIM2->CCR1 = 0; // 50% duty cycle

    // Configure TIM2 Channel 1 for PWM mode 1
    TIM2->CCMR1 &= ~TIM_CCMR1_OC1M; // Clear OC1M bits
    TIM2->CCMR1 |= (6UL << 4);      // Set OC1M to PWM mode 1 (0110)

    // Enable output for TIM2 Channel 1
    TIM2->CCER |= TIM_CCER_CC1E;

    // Enable TIM2
    TIM2->CR1 |= TIM_CR1_CEN;
}
/******* Example of Using above in main loop *******/

// int main(void) {
//     // Initialize PWM on TIM2 Channel 1 (PA0)
//     TIM2_PWM_Init();

//     uint16_t duty_cycle = 0; // Start with 0% duty cycle
//     uint8_t direction = 1;   // 1 = increasing, 0 = decreasing

//     while (1) {
//         // Update the duty cycle
//         TIM2->CCR1 = duty_cycle;

//         // Adjust duty cycle
//         if (direction) {
//             duty_cycle += 10; // Increase duty cycle
//             if (duty_cycle >= 1000) {
//                 duty_cycle = 1000; // Clamp to 100%
//                 direction = 0;     // Change direction
//             }
//         } else {
//             duty_cycle -= 10; // Decrease duty cycle
//             if (duty_cycle <= 0) {
//                 duty_cycle = 0; // Clamp to 0%
//                 direction = 1;  // Change direction
//             }
//         }

//         // Add a delay to observe the change in duty cycle
//         systickDelayMs(50);
//     }
//}
