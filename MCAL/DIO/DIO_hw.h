#ifndef _DIO_HW
#define _DIO_HW

#define DDRA_REG		*((volatile uint8*)0x3A)
#define PORTA_REG		*((volatile uint8*)0x3B)
#define PINA_REG		*((const volatile uint8*)0x39 )
#define DDRB_REG		*((volatile uint8*)0x37)
#define PORTB_REG		*((volatile uint8*)0x38)
#define PINB_REG		*((const volatile uint8*)0x36 )
#define DDRC_REG		*((volatile uint8*)0x34)
#define PORTC_REG		*((volatile uint8*)0x35)
#define PINC_REG		*((const volatile uint8*)0x33 )
#define DDRD_REG		*((volatile uint8*)0x31)
#define PORTD_REG		*((volatile uint8*)0x32)
#define PIND_REG		*((const volatile uint8*)0x30 )

#endif
