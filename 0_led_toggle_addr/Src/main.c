//Where is the led connected?
//Port: C
//Pin: 13

#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOC_OFFSET		(0x00000800UL)
#define GPIOC_BASE			(AHB1PERIPH_BASE + GPIOC_OFFSET)

#define RCC_OFFSET			(0x00003800UL)                      //resetting clock control(RCC)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET) 

#define AHB1EN_R_OFFSET 	(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET   	(0x00UL)
#define GPIOC_MODE_R		(*(volatile unsigned int*)(GPIOC_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14UL)
#define GPIOC_OD_R			(*(volatile unsigned int*)(GPIOC_BASE + OD_R_OFFSET))

#define GPIOCEN				(1UL << 2) //0b 0000 0000 0000 0000 0000 0000 0000 0100

#define PIN13               (1Ul << 13)
#define LED_PIN             PIN13