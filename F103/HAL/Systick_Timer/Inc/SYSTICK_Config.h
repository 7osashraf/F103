#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

// Define the clock source options for the SysTick timer
#define SYSTICK_CLKSOURCE_INTERNAL   0x00000004  // Internal clock source (AHB)
#define SYSTICK_CLKSOURCE_EXTERNAL   0x00000000  // External clock source (AHB/8)

// Define whether to use SysTick interrupt
#define SYSTICK_ENABLE_INTERRUPT     1
#define SYSTICK_DISABLE_INTERRUPT    0

// Define the default clock source
#define SYSTICK_DEFAULT_CLKSOURCE    SYSTICK_CLKSOURCE_INTERNAL

#endif // SYSTICK_CONFIG_H
