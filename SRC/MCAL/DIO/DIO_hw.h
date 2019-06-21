#ifndef _DIO_HW
#define _DIO_HW

#define PORTA_REG		*((volatile uint8*)0x3B)
#define PORTB_REG		*((volatile uint8*)0x38)
#define PORTC_REG		*((volatile uint8*)0x35)
#define PORTD_REG		*((volatile uint8*)0x32)

#define PINA_REG		*((const volatile uint8*)0x39 )
#define PINB_REG		*((const volatile uint8*)0x36 )
#define PINC_REG		*((const volatile uint8*)0x33 )
#define PIND_REG		*((const volatile uint8*)0x30 )



#endif
