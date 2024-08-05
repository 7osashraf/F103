#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H


// RCC Base Address
#define RCC_BASE_ADDRESS	0x40021000

// RCC Register Map
typedef struct {
	uint32_t CR;		//Clock Control Register
	uint32_t CFGR;		//Clock configuration register
	uint32_t CIR;		//Clock interrupt register
	uint32_t APB2RSTR;	//APB2 peripheral reset register
	uint32_t APB1RSTR;	//APB1 peripheral reset register
	uint32_t AHBENR;	//AHB peripheral clock enable register
	uint32_t APB2ENR;	//APB2 peripheral clock enable register
	uint32_t APB1ENR;	//APB1 peripheral clock enable register
	uint32_t BDCR;		//Backup domain control register
	uint32_t CSR;		//Control/status register

} RCC_Reg_t;

//RCC Base Address
RCC_Reg_t *RCC = (RCC_Reg_t *)(RCC_BASE_ADDRESS);


// RCC_CR Register Bit Masks
#define RCC_CR_HSION        (1 << 0)
#define RCC_CR_HSIRDY       (1 << 1)
#define RCC_CR_HSEON        (1 << 16)
#define RCC_CR_HSERDY       (1 << 17)
#define RCC_CR_PLLON        (1 << 24)
#define RCC_CR_PLLRDY       (1 << 25)

// RCC_CFGR Register Bit Masks
#define RCC_CFGR_SW         (3 << 0)
#define RCC_CFGR_SW_HSI     (0 << 0)
#define RCC_CFGR_SW_HSE     (1 << 0)
#define RCC_CFGR_SW_PLL     (2 << 0)

#define RCC_CFGR_PLLSRC     (1 << 16)
#define RCC_CFGR_PLLXTPRE   (1 << 17)
#define RCC_CFGR_PLLMULL    (0xF << 18)


// RCC_CFGR Register Bit Masks for PLL Source
#define RCC_CFGR_PLLSRC_HSI_DIV2    (0x00000000) // HSI clock divided by 2 selected as PLL entry clock source
#define RCC_CFGR_PLLSRC_HSE         (0x00010000) // HSE clock selected as PLL entry clock source

// RCC_AHBENR Register Bit Masks
#define RCC_AHBENR_DMA1EN   (1 << 0)
#define RCC_AHBENR_DMA2EN   (1 << 1)
#define RCC_AHBENR_SRAMEN   (1 << 2)
#define RCC_AHBENR_FLITFEN  (1 << 4)
#define RCC_AHBENR_CRCEN    (1 << 6)




#endif //RCC_REGISTER_H
