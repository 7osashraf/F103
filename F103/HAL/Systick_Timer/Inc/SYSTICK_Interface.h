#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#include "SYSTICK_Config.h"

#include "stdint.h"

void SYSTICK_init(void);

void SYSTICK_delayMilliSeconds(uint32_t ms);
void SYSTICK_delayMicroSeconds(uint32_t us);

uint32_t SYSTICK_getRemainingTime(void);
uint32_t SYSTICK_getElapsedTime(void);

void SYSTICK_enableInterrupt(void);
void SYSTICK_startCountMillisecondsIT(uint32_t ms, void (*callback)(void));
void SYSTICK_startCountMicrosecondsIT(uint32_t us, void (*callback)(void));

#endif // SYSTICK_INTERFACE_H
