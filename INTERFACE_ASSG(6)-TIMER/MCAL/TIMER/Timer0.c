#include"../../util/std_types.h"
#include"../../util/bit_math.h"
#include"../register_def.h"
#include"Timer0.h"
void (*OVpfn)(void)=NULL;

void TIMER0_voidInit(u8 Copy_u8PreScaler){
	/* Select prescalar */
	TIMER_TCCR0_REG &= 0xf8;
	TIMER_TCCR0_REG |= Copy_u8PreScaler;
	
	/* Select Fast PWM Mode: WGM00 = 1, WGM01 = 1 */
	SET_BIT(TIMER_TCCR0_REG, TIMER_TCCR0_WGM00);
	SET_BIT(TIMER_TCCR0_REG, TIMER_TCCR0_WGM01);

	/* Select Non-Inverting Mode: COM01 = 1, COM00 = 0 */
	SET_BIT(TIMER_TCCR0_REG, TIMER_TCCR0_COM01);
	CLR_BIT(TIMER_TCCR0_REG, TIMER_TCCR0_COM00);
}

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8CompareValue){
	TIMER_OCR0_REG = Copy_u8CompareValue;
}
void TIMER0_voidSetPrescalar(u8 Copy_u8PreScaler){
		/* Select prescalar */
		TIMER_TCCR0_REG &= 0xf8;
		TIMER_TCCR0_REG |= Copy_u8PreScaler;
}
void TIMER0_voidDisable(){
	TIMER_TCCR0_REG &= 0xf8;
}
void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload){
	TIMER_TCNT0_REG = Copy_u8Preload;
}

void TIMER0_voidOverFlowCallBack(void (*pfn)(void)){
	OVpfn=pfn;
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
OVpfn();
}