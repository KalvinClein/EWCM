/*******************************************************************************/
/**
\file       dummy.c
\brief      Dummy Functions
\author     Francisco Martinez
\version    1.0
\date       04/04/2014
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
#include "dummy.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/** Used modules */

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
/*typedef struct {
T_UWORD ruw_Counter;
T_UWORD ruw_TopCount;
tCallbackFunction   cpfu_PerFunct; 
}TASKSTRUCT;*/

/*****************************************************************************************************
* Definition of extern VARIABLEs 
*****************************************************************************************************/
extern TASKSTRUCT function_table_def[4];		/* Task's tables structures */
extern TASKSTRUCT *rps_TaskPtr[4];				/* Pointers to task's tables structures */

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/****************************************************************************************************/
/**
* \brief    Turn a combination of 4 LEDs with a unique blinking pattern, this funcation shall be 
* \brief    called periodically to operate. 
* \author   Francisco Martinez
* \return   void
*/
void Test(void)
{
    static T_UWORD rub_U16Counter = 0;
    
    rub_U16Counter++;
    
    if (rub_U16Counter == 1000)
    {
    	LED_TOGGLE(LED1);
    	rub_U16Counter = 0;	
    }

}

void dummy_endless_loop(void)
{
	for(;;)
	{
		/* Do nothing */	
	}
}

void dummy_500us(void)
{
	T_UBYTE i;
	for(i=0;i<4;i++)		
	{
		rps_TaskPtr[i]->ruw_Counter++;			/* Increase counters */
		if( (rps_TaskPtr[i]->ruw_Counter) == (rps_TaskPtr[i]->ruw_TopCount) )		/* Check if match */
		{
			rps_TaskPtr[i]->ruw_Counter=0;		/* Clear counter */
			rps_TaskPtr[i]->cpfu_PerFunct();	/* Call periodic function */
		}
	}
}

void Task_5ms(void)		/* Each 5ms */
{
	LED_TOGGLE(LED1);
}

void Task_10ms(void)	/* Each 10ms */
{
	LED_TOGGLE(LED2);
}

void Task_50ms(void)	/* Each 50ms */
{
	LED_TOGGLE(LED3);
}

void Task_100ms(void)	/* Each 100ms */
{
	LED_TOGGLE(LED4);
}
