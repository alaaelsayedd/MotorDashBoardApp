/*
 * MOTOR_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GRIO/DIO_Interface.h"
#include "MOTOR_Config.h"
#include "MOTOR_Interface.h"

void MOTOR_voidRotateXY(void)
{
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_1,LOW);
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_2,HIGH);
}
void MOTOR_voidRotateYX(void)
{
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_2,LOW);
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_1,HIGH);
}
void MOTOR_voidStop(void)
{
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_1,LOW);
	DIO_vSetPinValue(MOTOR_PORT,MOTOR_PIN_2,LOW);
}
