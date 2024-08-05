/***********************************
 *  @file GPIO_prog.c
 *  @author Hosam Ashraf
 *  @brief The GPIO main source file, including functions' definitions
 *
 * */


#include <stdint.h>
#include <stdio.h>
#include "Stm32F103C8T6.h"
#include "ErrType.h"

#include "GPIO_interface.h"
#include "GPIO_prv.h"
/************************   Function Implementations   ************************/
/**
 * @fn GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @param[in] PinConfig : the initialization values of the pin
 * @retval ErrorStatus : OK if initialization is successful, NOK otherwise
 * */
uint8_t GPIO_u8PinInit(const PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrorState = OK;
	// Pointer to the GPIO port base address
	GPIO_RegDef_t* GPIOx;

	if(PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTG) && (PinConfig->Pin <= PIN15))
		{
			// Select the GPIO port base address
			switch (PinConfig->Port)
			{
			case PORTA: GPIOx = GPIOA; break;
			case PORTB: GPIOx = GPIOB; break;
			case PORTC: GPIOx = GPIOC; break;
			case PORTD: GPIOx = GPIOD; break;
			case PORTE: GPIOx = GPIOE; break;
			case PORTF: GPIOx = GPIOF; break;
			case PORTG: GPIOx = GPIOG; break;
			default: return NOK; // Invalid port
			}


			// Calculate the register (CRL or CRH) and the position of the pin
			volatile uint32_t* configRegister;
			uint8_t pinPosition;
			if (PinConfig->Pin < 8)
			{
				configRegister = &GPIOx->CRL;
				pinPosition = PinConfig->Pin * 4;
			}
			else
			{
				configRegister = &GPIOx->CRH;
				pinPosition = (PinConfig->Pin - 8) * 4;
			}

			// Configure the mode and speed/type/pull-up configuration
			*configRegister &= ~(0xF << pinPosition); // Clear the existing configuration
			*configRegister |= 	((PinConfig->Mode & 0x3) << pinPosition) |
								((PinConfig->Speed & 0x3) << pinPosition) |
								((PinConfig->OutputType & 0x1) << (pinPosition + 2)) |
								((PinConfig->Pull & 0x1) << (pinPosition + 2));

		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	


    return Local_u8ErrorState;
	
	
}


/**
 * @fn GPIO_u8SetPinValue
 * @brief Sets the value of a specified pin (high or low)
 * @param[in] Port : the GPIO port
 * @param[in] PinNum : the pin number
 * @param[in] PinVal : the value to set (high or low)
 * @retval ErrorStatus : OK if the operation is successful, NOK otherwise
 */
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	GPIO_RegDef_t* GPIOx;
	if ((Port <= PORTG) && (PinNum <= 15))
	{

		switch (Port)
		{
		case PORTA: GPIOx = GPIOA; break;
		case PORTB: GPIOx = GPIOB; break;
		case PORTC: GPIOx = GPIOC; break;
		case PORTD: GPIOx = GPIOD; break;
		case PORTE: GPIOx = GPIOE; break;
		case PORTF: GPIOx = GPIOF; break;
		case PORTG: GPIOx = GPIOG; break;
		default: return NOK; // Invalid port
		}

	    if (PinVal == PIN_HIGH)
	    {
	    	GPIOx->BSRR = (1 << PinNum); // Set the pin
		}
	    else if(PinVal == PIN_LOW)
	    {
	    	GPIOx->BRR = (1 << PinNum); // Reset the pin
		}
	    else
	    {
	    	Local_u8ErrorState = NOK;
	    }
	}
	else
	{
		Local_u8ErrorState = NOK;
	}


    return Local_u8ErrorState;
}

/**
 * @fn GPIO_u8TogglePinValue
 * @brief Toggles the current value of a specified pin
 * @param[in] Port : the GPIO port
 * @param[in] PinNum : the pin number
 * @retval ErrorStatus : OK if the operation is successful, NOK otherwise
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{

	uint8_t Local_u8ErrorState = OK;
		if((Port <= PORTG) && (PinNum <= 15))
		{
			GPIO_RegDef_t* GPIOx;

			switch (Port)
			{
			case PORTA: GPIOx = GPIOA; break;
			case PORTB: GPIOx = GPIOB; break;
			case PORTC: GPIOx = GPIOC; break;
			case PORTD: GPIOx = GPIOD; break;
			case PORTE: GPIOx = GPIOE; break;
			case PORTF: GPIOx = GPIOF; break;
			case PORTG: GPIOx = GPIOG; break;
			default: return 1; // Invalid port
			}

			GPIOx->ODR ^= (1 << PinNum); // Toggle the pin value
		}
		else
		{
			Local_u8ErrorState = NOK;;
		}

    return Local_u8ErrorState;
}

/**
 * @fn GPIO_u8ReadPinValue
 * @brief Reads the current value of a specified pin
 * @param[in] Port : the GPIO port
 * @param[in] PinNum : the pin number
 * @param[out] PinVal : pointer to store the pin value (high or low)
 * @retval ErrorStatus : OK if the operation is successful, NOK otherwise
 */
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal)
{

	uint8_t Local_u8ErrorState = OK;
		if((Port <= PORTG) && (PinNum <= 15))
		{
			GPIO_RegDef_t* GPIOx;

			switch (Port)
			{
				case PORTA: GPIOx = GPIOA; break;
				case PORTB: GPIOx = GPIOB; break;
				case PORTC: GPIOx = GPIOC; break;
				case PORTD: GPIOx = GPIOD; break;
				case PORTE: GPIOx = GPIOE; break;
				case PORTF: GPIOx = GPIOF; break;
				case PORTG: GPIOx = GPIOG; break;
				default: return 1; // Invalid port
			}

			*PinVal = (GPIOx->IDR & (1 << PinNum)) ? PIN_HIGH : PIN_LOW;
		}
		else
		{
			Local_u8ErrorState = NOK;;
		}



    return Local_u8ErrorState; // Success
}
