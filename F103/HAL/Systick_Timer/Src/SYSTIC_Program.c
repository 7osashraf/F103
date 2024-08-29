#include "SYSTICK_Interface.h"
#include "SYSTICK_Registers.h"

static void (*systick_callback)(void) = 0;

void SYSTICK_init(void) {
    // Load the SysTick Reload value register
    SYSTICK->LOAD = 0xFFFFFF;  // Maximum load value
    // Set the SysTick clock source
    SYSTICK->CTRL = SYSTICK_DEFAULT_CLKSOURCE;
    // Reset the SysTick current value register
    SYSTICK->VAL = 0;
    // Enable the SysTick counter
    SYSTICK->CTRL |= 0x01;
}

void SYSTICK_delayMilliSeconds(uint32_t ms) {
	// value of reload register
    SYSTICK->LOAD = ms * (SystemCoreClock / 1000) - 1;
    SYSTICK->VAL = 0;
	
	// Start the counter
    SYSTICK->CTRL |= 0x01;  // Enable SysTick

    while (!(SYSTICK->CTRL & (1 << 16)));  // Wait until the COUNTFLAG is set
	
	SYSTICK->CTRL &= ~(0x01);  // Disable SysTick
}

void SYSTICK_delayMicroSeconds(uint32_t us) {
    SYSTICK->LOAD = us * (SystemCoreClock / 1000000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL |= 0x01;  // Enable SysTick

    while (!(SYSTICK->CTRL & (1 << 16)));  // Wait until the COUNTFLAG is set
	
	SYSTICK->CTRL &= ~(0x01);  // Disable SysTick
}

uint32_t SYSTICK_getRemainingTime(void) {
    return SYSTICK->VAL;
}

uint32_t SYSTICK_getElapsedTime(void) {
    return SYSTICK->LOAD - SYSTICK->VAL;
}

void SYSTICK_enableInterrupt(void) {
    SYSTICK->CTRL |= (1 << 1);  // Enable SysTick interrupt
}

void SYSTICK_startCountMillisecondsIT(uint32_t ms, void (*callback)(void)) {
    systick_callback = callback;
    SYSTICK->LOAD = ms * (SystemCoreClock / 1000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK_enableInterrupt();
    SYSTICK->CTRL |= 0x01;  // Enable SysTick
}

void SYSTICK_startCountMicrosecondsIT(uint32_t us, void (*callback)(void)) {
    systick_callback = callback;
    SYSTICK->LOAD = us * (SystemCoreClock / 1000000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK_enableInterrupt();
    SYSTICK->CTRL |= 0x01;  // Enable SysTick
}

void SysTick_Handler(void) {
    if (systick_callback) {
        systick_callback();
    }
}
