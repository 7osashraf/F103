#ifndef STM32F103C8T6
#define STM32F103C8T6

/************************   Various Memories Base Addresses   ************************/

#define FLASH_BASE_ADDRESS		0x08000000UL
#define SRAM_BASE_ADDRESS		0x20000000UL
#define ROM_BASE_ADDRESS		0x1FFF0000UL


/************************   AHB Peripherals Base Addresses   ************************/
#define RCC_BASE_ADDRESS		0x40021000
#define DMA1_BASE_ADDRESS       0x40020000   
#define DMA2_BASE_ADDRESS       0x40020400   

/************************   APB1 Peripherals Base Addresses   ************************/
#define TIM2_BASE_ADDRESS       0x40000000   
#define TIM3_BASE_ADDRESS       0x40000400   
#define TIM4_BASE_ADDRESS       0x40000800  
#define TIM5_BASE_ADDRESS       0x40000C00   
#define TIM6_BASE_ADDRESS       0x40001000   
#define TIM7_BASE_ADDRESS       0x40001400    

/************************   APB2 Peripherals Base Addresses   ************************/
#define GPIOA_BASE_ADDRESS      0x40010800   
#define GPIOB_BASE_ADDRESS      0x40010C00   
#define GPIOC_BASE_ADDRESS      0x40011000
#define GPIOD_BASE_ADDRESS      0x40011400   
#define GPIOE_BASE_ADDRESS      0x40011800   
#define GPIOF_BASE_ADDRESS      0x40011C00   
#define GPIOG_BASE_ADDRESS      0x40012000 
 
#define ADC1_BASE_ADDRESS       0x40012400  
#define ADC2_BASE_ADDRESS       0x40012800 

#define TIM1_BASE_ADDRESS       0x40012C00 
 
#define SPI1_BASE_ADDRESS       0x40013000

#define USART1_BASE_ADDRESS     0x40013800

#define TIM8_BASE_ADDRESS       0x40013400

/************************   GPIO Register Definition Structure   ************************/

typedef struct
{
	volatile uint32_t CRL;    // GPIO port configuration register low
	volatile uint32_t CRH;    // GPIO port configuration register high
	volatile uint32_t IDR;    // GPIO port input data register
	volatile uint32_t ODR;    // GPIO port output data register
	volatile uint32_t BSRR;   // GPIO port bit set/reset register
	volatile uint32_t BRR;    // GPIO port bit reset register
	volatile uint32_t LCKR;   // GPIO port configuration lock register
} GPIO_RegDef_t;

/************************   RCC Register Definition Structure   ************************/

typedef struct
{
    volatile uint32_t CR;        // Clock control register
    volatile uint32_t CFGR;      // Clock configuration register
    volatile uint32_t CIR;       // Clock interrupt register
    volatile uint32_t APB2RSTR;  // APB2 peripheral reset register
    volatile uint32_t APB1RSTR;  // APB1 peripheral reset register
    volatile uint32_t AHBENR;    // AHB peripheral clock enable register
    volatile uint32_t APB2ENR;   // APB2 peripheral clock enable register
    volatile uint32_t APB1ENR;   // APB1 peripheral clock enable register
    volatile uint32_t BDCR;      // Backup domain control register
    volatile uint32_t CSR;       // Control/status register
    volatile uint32_t AHBSTR;    // AHB peripheral reset register
    volatile uint32_t CFGR2;     // Clock configuration register 2
} RCC_RegDef_t;

/************************   GPIO Peripheral Definition   ************************/

#define GPIOA 							((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB 							((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC 							((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD 							((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE 							((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF 							((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG 							((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)


#endif