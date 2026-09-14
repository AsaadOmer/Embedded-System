#include "../../UTIL/bit_math.h"
#include "../../UTIL/std_types.h"
#include "../register_def.h"
#include "dio.h"

void DIO_voidSetPinDir(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Dir)
{
	if (Copy_u8PinID <= DIO_PIN7)
	{
		
		if (Copy_u8Dir == DIO_PIN_OUTPUT)
		{
			switch (Copy_u8PortID)
			{
				case DIO_PORTA : SET_BIT(DDRA_REG,Copy_u8PinID);break;
				case DIO_PORTB : SET_BIT(DDRB_REG,Copy_u8PinID);break;
				case DIO_PORTC : SET_BIT(DDRC_REG,Copy_u8PinID);break;
				case DIO_PORTD : SET_BIT(DDRD_REG,Copy_u8PinID);break;
				default : break;
				
			}
		}
		else if(Copy_u8Dir == DIO_PIN_INPUT)
		{
			switch (Copy_u8PortID)
			{
				case DIO_PORTA : CLR_BIT(DDRA_REG,Copy_u8PinID);break;
				case DIO_PORTB : CLR_BIT(DDRB_REG,Copy_u8PinID);break;
				case DIO_PORTC : CLR_BIT(DDRC_REG,Copy_u8PinID);break;
				case DIO_PORTD : CLR_BIT(DDRD_REG,Copy_u8PinID);break;
				
				default : break;
				
			}
		}
		else
		{
			//error
		}
	}
	else{
		//error
	}
	
}
void DIO_voidSetPinVal(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Val)
{
	
	if (Copy_u8PinID <= DIO_PIN7)
	{
		
		if (Copy_u8Val == DIO_PIN_HIGH)
		{
			switch (Copy_u8PortID)
			{
				case DIO_PORTA : SET_BIT(PORTA_REG,Copy_u8PinID);break;
				case DIO_PORTB : SET_BIT(PORTB_REG,Copy_u8PinID);break;
				case DIO_PORTC : SET_BIT(PORTC_REG,Copy_u8PinID);break;
				case DIO_PORTD : SET_BIT(PORTD_REG,Copy_u8PinID);break;
				default : break;
				
			}
		}
		else if(Copy_u8Val == DIO_PIN_LOW)
		{
			switch (Copy_u8PortID)
			{
				case DIO_PORTA : CLR_BIT(PORTA_REG,Copy_u8PinID);break;
				case DIO_PORTB : CLR_BIT(PORTB_REG,Copy_u8PinID);break;
				case DIO_PORTC : CLR_BIT(PORTC_REG,Copy_u8PinID);break;
				case DIO_PORTD : CLR_BIT(PORTD_REG,Copy_u8PinID);break;
				
				default : break;
				
			}
		}
		else
		{
			//error
		}
	}
	else{
		//error
	}
}

void DIO_voidSetPortDir(u8 Copy_u8PortID, u8 Copy_u8Dir) {
	switch (Copy_u8PortID){
		
		case DIO_PORTA: DDRA_REG = Copy_u8Dir; break ;
		case DIO_PORTB: DDRB_REG = Copy_u8Dir; break ;
		case DIO_PORTC: DDRC_REG= Copy_u8Dir; break ;
		case DIO_PORTD: DDRD_REG = Copy_u8Dir; break ;
		default : break;
	}
}

void DIO_voidSetPortVal(u8 Copy_u8PortID, u8 Copy_u8Val) {
	switch (Copy_u8PortID){
		case DIO_PORTA: PORTA_REG = Copy_u8Val; break ;
		case DIO_PORTB: PORTB_REG= Copy_u8Val; break ;
		case DIO_PORTC: PORTC_REG = Copy_u8Val; break ;
		case DIO_PORTD: PORTD_REG  = Copy_u8Val; break ; default: break ;
	}
}

u8 DIO_u8GetPinVal(u8 Copy_u8PortID,u8 Copy_u8PinID){
	u8 data=0 ;
	if (Copy_u8PinID<=DIO_PIN7)
	{
		switch (Copy_u8PortID)
		{
			case DIO_PORTA: data= GET_BIT(PINA_REG,Copy_u8PinID); break;
			case DIO_PORTB: data= GET_BIT(PINB_REG,Copy_u8PinID) ; break;
			case DIO_PORTC: data= GET_BIT(PINC_REG,Copy_u8PinID); break;
			case DIO_PORTD: data= GET_BIT(PIND_REG,Copy_u8PinID); break;
			default: break ;

			
		}
		}else{
		//error
	}
	return data ;
}

u8 DIO_u8GetPortVal(u8 Copy_u8PortID){
	u8 data = 0 ;
	switch (Copy_u8PortID)
	{
		case DIO_PORTA:data= GET_BIT(PINA_REG,Copy_u8PortID);			break;
		case DIO_PORTB:data= GET_BIT(PINB_REG,Copy_u8PortID);			break;
		case DIO_PORTC:data= GET_BIT(PINC_REG,Copy_u8PortID);			break;
		case DIO_PORTD:data= GET_BIT(PIND_REG,Copy_u8PortID);			break;
		default:
		break ;
		
	}

	return data ;
}

void DIO_togglePin(u8 Copy_u8PortID,u8 Copy_u8PinID){
	
	if (Copy_u8PinID<=DIO_PIN7)
	{
		switch (Copy_u8PortID)
		{
			case DIO_PORTA:  TOG_BIT(PORTA_REG,Copy_u8PinID); break;
			case DIO_PORTB:  TOG_BIT(PORTB_REG,Copy_u8PinID) ; break;
			case DIO_PORTC:  TOG_BIT(PORTC_REG,Copy_u8PinID); break;
			case DIO_PORTD:  TOG_BIT(PORTD_REG,Copy_u8PinID); break;
			default: break ;
		}
		}else{
		//error
	}
}

void DIO_voidEnablePullUp(u8 Copy_u8PortID, u8 Copy_u8PinID){
		if (Copy_u8PinID<=DIO_PIN7)
		{
			switch (Copy_u8PortID)
			{
				case DIO_PORTA:  SET_BIT(PORTA_REG,Copy_u8PinID); break;
				case DIO_PORTB:  SET_BIT(PORTB_REG,Copy_u8PinID) ; break;
				case DIO_PORTC:  SET_BIT(PORTC_REG,Copy_u8PinID); break;
				case DIO_PORTD:  SET_BIT(PORTD_REG,Copy_u8PinID); break;
				default: break ;
			}
			}else{
			//error
		}
}