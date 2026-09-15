/*
 * CLCD_int.h
 *
 * Created: 5/13/2026 9:08:43 PM
 *  Author: Eslam El Hefny
 */ 


#ifndef CLCD_INT_H_
#define CLCD_INT_H_


void CLCD_voidInit();
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Com);
void CLCD_voidSendString(u8 * Copy_pu8str);
void CLCD_voidSetCursorPosition(u8 Copy_u8x, u8 Copy_u8y);
void CLCD_voidClearDisplay();
void CLCD_voidSenSpecialChar(u8 * Copy_pu8array, u8 Copy_u8Index, u8 Copy_u8x,u8 Copy_u8y);
#endif /* CLCD_INT_H_ */