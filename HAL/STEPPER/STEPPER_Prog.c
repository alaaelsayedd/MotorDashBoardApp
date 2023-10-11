/*
 * STEPPER_Prog.c

 *
 *  Created on: ??�/??�/????
 *      Author: zas
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GRIO/DIO_Interface.h"
#include "STEPPER_Interface.h"
#include "STEPPER_Config.h"
#include "STEPPER_Private.h"
#include <avr/delay.h>
void STEPPER_voidRotateXY(void)
{
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,LOW);
	_delay_ms(2);
}

void STEPPER_voidRotateYX(void)
{
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,LOW);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,LOW);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
	_delay_ms(2);
}
void STEPPER_voidStop(void)
{
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_1,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_2,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_3,HIGH);
	DIO_vSetPinValue(STEPPER_PORT,STEEPER_PIN_4,HIGH);
}
