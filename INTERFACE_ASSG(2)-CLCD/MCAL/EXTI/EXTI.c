#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../util/std_types.h"
#include "../../util/bit_math.h"
#include "EXTI.h"
#include "../register_def.h"



void Enable_INT1()
{
	SET_BIT(GICR_REG,GICR_INT1);
}
void Disable_INT1()
{
	CLR_BIT(GICR_REG,GICR_INT1);
}

void Enable_INT2()
{
	SET_BIT(GICR_REG,GICR_INT2);
}
void Disable_INT2()
{
	CLR_BIT(GICR_REG,GICR_INT1);
}

void Enable_INT0()
{
	SET_BIT(GICR_REG,GICR_INT0);
}
void Disable_INT0()
{
	CLR_BIT(GICR_REG,GICR_INT0);
}

void EXTINT_voidChangeSenseControl(u8 copy_u8INTID , u8 copy_u8sensecontrol)
{
	switch (copy_u8INTID)
	{
		
		case EXTINT_INT0 :
		switch (copy_u8sensecontrol)
		{
			case EXTINT_lowlevel :
			CLR_BIT(MCUCR_REG,MCUCR_ISC00);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			case EXTINT_anychange :
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			case EXTINT_falling :
			CLR_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			case EXTINT_rising :
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
		}
		break;
		
		
		case EXTINT_INT1 :
		switch (copy_u8sensecontrol)
		{
			
			case EXTINT_lowlevel :
			CLR_BIT(MCUCR_REG,MCUCR_ISC10);
			CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			case EXTINT_anychange :
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
			CLR_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			case EXTINT_falling :
			CLR_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			case EXTINT_rising :
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
		}
		break;
		
		
		case EXTINT_INT2 :
		switch (copy_u8sensecontrol)
		{
			case EXTINT_falling :
			CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
			break;
			case EXTINT_rising :
			SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
			break;
			default:
			//error
			break;
		}
		break;
		
		default:
		//error
		break;
	}
	
	
}