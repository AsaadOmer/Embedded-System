/*
 * register_def.h
 *
 * Created: 4/29/2026 8:51:36 PM
 *  Author: Eslam El Hefny
 */ 


#ifndef REGISTER_DEF_H_
#define REGISTER_DEF_H_

// /*
// $1B ($3B) PORTA PORTA7 PORTA6 PORTA5 PORTA4 PORTA3 PORTA2 PORTA1 PORTA0 64
// $1A ($3A) DDRA DDA7 DDA6 DDA5 DDA4 DDA3 DDA2 DDA1 DDA0 64
// $19 ($39) PINA PINA7 PINA6 PINA5 PINA4 PINA3 PINA2 PINA1 PINA0 64
// $18 ($38) PORTB PORTB7 PORTB6 PORTB5 PORTB4 PORTB3 PORTB2 PORTB1 PORTB0 64
// $17 ($37) DDRB DDB7 DDB6 DDB5 DDB4 DDB3 DDB2 DDB1 DDB0 64
// $16 ($36) PINB PINB7 PINB6 PINB5 PINB4 PINB3 PINB2 PINB1 PINB0 65
// $15 ($35) PORTC PORTC7 PORTC6 PORTC5 PORTC4 PORTC3 PORTC2 PORTC1 PORTC0 65
// $14 ($34) DDRC DDC7 DDC6 DDC5 DDC4 DDC3 DDC2 DDC1 DDC0 65
// $13 ($33) PINC PINC7 PINC6 PINC5 PINC4 PINC3 PINC2 PINC1 PINC0 65
// $12 ($32) PORTD PORTD7 PORTD6 PORTD5 PORTD4 PORTD3 PORTD2 PORTD1 PORTD0 65
// $11 ($31) DDRD DDD7 DDD6 DDD5 DDD4 DDD3 DDD2 DDD1 DDD0 65
// $10 ($30) PIND PIND7 PIND6 PIND5 PIND4 PIND3 PIND2 PIND1 PIND0 65*/
#define PORTA_REG     *((volatile u8 *)(0x3b))
#define DDRA_REG     *((volatile u8 *)(0x3a))
#define PINA_REG     *((volatile u8 *)(0x39))
#define PORTB_REG     *((volatile u8 *)(0x38))
#define DDRB_REG     *((volatile u8 *)(0x37))
#define PINB_REG     *((volatile u8 *)(0x36))
#define PORTC_REG     *((volatile u8 *)(0x35))
#define DDRC_REG     *((volatile u8 *)(0x34))
#define PINC_REG     *((volatile u8 *)(0x33))
#define PORTD_REG     *((volatile u8 *)(0x32))
#define DDRD_REG     *((volatile u8 *)(0x31))
#define PIND_REG     *((volatile u8 *)(0x30))


/************************ EXTI******************/
#define MCUCR_REG     *((volatile u8*)(0x55))
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3
#define MCUCSR_REG    *((volatile u8*)(0x54))
#define MCUCSR_ISC2   6

#define GICR_REG       *((volatile u8*)(0x5b))
#define GICR_INT2       5
#define GICR_INT0       6
#define GICR_INT1       7


#define GIFR_REG       *((volatile u8*)(0x5a))
#define GIFR_INT2       5
#define GIFR_INT0       6
#define GIFR_INT1       7



/**************************ADC Reg ***************************/


/*ADC Multiplexer Register */
#define ADC_ADMUX_REG        *((volatile u8* )(0x27))
#define ADC_ADMUX_REFS1      7
#define ADC_ADMUX_REFS0      6
#define ADC_ADMUX_ADLAR      5
/*ADC Control Register */
#define ADC_ADCSRA_REG       *((volatile u8* )(0x26))
#define ADC_ADCSRA_ADEN      7
#define ADC_ADCSRA_ADSC      6
#define ADC_ADCSRA_ADATE     5
#define ADC_ADCSRA_ADIF      4
#define ADC_ADCSRA_ADIE      3
#define ADC_ADCSRA_ADPS2     2
#define ADC_ADCSRA_ADPS1     1
#define ADC_ADCSRA_ADPS0     0

/*ADC Data Register */
#define ADC_ADC_REG          *((volatile u16*)(0x24))
#define ADC_ADCL_REG         *((volatile u8* )(0x24))
#define ADC_ADCH_REG         *((volatile u8* )(0x25))

/*************************** Timer 0 *************************/
/********* Timer/Counter Register **********/
/*Timer/Counter Control Register – TCCR0 */
/*
$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
$38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130
$33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80
$32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82*/
#define TIMER_TCCR0_REG        *((volatile u8* )(0x53))
#define TIMER_TCCR0_FOC0      7
#define TIMER_TCCR0_WGM00     6
#define TIMER_TCCR0_COM01     5
#define TIMER_TCCR0_COM00     4
#define TIMER_TCCR0_WGM01     3
#define TIMER_TCCR0_CS02      2
#define TIMER_TCCR0_CS01      1
#define TIMER_TCCR0_CS00      0

/*Timer/Counter Register – TCNT0 */
#define TIMER_TCNT0_REG       *((volatile u8*)(0x52))


