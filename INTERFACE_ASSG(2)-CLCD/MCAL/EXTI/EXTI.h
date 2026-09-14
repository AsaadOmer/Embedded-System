#ifndef EXTINT_H_
#define EXTINT_H_

#define EXTINT_rising 3
#define EXTINT_falling 2
#define EXTINT_anychange 1
#define EXTINT_lowlevel 0

#define EXTINT_INT2 2
#define EXTINT_INT1 1
#define EXTINT_INT0 0

void Enable_INT1();
void Disable_INT1();

void Enable_INT2();
void Disable_INT2();

void Enable_INT0();
void Disable_INT0();

void EXTINT_voidChangeSenseControl(u8 copy_u8INTID , u8 copy_u8sensecontrol);



#endif /* EXTINT_H_ */