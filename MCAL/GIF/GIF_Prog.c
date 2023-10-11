/*
 * GIF_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: zas
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.H"
#include "../GRIO/DIO_Interface.h"
#include "GIF_Register.h"
#include "GIF_Interface.h"

void GIF_voidEnable(void)
{
	SET_BIT(SRIC_REG,SRIC_I);
}
 void GIF_voidDisable(void)
 {
	 CLR_BIT(SRIC_REG,SRIC_I);
 }
