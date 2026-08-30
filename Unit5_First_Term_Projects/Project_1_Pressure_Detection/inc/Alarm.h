#ifndef ALARM_H_
#define ALARM_H_
/*Section 1: Include Files*/
#include "driver/Alarm_Actuator_Driver.h"
#include "High_Pressure_Detection.h"
/*Section 2: Macros*/
/*Section 3: Macro Functions*/
/*Section 4: Function Prototypes*/

 /**
 * @brief Finite State Machine tick function for alarm control
 */
void alarmfsmTick(void);

#endif /* ALARM_H_ */
