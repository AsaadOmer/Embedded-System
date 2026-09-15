#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#include "util/std_types.h"
#include "util/bit_math.h"

#include "MCAL/DIO/dio.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/GIEE/GIE.h"

/* Configuration Pins for LEDs */
#define LED1_PORT   DIO_PORTA
#define LED1_PIN    DIO_PIN0

#define LED2_PORT   DIO_PORTA
#define LED2_PIN    DIO_PIN1

#define LED3_PORT   DIO_PORTA
#define LED3_PIN    DIO_PIN2

/* Counter variable to hold active LEDs count (0 to 3) */
volatile u8 g_u8LedCount = 0;

/* Function to update LEDs status based on g_u8LedCount */
void Update_Leds(void)
{
	switch (g_u8LedCount)
	{
		case 0:
		DIO_voidSetPinVal(LED1_PORT, LED1_PIN, DIO_PIN_LOW);
		DIO_voidSetPinVal(LED2_PORT, LED2_PIN, DIO_PIN_LOW);
		DIO_voidSetPinVal(LED3_PORT, LED3_PIN, DIO_PIN_LOW);
		break;
		case 1:
		DIO_voidSetPinVal(LED1_PORT, LED1_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinVal(LED2_PORT, LED2_PIN, DIO_PIN_LOW);
		DIO_voidSetPinVal(LED3_PORT, LED3_PIN, DIO_PIN_LOW);
		break;
		case 2:
		DIO_voidSetPinVal(LED1_PORT, LED1_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinVal(LED2_PORT, LED2_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinVal(LED3_PORT, LED3_PIN, DIO_PIN_LOW);
		break;
		case 3:
		DIO_voidSetPinVal(LED1_PORT, LED1_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinVal(LED2_PORT, LED2_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinVal(LED3_PORT, LED3_PIN, DIO_PIN_HIGH);
		break;
	}
}

/* ISR for Push Button 1 (Increase) -> INT0 (PD2) */
ISR(INT0_vect)
{
	if (g_u8LedCount < 3)
	{
		g_u8LedCount++;
	}
}

/* ISR for Push Button 2 (Decrease) -> INT1 (PD3) */
ISR(INT1_vect)
{
	if (g_u8LedCount > 0)
	{
		g_u8LedCount--;
	}
}

int main(void)
{
	/* 1. Set LEDs Pins as Output */
	DIO_voidSetPinDir(LED1_PORT, LED1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(LED2_PORT, LED2_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(LED3_PORT, LED3_PIN, DIO_PIN_OUTPUT);

	/* Initial State: All Off */
	Update_Leds();

	/* 2. Set INT0 (PD2) & INT1 (PD3) Pins as Inputs */
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);

	/* 3. Configure EXTI Sense Control to Rising Edge */
	EXTINT_voidChangeSenseControl(EXTINT_INT0, EXTINT_rising);
	EXTINT_voidChangeSenseControl(EXTINT_INT1, EXTINT_rising);

	/* 4. Enable External Interrupts INT0 & INT1 */
	Enable_INT0();
	Enable_INT1();

	/* 5. Enable Global Interrupt */
	GIE_voidEnableGlobalInterrupt();

	while (1)
	{
		Update_Leds();
	}
}