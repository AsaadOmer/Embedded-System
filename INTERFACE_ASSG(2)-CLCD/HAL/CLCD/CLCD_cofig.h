/*
 * CLCD_cofig.h
 *
 * Created: 5/13/2026 9:23:19 PM
 *  Author: Eslam El Hefny
 */ 


#ifndef CLCD_COFIG_H_
#define CLCD_COFIG_H_
#define CLCD_4_BIT	0
#define CLCD_8_BIT	1

#define CLCD_MODE		CLCD_4_BIT       

#define CLCD_DATA_PORT	DIO_PORTA
#if CLCD_MODE == CLCD_4_BIT
#define CLCD_DATA_PIN0	DIO_PIN4
#define CLCD_DATA_PIN1	DIO_PIN5
#define CLCD_DATA_PIN2	DIO_PIN6
#define CLCD_DATA_PIN3	DIO_PIN7


#endif 

#define CLCD_CTRL_PORT  DIO_PORTB

#define CLCD_RS_PIN		DIO_PIN1
#define CLCD_E_PIN		DIO_PIN2
#define CLCD_RW_PIN		DIO_PIN0




#endif /* CLCD_COFIG_H_ */