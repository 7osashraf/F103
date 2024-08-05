#include "rcc_interface.h"
#include "rcc_register.h"
#include "rcc_private.h"



void RCC_SetClkSts(RCC_ClkType ClkType, RCC_ClkStatus Stauts){
	switch(ClkType) {
		case RCC_CLK_HSI:
			if(RCC_CLK_ON == Stauts) {
				RCC->CR |= RCC_CR_HSION;
				// Wait until HSI is ready
				while (!(RCC->CR & RCC_CR_HSIRDY));
			} else {
				RCC->CR &= ~RCC_CR_HSION;
				// Wait until HSI is not ready
				while (RCC->CR & RCC_CR_HSIRDY);
			}
			break;
		case RCC_CLK_HSE :
			if(RCC_CLK_ON == Stauts) {
				RCC->CR |= RCC_CR_HSEON;
				// Wait until HSI is ready
				while (!(RCC->CR & RCC_CR_HSERDY));
			} else {
				RCC->CR &= ~RCC_CR_HSEON;
				// Wait until HSI is not ready
				while (RCC->CR & RCC_CR_HSERDY);
			}
			break;
		case RCC_CLK_PLL :
			if (RCC_CLK_ON == Stauts) {
				RCC->CR |= RCC_CR_PLLON;
			    // Wait until PLL is ready
			    while (!(RCC->CR & RCC_CR_PLLRDY));
			} else {
			    RCC->CR &= ~RCC_CR_PLLON;
			    // Wait until PLL is not ready
			    while (RCC->CR & RCC_CR_PLLRDY);
	        }
			break;
		default :
	}
}

void RCC_SetSysClk(RCC_ClkType ClkType){
	uint32_t temp = RCC->CFGR;


	switch(ClkType) {
			case RCC_CLK_HSI:
				temp &= ~0x03; // Clear SW bits
				temp |= RCC_CFGR_SW_HSI;
				break;
			case RCC_CLK_HSE :
				temp &= ~0x03; // Clear SW bits
				temp |= RCC_CFGR_SW_HSE;
				break;
			case RCC_CLK_PLL :
				temp &= ~0x03; // Clear SW bits
				temp |= RCC_CFGR_SW_PLL;
				break;
			default :
	}

	RCC->CFGR = temp;

	// Wait until the switch is complete
	while (((RCC->CFGR & 0x0C) >> 2) != ClkType);
}

void RCC_HSEConfig(RCC_HSE_Config config){
	if ( RCC_HSE_DIV1 == config) {
		RCC->CFGR  &= ~(1 << 17); // Clear HSE division factor bit

	} else if ( RCC_HSE_DIV2 == config) {
		RCC->CFGR |= (1 << 17); // Set HSE division factor bit
	}
}

void RCC_PLLConfig(RCC_PLLMul mul, RCC_PLLSrc src){
	// Disable PLL before configuring it
	RCC->CR &= ~RCC_CR_PLLON;

	// Clear PLL configuration bits
	RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);

	// Set PLL source
	if (RCC_PLL_SRC_HSI_DIV2 == src) {
		RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_DIV2;
	} else if (RCC_PLL_SRC_HSE == src) {
		RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;
	}

	// Set PLL multiplier
	RCC->CFGR |= (mul << 18);

	// Enable PLL
	RCC->CR |= RCC_CR_PLLON;

	// Wait until PLL is ready
	while (!(RCC->CR & RCC_CR_PLLRDY));
}

void RCC_AHBEnableClock(RCC_AHBPeriph peripheral){

	 switch (peripheral) {
	        case RCC_AHB_DMA1:
	            RCC->AHBENR |= RCC_AHBENR_DMA1EN;
	            break;
	        case RCC_AHB_DMA2:
	            RCC->AHBENR |= RCC_AHBENR_DMA2EN;
	            break;
	        case RCC_AHB_SRAM:
	            RCC->AHBENR |= RCC_AHBENR_SRAMEN;
	            break;
	        case RCC_AHB_FLITF:
	            RCC->AHBENR |= RCC_AHBENR_FLITFEN;
	            break;
	        case RCC_AHB_CRC:
	            RCC->AHBENR |= RCC_AHBENR_CRCEN;
	            break;
	    }

}

void RCC_AHBDisableClock(RCC_AHBPeriph peripheral){

	 switch (peripheral) {
	        case RCC_AHB_DMA1:
	            RCC->AHBENR &= ~RCC_AHBENR_DMA1EN;
	            break;
	        case RCC_AHB_DMA2:
	            RCC->AHBENR &= ~RCC_AHBENR_DMA2EN;
	            break;
	        case RCC_AHB_SRAM:
	            RCC->AHBENR &= ~RCC_AHBENR_SRAMEN;
	            break;
	        case RCC_AHB_FLITF:
	            RCC->AHBENR &= ~RCC_AHBENR_FLITFEN;
	            break;
	        case RCC_AHB_CRC:
	            RCC->AHBENR &= ~RCC_AHBENR_CRCEN;
	            break;
	    }

}

void RCC_APB1EnableClock(RCC_APB1Periph peripheral){
	RCC->APB1ENR |= (1 << peripheral);
}

void RCC_APB1DisableClock(RCC_APB1Periph peripheral){
	RCC->APB1ENR &= ~(1 << peripheral);
}

void RCC_APB2EnableClock(RCC_APB2Periph peripheral){
	RCC->APB2ENR |= (1 << peripheral);
}

void RCC_APB2DisableClock(RCC_APB2Periph peripheral){
	RCC->APB2ENR &= ~(1 << peripheral);
}
