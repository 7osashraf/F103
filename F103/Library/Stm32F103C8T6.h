#ifndef STM32F103C8T6
#define STM32F103C8T6

#include <stdint.h>


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

/************************   NVIC Base Address   ************************/
#define NVIC_BASE_ADDRESS        0xE000E100UL
/************************   SCB Base Address   ************************/
#define SCB_BASE_ADDRESS 0xE000ED00UL

/************************   NVIC Register Definition Structure   ************************/

typedef struct
{
    volatile uint32_t ISER[3];    // Interrupt Set Enable Registers (0xE000E100 - 0xE000E10C)
    uint32_t RESERVED0[29];       // Reserved memory space
    volatile uint32_t ICER[3];    // Interrupt Clear Enable Registers (0xE000E180 - 0xE000E18C)
    uint32_t RESERVED1[29];       // Reserved memory space
    volatile uint32_t ISPR[3];    // Interrupt Set Pending Registers (0xE000E200 - 0xE000E20C)
    uint32_t RESERVED2[29];       // Reserved memory space
    volatile uint32_t ICPR[3];    // Interrupt Clear Pending Registers (0xE000E280 - 0xE000E28C)
    uint32_t RESERVED3[29];       // Reserved memory space
    volatile uint32_t IABR[3];    // Interrupt Active Bit Registers (0xE000E300 - 0xE000E30C)
    uint32_t RESERVED4[61];       // Reserved memory space
    volatile uint8_t  IP[84];     // Interrupt Priority Registers (0xE000E400 - 0xE000E4F3)
    uint32_t RESERVED5[690];      // Reserved memory space
    volatile uint32_t STIR;       // Software Trigger Interrupt Register (0xE000EF00)
} NVIC_RegDef_t;


/************************   SCB Register Definition Structure   ************************/

typedef struct
{
    volatile uint32_t CPUID;    // CPUID Base Register
    volatile uint32_t ICSR;     // Interrupt Control and State Register
    volatile uint32_t VTOR;     // Vector Table Offset Register
    volatile uint32_t AIRCR;    // Application Interrupt and Reset Control Register
    volatile uint32_t SCR;      // System Control Register
    volatile uint32_t CCR;      // Configuration and Control Register
    volatile uint8_t  SHP[12];  // System Handler Priority Registers
    volatile uint32_t SHCSR;    // System Handler Control and State Register
    volatile uint32_t CFSR;     // Configurable Fault Status Register
    volatile uint32_t HFSR;     // HardFault Status Register
    volatile uint32_t MMAR;     // MemManage Fault Address Register
    volatile uint32_t BFAR;     // BusFault Address Register
    volatile uint32_t AFSR;     // Auxiliary Fault Status Register
} SCB_RegDef_t;

/************************   GPIO Peripheral Definition   ************************/

#define GPIOA 							((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB 							((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC 							((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD 							((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE 							((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF 							((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG 							((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)


#endif
