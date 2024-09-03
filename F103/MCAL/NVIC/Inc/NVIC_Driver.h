#ifndef NVIC_DRIVER_H
#define NVIC_DRIVER_H

#include <stdint.h>
#include "ErrType.h"

/************************   Function Prototypes   ************************/

uint8_t NVIC_EnableIRQ(uint8_t IRQNumber);
uint8_t NVIC_DisableIRQ(uint8_t IRQNumber);
uint8_t NVIC_SetPendingFlag(uint8_t IRQNumber);
uint8_t NVIC_ClearPendingFlag(uint8_t IRQNumber);
uint8_t NVIC_GetActiveFlag(uint8_t IRQNumber, uint8_t *activeFlag);
uint8_t SCB_voidSetPriorityGroup(uint8_t PriorityGroup);
uint8_t NVIC_voidSetIRQPriority(uint8_t IRQNumber, uint8_t priority);

#endif // NVIC_DRIVER_H
