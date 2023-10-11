/*************  DRIVER : ADC             *******************
**************  DEV_NAME : ALAA            ******************
**************  DATE :26 AUG 2023         ******************
**************  SOFTWARE VERSION : V2.0    ******************
************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
/*
 * ADC VOLTAGE REFERACE:
 * 1- AREF_EXT
 * 2- AVCC
 * 3- AREF_INTERNAL
 */
#define ADC_VOLT_REF   AVCC
/*
 * ADC_LEFT_ADJUST RSULT:
 * 1- ENABLE
 * 2- DISABLE
 */
#define ADC_LEFT_ADJUST  ENABLE
/*
 * ADC Auto Trigger :
 * 1- ENABLE
 * 2- DISABLE
 */


#define ADC_AUTO_TRIGGER  DISABLE
/*
 * Choose Trigger Source:
1- FREE_RUNNING
2- ANALOG_COMPARATOR
3- EXTERNAL_INTERRUPT_REQUEST_0
4- TIMER/COUNTER0_COMPARE_MATCH
5- TIMER/COUNTER0_OVERFLOW
6- TIMER/COUNTER_COMPARE_MATCH_B
7- TIMER/COUNTER1_OVERFLOW
8- TIMER/COUNTER1_CAPTURE_EVENT
*/

#define TRIGGER_SOURCE   FREE_RUNNING
/*
 * ADC Interrupt :
 * 1- ENABLE
 * 2- DISABLE
 */
#define ADC_INTERRUPT  DISABLE


/*
 * ADC Prescaler Select :
 * ADPS_DIV_BY2
 * ADPS_DIV_BY4
 * ADPS_DIV_BY8
 * ADPS_DIV_BY16
 * ADPS_DIV_BY32
 * ADPS_DIV_BY64
 * ADPS_DIV_BY128
 */
#define ADC_PRESCALER   ADPS_DIV_BY128
/*
 * ADC_TRIGGER_CHANNEL :
 * 1- ADC0
 * 2- ADC1
 * 3- ADC2
 * 4- ADC3
 * 5- ADC4
 * 6- ADC5
 * 7- ADC6
 * 8- ADC7
 */
#define ADC_TRIGGER_CHANNEL  ADC0
#define ADC_TIMEOUT            50000

#define IDEL   0
#define BUSY   1

#endif
