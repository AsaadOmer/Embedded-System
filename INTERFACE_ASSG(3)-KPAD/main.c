#define F_CPU 16000000UL
#include <util/delay.h>

#include "util/std_types.h"
#include "util/bit_math.h"

#include "MCAL/DIO/dio.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/KPAD/KPAD.h"

int main(void)
{
	/* Initialize Peripherals */
	CLCD_voidInit();
	KPAD_voidInit();

	u8 local_u8Key = 255;
	
	/* Explicitly use 32-bit signed long integers */
	signed long int local_s32Num1 = 0;
	signed long int local_s32Num2 = 0;
	signed long int local_s32Result = 0;
	
	u8 local_u8Op = 0;
	u8 local_u8State = 0; /* 0: Entering Num1, 1: Entering Num2, 2: Result Done */

	CLCD_voidSendString((u8 *)"Calculator Ready");
	_delay_ms(1000);
	CLCD_voidClearDisplay();

	while (1)
	{
		local_u8Key = KPAD_u8GetKeyPressed();

		if (local_u8Key != 255)
		{
			if (local_u8Key == 'C')
			{
				local_u8State = 0;
				local_s32Num1 = 0;
				local_s32Num2 = 0;
				local_u8Op = 0;
				CLCD_voidClearDisplay();
			}
			else
			{
				if (local_u8Key >= '0' && local_u8Key <= '9')
				{
					if (local_u8State == 0)
					{
						local_s32Num1 = (local_s32Num1 * 10L) + (local_u8Key - '0');
						CLCD_voidSendData(local_u8Key);
					}
					else if (local_u8State == 1)
					{
						local_s32Num2 = (local_s32Num2 * 10L) + (local_u8Key - '0');
						CLCD_voidSendData(local_u8Key);
					}
				}
				else if (local_u8Key == '+' || local_u8Key == '-' || local_u8Key == '*' || local_u8Key == '/')
				{
					if (local_u8State == 0)
					{
						local_u8Op = local_u8Key;
						CLCD_voidSendData(local_u8Key);
						local_u8State = 1;
					}
				}
				else if (local_u8Key == '=')
				{
					if (local_u8State == 1)
					{
						CLCD_voidSendData('=');
						
						u8 local_u8ErrorFlag = 0;
						switch (local_u8Op)
						{
							case '+': local_s32Result = local_s32Num1 + local_s32Num2; break;
							case '-': local_s32Result = local_s32Num1 - local_s32Num2; break;
							case '*': local_s32Result = local_s32Num1 * local_s32Num2; break;
							case '/':
							if (local_s32Num2 != 0)
							{
								local_s32Result = local_s32Num1 / local_s32Num2;
							}
							else
							{
								local_u8ErrorFlag = 1;
							}
							break;
						}

						CLCD_voidSetCursorPosition(0, 1);

						if (local_u8ErrorFlag == 1)
						{
							CLCD_voidSendString((u8 *)"Error: Div by 0");
						}
						else
						{
							if (local_s32Result < 0)
							{
								CLCD_voidSendData('-');
								local_s32Result = -local_s32Result;
							}
							
							if (local_s32Result == 0)
							{
								CLCD_voidSendData('0');
							}
							else
							{
								u8 buffer[12];
								s8 i = 0;
								while (local_s32Result > 0)
								{
									buffer[i++] = (local_s32Result % 10) + '0';
									local_s32Result /= 10;
								}
								while (--i >= 0)
								{
									CLCD_voidSendData(buffer[i]);
								}
							}
						}

						local_u8State = 2;
					}
				}
			}

			_delay_ms(250);
		}
	}
}