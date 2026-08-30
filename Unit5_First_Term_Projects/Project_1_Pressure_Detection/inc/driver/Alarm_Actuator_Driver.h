#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

/*Section 1: Include Files*/
#include "driver.h"
/*Section 2: Macros*/
/*Section 3: Macro Functions*/
/*Section 4: Function Prototypes*/

/**
 * @brief Initialize the alarm actuator
 */
void alarmActuatorInit();

/**
 * @brief Turn the alarm actuator on
 */
void alarmActuatorOn();

/**
 * @brief Turn the alarm actuator off
 */
void alarmActuatorOff();
#endif // ALARM_ACTUATOR_DRIVER_H_