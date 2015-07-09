/*******************************************************************************
*		Practice 2	EWCM
*		Automotive Entry Program 2015
*		Kevin Castellanos
********************************************************************************/

#include "MCU_derivative.h"

/** GPIO funtion prototypes  */
#include    "GPIO.h"
#include    "PIT.h"
#include    "dummy.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/


/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/
 
/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/

/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(void) 

{
	initModesAndClock();
	/* Disable Watchdog */
	disableWatchdog();
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init();
	

		
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , dummy_500us);	
    PIT_channel_start(PIT_CHANNEL_0);
    
    /* Enable External Interrupts*/
    enableIrq();
	
	/* Do nothing, work using PIT ISR */
	dummy_endless_loop();
	
	/* Infinite loop */
	for (;;) 
	{
        BackgroundSubsystemTasks();
	}
}

/*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* Background tasks related to Subsystem control */
void BackgroundSubsystemTasks(void) 
{
	rpub_PtrToU8 = &rub_Var1; /* We need to initialize the pointer to be used by our function invocation */

    rpfu_PtrToFctn = &Function1; /* Let's perform our deferencing procedure (initialization) */

    /* Let's first call our function through direct invocation */
    rub_Var2 = Function1(rpub_PtrToU8);
    
    /* Clear var2 in preparation to next invocation */
    rub_Var2 = 0;

    /* Now, perform invocation through our pointer */
    rub_Var2 = rpfu_PtrToFctn(rpub_PtrToU8);

    /* See, I told you, pointers to functions are FUN !! */;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
