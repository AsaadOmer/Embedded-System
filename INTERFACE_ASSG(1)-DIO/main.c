#define F_CPU 16000000UL 
#include <util/delay.h>

#include "util/std_types.h"
#include "util/bit_math.h"

#include "MCAL/DIO/dio.h"

int main(void)
{
    //    Pin (PIN0 ?? PORTA) = OUTPUT
    DIO_voidSetPinDir(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);

    while (1)
    {
       
         // Way 1: Blinking using Set Pin & Clear Pin (Bitwise OR & AND)
        
        for (u8 i = 0; i < 5; i++) // ????? 5 ????
        {
            DIO_voidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH); // Turn ON (Bitwise OR)
            _delay_ms(500);
            DIO_voidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_PIN_LOW);  // Turn OFF (Bitwise AND)
            _delay_ms(500);
        }

        _delay_ms(1000); // ???? ???? ??? ?????????

        
         // Way 2: Blinking using Toggle Pin (Bitwise XOR)
        
        for (u8 i = 0; i < 10; i++) // ????? 10 ??????? (5 ???? ON/OFF)
        {
            DIO_togglePin(DIO_PORTA, DIO_PIN0); // Toggle state (Bitwise XOR)
            _delay_ms(500);
        }

        _delay_ms(1000); //??? ???? ??? ????? ?? Loop ????????
    }

    return 0;
}