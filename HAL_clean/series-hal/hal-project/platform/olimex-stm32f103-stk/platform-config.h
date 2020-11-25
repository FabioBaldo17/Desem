#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#define TARGET_PLATFORM_OLIMEX_STM32F103_STK

#ifndef UNUSED
	#define UNUSED(x) (void)(x)
#endif

#define REM_FOR_STUDENTS	1

// ISR priorities starting from the highest urgency (Cortex-Mx specific)
enum ISR_Priorities
{
	TSM_PRIO,				/* TIM used for time slots */
    SYSTICK_PRIO,			/* Cortex System Tick Interrupt (SysTick_IRQn) */
    NRF24_PRIO,
    UART1_PRIO,
    UART2_PRIO,
    EXTI9_5_PRIO,
};

#define USE_TRACE				1		/* Enables/disables trace */
#define USE_USART2_TRACE		1		/* Use UART2 as output */
#define TRACE_FORMAT_LINUX		1		/* Set to one if the host is a Linux based OS */
#define TRACE_BUFFER_SIZE		256		/* Trace internal buffer size */

#define EXCLUDE_BOARD_NRFTRANSCEIVER 	1

#endif // PLATFORM_CONFIG_H
