#ifndef SYSTICK_REGISTERS_H
#define SYSTICK_REGISTERS_H

#include <stdint.h>

#define SYSTICK_BASE_ADDR    0xE000E010

typedef struct {
    volatile uint32_t CTRL;   // SysTick Control and Status Register
    volatile uint32_t LOAD;   // SysTick Reload Value Register
    volatile uint32_t VAL;    // SysTick Current Value Register
    volatile uint32_t CALIB;  // SysTick Calibration Value Register
} SYSTICK_RegDef_t;

#define SYSTICK              ((SYSTICK_RegDef_t *) SYSTICK_BASE_ADDR)

#endif // SYSTICK_REGISTERS_H