/* Output Compare Register – OCR0  */
#define TIMER_OCR0_REG          *((volatile u8*)(0x5C))

/*Timer/Counter Interrupt Mask Register – TIMSK  */
#define TIMER_TIMSK_REG          *((volatile u8*)(0x59))
#define TIMER_TIMSK_OCIE0   1
#define TIMER_TIMSK_TOIE0   0

/*Timer/Counter Interrupt Flag Register – TIFR*/
#define TIMER_TIFR_REG          *((volatile u8*)(0x58))
#define TIMER_TIFR_OCF0   1
#define TIMER_TIFR_TOV0   0

/******************************************************************************/
/*************************** USART Registers **********************************/
/******************************************************************************/

/* USART I/O Data Register */
#define USART_UDR_REG           (*((volatile u8* )(0x2C)))

/* USART Control and Status Register A */
#define USART_UCSRA_REG         (*((volatile u8* )(0x2B)))
#define USART_UCSRA_RXC         7
#define USART_UCSRA_TXC         6
#define USART_UCSRA_UDRE        5
#define USART_UCSRA_FE          4
#define USART_UCSRA_DOR         3
#define USART_UCSRA_PE          2
#define USART_UCSRA_U2X         1
#define USART_UCSRA_MPCM        0

/* USART Control and Status Register B */
#define USART_UCSRB_REG         (*((volatile u8* )(0x2A)))
#define USART_UCSRB_RXCIE       7
#define USART_UCSRB_TXCIE       6
#define USART_UCSRB_UDRIE       5
#define USART_UCSRB_RXEN        4
#define USART_UCSRB_TXEN        3
#define USART_UCSRB_UCSZ2       2
#define USART_UCSRB_RXB8        1
#define USART_UCSRB_TXB8        0

/* USART Control and Status Register C */
#define USART_UCSRC_REG         (*((volatile u8* )(0x40)))
#define USART_UCSRC_URSEL       7
#define USART_UCSRC_UMSEL       6
#define USART_UCSRC_UPM1        5
#define USART_UCSRC_UPM0        4
#define USART_UCSRC_USBS        3
#define USART_UCSRC_UCSZ1       2
#define USART_UCSRC_UCSZ0       1
#define USART_UCSRC_UCPOL       0

/* USART Baud Rate Register Low */
#define USART_UBRRL_REG         (*((volatile u8* )(0x29)))

/* USART Baud Rate Register High */
#define USART_UBRRH_REG         (*((volatile u8* )(0x40)))



/* ==================================================================== */
/*                           SPI Registers                              */
/* ==================================================================== */
#define SPCR    *((volatile u8*)0x2D)   /* SPI Control Register */
#define SPSR    *((volatile u8*)0x2E)   /* SPI Status Register */
#define SPDR    *((volatile u8*)0x2F)   /* SPI Data Register */

/* SPCR Bits */
#define SPCR_SPIE   7   /* SPI Interrupt Enable */
#define SPCR_SPE    6   /* SPI Enable */
#define SPCR_DORD   5   /* Data Order */
#define SPCR_MSTR   4   /* Master/Slave Select */
#define SPCR_CPOL   3   /* Clock Polarity */
#define SPCR_CPHA   2   /* Clock Phase */
#define SPCR_SPR1   1   /* Clock Rate Select 1 */
#define SPCR_SPR0   0   /* Clock Rate Select 0 */

/* SPSR Bits */
#define SPSR_SPIF   7   /* SPI Interrupt Flag */
#define SPSR_WCOL   6   /* Write Collision Flag */
#define SPSR_SPI2X  0   /* Double SPI Speed Bit */


/******************************************************************************/
/*************************** TWI / I2C Registers ******************************/
/******************************************************************************/

/* TWI Bit Rate Register */
#define TWI_TWBR_REG             *((volatile u8*)(0x20))

/* TWI Control Register */
#define TWI_TWCR_REG             *((volatile u8*)(0x56))
#define TWI_TWCR_TWINT           7   /* TWI Interrupt Flag */
#define TWI_TWCR_TWEA            6   /* TWI Enable Acknowledge Bit */
#define TWI_TWCR_TWSTA           5   /* TWI START Condition Bit */
#define TWI_TWCR_TWSTO           4   /* TWI STOP Condition Bit */
#define TWI_TWCR_TWWC            3   /* TWI Write Collision Flag */
#define TWI_TWCR_TWEN            2   /* TWI Enable Bit */
#define TWI_TWCR_TWIE            0   /* TWI Interrupt Enable */

/* TWI Status Register */
#define TWI_TWSR_REG             *((volatile u8*)(0x21))
#define TWI_TWSR_TWPS1           1   /* TWI Prescaler Bit 1 */
#define TWI_TWSR_TWPS0           0   /* TWI Prescaler Bit 0 */

/* TWI Data Register */
#define TWI_TWDR_REG             *((volatile u8*)(0x23))

/* TWI (Slave) Address Register */
#define TWI_TWAR_REG             *((volatile u8*)(0x22))
#define TWI_TWAR_TWGCE           0   /* TWI General Call Enable Bit */

#endif /* REGISTER_DEF_H_ */