#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "Stm32F103C8T6.h"

typedef enum
{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG
}Port_t;

typedef enum
{
	PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
}Pin_t;


typedef enum
{
	INPUT_ANALOG = 0x0,
    INPUT_FLOATING = 0x4,
    INPUT_PU_PD = 0x8,
    OUTPUT_PP = 0x0,
    OUTPUT_OD = 0x4,
    OUTPUT_AF_PP = 0x8,
    OUTPUT_AF_OD = 0xC
}Mode_t;

typedef enum
{
	SPEED_10MHZ = 1,
    SPEED_2MHZ,
    SPEED_50MHZ
}OutputSpeed_t;


typedef enum
{
	PUSH_PULL = 0,
    OPEN_DRAIN
}OutputType_t;

typedef enum
{
	NO_PULL = 0,
    PULL_UP,
    PULL_DOWN
}PullUpDown_t;

typedef enum
{
	PIN_LOW = 0,
    PIN_HIGH
}PinVal_t;

typedef enum
{
	AF0 = 0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7
}AltFunc_t;

typedef struct
{
	Port_t Port;               // Port (A, B, C, etc.)
    Pin_t Pin;                 // Pin number (0-15)
    Mode_t Mode;               // Mode (input/output/alternate function)
    OutputSpeed_t Speed;       // Output speed (10MHz, 2MHz, 50MHz)
    OutputType_t OutputType;   // Output type (push-pull, open-drain)
    PullUpDown_t Pull;         // Pull-up/pull-down configuration
    AltFunc_t AltFunc;         // Alternate function (if any)
} PinConfig_t;

uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig);

uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum);

uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal);

#endif
