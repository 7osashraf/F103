#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include <stdint.h>

typedef enum {
	RCC_CLK_HSI,
	RCC_CLK_HSE,
	RCC_CLK_PLL
} RCC_ClkType;

typedef enum {
	RCC_CLK_OFF,
	RCC_CLK_ON
}RCC_ClkStatus;

typedef enum {
    RCC_HSE_DIV1,
    RCC_HSE_DIV2
} RCC_HSE_Config;

typedef enum {
    RCC_PLL_MUL_2 = 0,
    RCC_PLL_MUL_3,
    RCC_PLL_MUL_4,
    RCC_PLL_MUL_5,
    RCC_PLL_MUL_6,
    RCC_PLL_MUL_7,
    RCC_PLL_MUL_8,
    RCC_PLL_MUL_9,
    RCC_PLL_MUL_10,
    RCC_PLL_MUL_11,
    RCC_PLL_MUL_12,
    RCC_PLL_MUL_13,
    RCC_PLL_MUL_14,
    RCC_PLL_MUL_15,
    RCC_PLL_MUL_16
} RCC_PLLMul;

typedef enum {
    RCC_PLL_SRC_HSI_DIV2,
    RCC_PLL_SRC_HSE
} RCC_PLLSrc;

typedef enum {
    RCC_AHB_DMA1   = 0,  // DMA1
    RCC_AHB_DMA2   = 1,  // DMA2
    RCC_AHB_SRAM   = 2,  // SRAM interface
    RCC_AHB_FLITF  = 4,  // FLITF (Flash interface)
    RCC_AHB_CRC    = 6   // CRC
} RCC_AHBPeriph;


typedef enum {
    RCC_APB1_TIM2    = 0,  // TIM2
    RCC_APB1_TIM3    = 1,  // TIM3
    RCC_APB1_TIM4    = 2,  // TIM4
    RCC_APB1_TIM5    = 3,  // TIM5
    RCC_APB1_TIM6    = 4,  // TIM6
    RCC_APB1_TIM7    = 5,  // TIM7
    RCC_APB1_WWDG    = 11, // Window watchdog
    RCC_APB1_SPI2    = 14, // SPI2
    RCC_APB1_SPI3    = 15, // SPI3
    RCC_APB1_USART2  = 17, // USART2
    RCC_APB1_USART3  = 18, // USART3
    RCC_APB1_UART4   = 19, // UART4
    RCC_APB1_UART5   = 20, // UART5
    RCC_APB1_I2C1    = 21, // I2C1
    RCC_APB1_I2C2    = 22, // I2C2
    RCC_APB1_USB     = 23, // USB
    RCC_APB1_CAN     = 25, // CAN
    RCC_APB1_BKP     = 27, // Backup interface
    RCC_APB1_PWR     = 28, // Power interface
    RCC_APB1_DAC     = 29  // DAC
} RCC_APB1Periph;

typedef enum {
    RCC_APB2_AFIO      = 0,  // Alternate function I/O
    RCC_APB2_GPIOA     = 2,  // GPIO Port A
    RCC_APB2_GPIOB     = 3,  // GPIO Port B
    RCC_APB2_GPIOC     = 4,  // GPIO Port C
    RCC_APB2_GPIOD     = 5,  // GPIO Port D
    RCC_APB2_GPIOE     = 6,  // GPIO Port E
    RCC_APB2_ADC1      = 9,  // ADC1
    RCC_APB2_ADC2      = 10, // ADC2
    RCC_APB2_TIM1      = 11, // TIM1
    RCC_APB2_SPI1      = 12, // SPI1
    RCC_APB2_USART1    = 14, // USART1
    RCC_APB2_TIM8      = 13, // TIM8
    RCC_APB2_ADC3      = 15  // ADC3
} RCC_APB2Periph;

// Function prototypes for RCC functions
void RCC_SetClkSts(RCC_ClkType ClkType, RCC_ClkStatus Stauts); //set clock status
void RCC_SetSysClk(RCC_ClkType ClkType); //set the system clock
void RCC_HSEConfig(RCC_HSE_Config config); //select HSE config
void RCC_PLLConfig(RCC_PLLMul mul, RCC_PLLSrc src);
void RCC_AHBEnableClock(RCC_AHBPeriph peripheral);
void RCC_AHBDisableClock(RCC_AHBPeriph peripheral);
void RCC_APB1EnableClock(RCC_APB1Periph peripheral);
void RCC_APB1DisableClock(RCC_APB1Periph peripheral);
void RCC_APB2EnableClock(RCC_APB2Periph peripheral);
void RCC_APB2DisableClock(RCC_APB2Periph peripheral);




#endif // RCC_INTERFACE_H
