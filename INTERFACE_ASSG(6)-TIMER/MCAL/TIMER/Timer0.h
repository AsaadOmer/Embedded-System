/*
 * Timer0.h
 *
 * Created: 6/24/2026 10:18:00 PM
 *  Author: Eslam El Hefny
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define TIMER0_DISABLE			0
#define TIMER0_1_PRESCALAR		1
#define TIMER0_8_PRESCALAR		2
#define TIMER0_64_PRESCALAR		3
#define TIMER0_256_PRESCALAR	4
#define TIMER0_1024_PRESCALAR	5
#define TIMER0_EXT_FALLING		6
#define TIMER0_EXT_RISING		7
void TIMER0_voidInit(u8 Copy_u8PreScaler);
void TIMER0_voidSetPrescalar(u8 Copy_u8PreScaler);
void TIMER0_voidDisable();
void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload);
void TIMER0_voidOverFlowCallBack(void (*pfn)(void));
void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareValue);

#endif /* TIMER0_H_ */