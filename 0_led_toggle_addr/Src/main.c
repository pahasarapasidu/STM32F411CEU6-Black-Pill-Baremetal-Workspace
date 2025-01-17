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