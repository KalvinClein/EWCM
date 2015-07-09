/* main.h */
/* June 2015 AEP Continental*/

//#include "typedefs.h"
//#include "MPC5606B.h"


#include "MCU_derivative.h"

#define Output 	(uint16_t)0x200 
#define Input 	(uint16_t)0x100
#define Analog 	(uint16_t)0x2000


/* Push buttons */

#define PortE0 SIU.PCR[64].R
#define PortE1 SIU.PCR[65].R 
#define PortE2 SIU.PCR[66].R 
#define PortE3 SIU.PCR[67].R

/* Board LEDs */
#define PortE4 SIU.PCR[68].R 
#define PortE5 SIU.PCR[69].R 
#define PortE6 SIU.PCR[70].R 
#define PortE7 SIU.PCR[71].R

/* ADC pins */
#define PortB4 SIU.PCR[20].R	//ADC0_P0

/* Push buttons pins */
#define S1 SIU.GPDI[64].R
#define S2 SIU.GPDI[65].R