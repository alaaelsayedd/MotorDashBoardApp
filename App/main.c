#include "../LIB/STD_TYPES.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/GRIO/DIO_Interface.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/GIF/GIF_Interface.h"
#include "../HAL/CLCD/CLCD_Interface.h"
#include "../HAL/KeyPad/Keypad_Interface.h"
#include "../HAL/MOTOR/MOTOR_Interface.h"
#include "../HAL/STEPPER/STEPPER_Interface.h"
#include <avr/delay.h>
u16 EnterID(void);
u16 ReversePass(void);
void DC_Motor(void);
void Servo_Motor(void);
void Stepper_Motor(void);
void PWMCCW_SW(void);
void PWMCW_SW(void);
u16 ID=0;
u16 Pass=0;
u16 Detect_Pass=0;
void main()
{
	PORT_voidInit();
	CLCD_void_Init();
	TIMER0_voidInit();
	TIMER1_voidInit();

	ADC_voidInit();



	u8 Local_PressedKey;



	CLCD_SendString("MOTORDashBoard");
	_delay_ms(300);



	while (1)
	{
		CLCD_voidSendCommand(1);
		CLCD_SendString("Enter Your ID:");
		_delay_ms(50);
		CLCD_voidGoToXY(1,0);
		ID=EnterID();
		CLCD_SendString("Enter Your Pass:");
		_delay_ms(50);
		Pass=EnterID();
		Detect_Pass=ReversePass();
		if(Pass==Detect_Pass)
		{
			CLCD_SendString("Welcom ");
			_delay_ms(300);
			CLCD_voidSendCommand(1);
			CLCD_voidGoToXY(0,0);
			CLCD_SendString("1- DC");
			CLCD_voidGoToXY(0,7);
			CLCD_SendString("2- SERVO");
			CLCD_voidGoToXY(1,0);
			CLCD_SendString("3-STEEPER");

			do
			{
				Local_PressedKey=KPD_u8GetPressedKey();
			}
			while(Local_PressedKey==KPD_NOPRESSEDkEY);
			if(Local_PressedKey==1)
			{
				while(Local_PressedKey!=29)
				{
					DC_Motor();
					do
					{
						Local_PressedKey=KPD_u8GetPressedKey();
					}
					while(Local_PressedKey==KPD_NOPRESSEDkEY);
				}
				MOTOR_voidStop();

			}

			else if(Local_PressedKey==2)
			{
				while(Local_PressedKey!=29)
				{
					Servo_Motor();
					do
					{
						Local_PressedKey=KPD_u8GetPressedKey();
					}
					while(Local_PressedKey==KPD_NOPRESSEDkEY);
				}
			}
			else if (Local_PressedKey==3)
			{
				while(Local_PressedKey!=29)
				{
					Stepper_Motor();
					do
					{
						Local_PressedKey=KPD_u8GetPressedKey();
					}
					while(Local_PressedKey==KPD_NOPRESSEDkEY);
				}
				STEPPER_voidStop();
			}
		}
			else
			{
				CLCD_SendString("Wrong Password ");
				_delay_ms(300);
				CLCD_voidSendCommand(1);
				CLCD_SendString("PleaseCloseAndTRYAgin");
			}
		}

	}
	u16 EnterID(void)
	{
		u8 Local_PressedKey;
		u16 Local_Number=1;
		do{
			Local_PressedKey=KPD_u8GetPressedKey();
		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY);
		/*
		 *  /:24
		 *  *:25
		 *  -:26
		 *  =: 28
		 *  +:27
		 *  ON/OFF:29
		 */
		while(Local_PressedKey!=28)
		{

			Local_Number=(Local_Number*10)+Local_PressedKey;
			CLCD_voidSendNumber(Local_PressedKey);
			do{
				Local_PressedKey=KPD_u8GetPressedKey();
			}
			while(Local_PressedKey==KPD_NOPRESSEDkEY);

		}
		CLCD_voidSendCommand(1);
		return Local_Number;

	}
	u16 ReversePass(void)
	{
		u16 Local_Var=ID;
		u16 Reversed_Pass=1;
		while(Local_Var!=1)
		{
			Reversed_Pass=Reversed_Pass*10+(Local_Var%10);
			Local_Var/=10;
		}

		return Reversed_Pass;
	}
	void DC_Motor(void)
	{
		u8 Local_PressedKey,Local_RDir,Local_Speed,LM_Read,POT_Read;
		u32 Mili_Volt;
		u8 Temp;
		s32 Result=0;

		CLCD_voidSendCommand(1);
		CLCD_voidGoToXY(0,0);
		CLCD_SendString("DC: 1- C.W");
		CLCD_voidGoToXY(1,0);
		CLCD_SendString("DC: 2- CC.W");
		do
		{
			Local_PressedKey=KPD_u8GetPressedKey();
		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY||Local_PressedKey>2);
		Local_RDir=Local_PressedKey;

		CLCD_voidSendCommand(1);
		CLCD_voidGoToXY(0,0);
		CLCD_SendString("1-full_speed");
		CLCD_voidGoToXY(1,0);
		CLCD_SendString("2-LM35");
		CLCD_voidGoToXY(1,7);
		CLCD_SendString("3-POT");
		do
		{
			Local_PressedKey=KPD_u8GetPressedKey();
		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY||Local_PressedKey>3);
		Local_Speed=Local_PressedKey;
		if(Local_RDir==1)
		{
			if(Local_Speed==1)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-full_speed And C.W");
				CLCD_voidGoToXY(1,0);
				CLCD_SendString("For DC Motor");
				MOTOR_voidRotateXY();




			}
			else if(Local_Speed==2)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-LM35 And C.W");
				CLCD_SendString("For DC Motor:");
				ADC_u8StartConvSynch(0,&LM_Read);
				Mili_Volt=((u32)LM_Read*5000UL)/255UL;
				Temp=Mili_Volt/10;
				Result= Map(0,45,0,255,Temp);
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendNumber(Result);
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendNumber(Temp);
				TIMER0_2_u8SetCompMatchValue(TIMER_0,Result);
				TIMER_voidSetCallBackFunc (&PWMCW_SW,TIMER_COUNTER0_COM);
				GIF_voidEnable();



			}
			else if(Local_Speed==3)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-POT And C.W");
				CLCD_voidGoToXY(1,0);
				CLCD_SendString("For DC Motor:");
				ADC_u8StartConvSynch(1,&POT_Read);
				TIMER0_2_u8SetCompMatchValue(TIMER_0,POT_Read);
				TIMER_voidSetCallBackFunc (&PWMCW_SW,TIMER_COUNTER0_COM);
				GIF_voidEnable();




			}
		}

		else
		{
			if(Local_Speed==1)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-full_speed And CC.W");
				CLCD_voidGoToXY(1,0);
				CLCD_SendString("For DC Motor");

				MOTOR_voidRotateYX();
			}
			else if(Local_Speed==2)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-LM35 And CC.W");
				CLCD_SendString("For DC Motor:");
				ADC_u8StartConvSynch(0,&LM_Read);
				Mili_Volt=((u32)LM_Read*5000UL)/255UL;
				Temp=Mili_Volt/10;
				Result= Map(0,45,0,255,Temp);
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendNumber(Result);
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendNumber(Temp);
				TIMER0_2_u8SetCompMatchValue(TIMER_0,Result);
				TIMER_voidSetCallBackFunc (&PWMCCW_SW,TIMER_COUNTER0_COM);
				GIF_voidEnable();


			}
			else if(Local_Speed==3)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidGoToXY(0,0);
				CLCD_SendString("1-POT And CC.W");
				CLCD_voidGoToXY(1,0);
				CLCD_SendString("For DC Motor:");
				ADC_u8StartConvSynch(1,&POT_Read);
				TIMER0_2_u8SetCompMatchValue(TIMER_0,POT_Read);
				TIMER_voidSetCallBackFunc (&PWMCCW_SW,TIMER_COUNTER0_COM);
				GIF_voidEnable();


			}

		}

	}
	void Servo_Motor(void)
	{
		u8 Local_PressedKey;
		s32  Result=0,Local_Angle=0;;
		TIMER1_u16SetTopValue(2000);
		CLCD_voidSendCommand(1);

		CLCD_voidGoToXY(0,0);
		CLCD_SendString("EnterAngle0:180");
		CLCD_voidGoToXY(1,0);
		CLCD_SendString("Angle:");
		do
		{
			Local_PressedKey=KPD_u8GetPressedKey();

		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY||Local_PressedKey>=24);
		while(Local_PressedKey!=28)
		{
			CLCD_voidSendNumber(Local_PressedKey);
			Local_Angle=Local_Angle*10+Local_PressedKey;
			do
			{

				Local_PressedKey=KPD_u8GetPressedKey();

			}
			while(Local_PressedKey==KPD_NOPRESSEDkEY||(Local_PressedKey>=24&&Local_PressedKey<=27));

		}
		Result=Map(0,180,124,248,Local_Angle);
		TIMER1_SetChannel(TIMER1_COMA);
		TIMER1_u8SetCompMatchValue(TIMER1_COMA,Result);
	}
	void Stepper_Motor(void)
	{
		u8 Local_PressedKey,Local_u8Counter,Local_RDir;
		s32  Result=0,Local_Angle=0;
		CLCD_voidSendCommand(1);
		CLCD_voidGoToXY(0,0);
		CLCD_SendString("1- C.W");
		CLCD_voidGoToXY(1,0);
		CLCD_SendString("2- CC.W");
		do
		{
			Local_PressedKey=KPD_u8GetPressedKey();
		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY||Local_PressedKey>2);
		Local_RDir=Local_PressedKey;
		CLCD_voidSendCommand(1);
		CLCD_voidGoToXY(0,0);
		CLCD_SendString("EnterAngle0:180");
		CLCD_voidGoToXY(1,0);
		CLCD_SendString("Angle:");
		do
		{
			Local_PressedKey=KPD_u8GetPressedKey();

		}
		while(Local_PressedKey==KPD_NOPRESSEDkEY||Local_PressedKey>=24);
		while(Local_PressedKey!=28)
		{
			CLCD_voidSendNumber(Local_PressedKey);
			Local_Angle=Local_Angle*10+Local_PressedKey;
			do
			{

				Local_PressedKey=KPD_u8GetPressedKey();

			}
			while(Local_PressedKey==KPD_NOPRESSEDkEY||(Local_PressedKey>=24&&Local_PressedKey<=27));

		}
		Result=Local_Angle;
		Result*=1.5;

		for(Local_u8Counter=0;Local_u8Counter<Result;Local_u8Counter++)
		{
			if(Local_RDir==1)
			{
				STEPPER_voidRotateXY();
			}
			else if(Local_RDir==2)
			{
				STEPPER_voidRotateYX();
			}

		}


	}


	void PWMCCW_SW(void)
	{
		DIO_vTogglePin(GROUPA,PIN_7);
	}
	void PWMCW_SW(void)
	{
		DIO_vTogglePin(GROUPA,PIN_6);
	}




