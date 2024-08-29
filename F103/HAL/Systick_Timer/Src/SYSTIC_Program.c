#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Registers.h"

static void (*systick_callback)(void) = 0;

void SYSTICK_init(void) {
	SYSTICK->LOAD = 0xFFFFFF;  // Maximum load value
    // Set the SysTick clock source
    SYSTICK->CTRL |= SYSTICK_DEFAULT_CLKSOURCE;
    // Reset the SysTick current value register
    SYSTICK->VAL = 0;
}

void SYSTICK_delayMilliSeconds(uint32_t ms) {

	uint32_t max_delay = 0xFFFFFF / (SystemCoreClock / 1000);

	while (ms > max_delay) {
    SYSTICK->LOAD = max_delay * (SystemCoreClock / 1000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL |= 0x01;  // Enable SysTick

    while (!(SYSTICK->CTRL & (1 << 16)));

    SYSTICK->CTRL &= ~(0x01);  // Disable SysTick
    ms -= max_delay;
	}

	SYSTICK->LOAD = ms * (SystemCoreClock / 1000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL |= 0x01;  // Enable SysTick

    while (!(SYSTICK->CTRL & (1 << 16)));

    SYSTICK->CTRL &= ~(0x01);  // Disable SysTick
}

void SYSTICK_delayMicroSeconds(uint32_t us) {

    uint32_t max_delay = 0xFFFFFF / (SystemCoreClock / 1000000);

    while (us > max_delay) {
        SYSTICK->LOAD = max_delay * (SystemCoreClock / 1000000) - 1;
        SYSTICK->VAL = 0;
        SYSTICK->CTRL |= 0x01;  // Enable SysTick

        while (!(SYSTICK->CTRL & (1 << 16)));

        SYSTICK->CTRL &= ~(0x01);  // Disable SysTick
        us -= max_delay;
    }

    SYSTICK->LOAD = us * (SystemCoreClock / 1000000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL |= 0x01;  // Enable SysTick

    while (!(SYSTICK->CTRL & (1 << 16)));

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
