#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../util/std_types.h"
#include "../../util/bit_math.h"
#include "../../MCAL/DIO/dio.h"
#include "CLCD_int.h"
#include "CLCD_cofig.h"

static void SendEnablePulse(){
		/* E high ,, delay ,, LOW */
		DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_PIN_LOW);
} 
static void SetHalfPort(u8 Copy_u8data){
	DIO_voidSetPinVal(CLCD_DATA_PORT,CLCD_DATA_PIN0,GET_BIT(Copy_u8data,0));
	DIO_voidSetPinVal(CLCD_DATA_PORT,CLCD_DATA_PIN1,GET_BIT(Copy_u8data,1));
	DIO_voidSetPinVal(CLCD_DATA_PORT,CLCD_DATA_PIN2,GET_BIT(Copy_u8data,2));
	DIO_voidSetPinVal(CLCD_DATA_PORT,CLCD_DATA_PIN3,GET_BIT(Copy_u8data,3));
	
}
void CLCD_voidInit(){
	/* DATA port OUTPUT */
	DIO_voidSetPortDir(CLCD_DATA_PORT,DIO_PORT_OUTPUT);
	/*RS,RW,E output */
	DIO_voidSetPinDir(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_PIN_OUTPUT);
	
	/*initialzation sequence */
	
	/* 1. wait for 40ms */
	_delay_ms(40);
	
	#if CLCD_MODE == CLCD_8_BIT
	/* 2. send Function Set Command 0b00111000 */
	CLCD_voidSendCommand(0b00111000);
	#elif CLCD_MODE == CLCD_4_BIT
		SetHalfPort(0b0010);
		SendEnablePulse();
		SetHalfPort(0b0010);
		SendEnablePulse();
		SetHalfPort(0b1000);
		SendEnablePulse();
	#else
	
	#endif
	/* 3. Send Command on/off Control 0b00001111*/
	CLCD_voidSendCommand(0b00001111);
	/* 4. Send Clear 1*/
	CLCD_voidSendCommand(1);
}
void CLCD_voidSendData(u8 Copy_u8Data){

	/*r/w ===> LOW */
	DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_LOW);
	/* R/S ======> High */ 
	DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_HIGH);
	
	
	#if CLCD_MODE == CLCD_8_BIT
		/*put data on data port */
		DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Data);
		SendEnablePulse();
	#elif CLCD_MODE == CLCD_4_BIT
	SetHalfPort(Copy_u8Data>>4);
	SendEnablePulse();
	SetHalfPort(Copy_u8Data);
	SendEnablePulse();
	#else 
	
	#endif
}
void CLCD_voidSendCommand(u8 Copy_u8Com){

	/*r/w ===> LOW */
	DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_LOW);
	/* R/S ======> High */
	DIO_voidSetPinVal(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_LOW);
		#if CLCD_MODE == CLCD_8_BIT
		/*put data on data port */
	DIO_voidSetPortVal(CLCD_DATA_PORT,Copy_u8Com);
		SendEnablePulse();
	#elif CLCD_MODE == CLCD_4_BIT
		SetHalfPort(Copy_u8Com>>4);
		SendEnablePulse();
		SetHalfPort(Copy_u8Com);
		SendEnablePulse();
		#else
		
		#endif
}
void CLCD_voidSendString(u8 * Copy_pu8str){
	while(*Copy_pu8str!='\0'){
		CLCD_voidSendData(*Copy_pu8str++);
	}
}



void CLCD_voidClearDisplay(){
	CLCD_voidSendCommand(1);
}
void CLCD_voidSetCursorPosition(u8 Copy_u8x, u8 Copy_u8y){
	u8 address = Copy_u8x+(Copy_u8y*0x40);
	SET_BIT(address,7);
	CLCD_voidSendCommand(address);
}

void CLCD_voidSenSpecialChar(u8 * Copy_pu8array, u8 Copy_u8Index, u8 Copy_u8x,u8 Copy_u8y){
	u8 address = (Copy_u8Index * 8);
	SET_BIT(address,6);
	CLCD_voidSendCommand(address);
	for(u8 i = 0 ; i<8;i++){
		CLCD_voidSendData(Copy_pu8array[i]);
	}
	CLCD_voidSetCursorPosition(Copy_u8x,Copy_u8y);
	CLCD_voidSendData(Copy_u8Index);
}