#include "stm32f4xx.h"
#include "stm32f411xe.h"
 
#define GPIOCEN     (1UL << 2)
#define PIN13       (1UL << 13)
#define LED_PIN     PIN13

int main(void){
    RCC ->AHB1ENR |= GPIOCEN; // Enable clock for GPIOC
    GPIOC ->MODER |= (1 << 26); // Set pin 13 as output

    while (1)
    {
        GPIOC ->ODR ^= LED_PIN; // Toggle pin 13
        for (int i = 0; i < 100000; i++); // Delay
    }
    
}
