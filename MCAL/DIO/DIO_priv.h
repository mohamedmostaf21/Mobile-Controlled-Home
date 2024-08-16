/**************************************/
/* Description : DIO private file     */
/* Author      : Mohamed Mostafa        */
/* Version     : 0.1v                 */
/* Date        : 29 july 2024          */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#define DIO_INPUT     0
#define DIO_OUTPUT    1

#define DDRA *((volatile u8 *)0x3A)
#define DDRB *((volatile u8 *)0x37)
#define DDRC *((volatile u8 *)0x34)
#define DDRD *((volatile u8 *)0x31)

#define IDRA *((volatile u8 *)0x39)
#define IDRB *((volatile u8 *)0x36)
#define IDRC *((volatile u8 *)0x33)
#define IDRD *((volatile u8 *)0x30)

#define ODRA *((volatile u8 *)0x3B)
#define ODRB *((volatile u8 *)0x38)
#define ODRC *((volatile u8 *)0x35)
#define ODRD *((volatile u8 *)0x32)


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)       CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
//Creating an enum to substitute every PORT with it's number
typedef enum{
	PORTA = 0, //making sure first element equals 0
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS_t;

#ifndef DIO_PIN_DIR_0
#define DIO_PIN_DIR_0     DIO_INPUT
#endif

#endif
