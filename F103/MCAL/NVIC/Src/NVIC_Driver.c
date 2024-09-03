#include "NVIC_Driver.h"
#include "STM32F103C8T6.h"

/************************   SCB Peripheral Definition   ************************/
#define SCB ((SCB_RegDef_t*)SCB_BASE_ADDRESS)
/************************   NVIC Peripheral Definition   ************************/
#define NVIC ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/**
 * @brief  Enables the interrupt for a given IRQ number.
 * @param  IRQNumber: IRQ number to be enabled.
 */
uint8_t NVIC_EnableIRQ(uint8_t IRQNumber) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    NVIC->ISER[IRQNumber >> 5] = (1 << (IRQNumber & 0x1F));
    return OK;
}

/**
 * @brief  Disables the interrupt for a given IRQ number.
 * @param  IRQNumber: IRQ number to be disabled.
 */
uint8_t NVIC_DisableIRQ(uint8_t IRQNumber) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    NVIC->ICER[IRQNumber >> 5] = (1 << (IRQNumber & 0x1F));
    return OK;
}

/**
 * @brief  Sets the pending flag for a given IRQ number.
 * @param  IRQNumber: IRQ number for which the pending flag will be set.
 */
uint8_t NVIC_SetPendingFlag(uint8_t IRQNumber) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    NVIC->ISPR[IRQNumber >> 5] = (1 << (IRQNumber & 0x1F));
    return OK;
}

/**
 * @brief  Clears the pending flag for a given IRQ number.
 * @param  IRQNumber: IRQ number for which the pending flag will be cleared.
 */
uint8_t NVIC_ClearPendingFlag(uint8_t IRQNumber) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    NVIC->ICPR[IRQNumber >> 5] = (1 << (IRQNumber & 0x1F));
    return OK;
}

/**
 * @brief  Gets the active flag status for a given IRQ number.
 * @param  IRQNumber: IRQ number for which the active flag status will be retrieved.
 * @retval 1 if the IRQ is active, 0 otherwise.
 */
uint8_t NVIC_GetActiveFlag(uint8_t IRQNumber, uint8_t *activeFlag) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    if (activeFlag == NULL) {
        return NULL_PTR_ERR;  // Null pointer error
    }

    *activeFlag = (NVIC->IABR[IRQNumber >> 5] & (1 << (IRQNumber & 0x1F))) ? 1 : 0;
    return OK;
}

/**
 * @brief  Sets the priority grouping in the SCB AIRCR register.
 * @param  PriorityGroup: Priority group to be set (0-7).
 *         0: 7 bits for pre-emption priority, 1 bit for subpriority
 *         1: 6 bits for pre-emption priority, 2 bits for subpriority
 *         ...
 *         7: 0 bits for pre-emption priority, 8 bits for subpriority
 */
uint8_t SCB_voidSetPriorityGroup(uint8_t PriorityGroup) {
    if (PriorityGroup > 7) {
        return NOK;  // Invalid Priority Group
    }

    uint32_t temp = SCB->AIRCR;
    temp &= ~(0xFFFF0700);  // Clear VECTKEY and PRIGROUP fields
    temp |= (0x5FA << 16) | (PriorityGroup << 8);  // Write VECTKEY (0x5FA) and PRIGROUP
    SCB->AIRCR = temp;

    return OK;
}

/**
 * @brief  Sets the priority of a specific IRQ.
 * @param  IRQNumber: IRQ number for which the priority is to be set.
 * @param  priority: Priority value to be assigned (0-15).
 */
uint8_t NVIC_voidSetIRQPriority(uint8_t IRQNumber, uint8_t priority) {
    if (IRQNumber >= 240) {
        return NOK;  // Invalid IRQ number
    }

    if (priority > 15) {
        return NOK;  // Invalid priority value
    }

    NVIC->IP[IRQNumber] = (priority << 4);  // Lower 4 bits are reserved, so shift left by 4
    return OK;
}
