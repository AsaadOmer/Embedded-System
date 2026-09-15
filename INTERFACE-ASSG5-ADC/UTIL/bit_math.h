/*
 * bit_math.h
 *
 * Created: 4/29/2026 8:38:37 PM
 *  Author: Eslam El Hefny
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)     (reg|=(1<<bit))
#define CLR_BIT(reg,bit)     (reg&=~(1<<bit))
#define TOG_BIT(reg,bit)     (reg^=(1<<bit))
#define GET_BIT(reg,bit)	 ((reg>>bit)&1)


#endif /* BIT_MATH_H_ */