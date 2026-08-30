#ifndef HIGH_PRESSURE_DETECTION_H_
#define HIGH_PRESSURE_DETECTION_H_

/*Section 1: Include Files*/
#include "driver/Pressure_Sensor_Driver.h"
/*Section 2: User Defined Types*/
typedef enum{
    PRESSURE_NOT_HIGH,
    PRESSURE_HIGH
}highPressureState_t;
/*Section 2: Macros*/
#define HIGH_PRESSURE_THRESHOLD 20 // Example threshold value
/*Section 3: Macro Functions*/
/*Section 4: Function Prototypes*/

/**
 * @brief Finite State Machine tick function for high pressure detection
 */
void highPressureDetectionfsmTick(void);

/**
 * @brief Detects if the pressure is high
 * @return The state of the pressure detection
 */
highPressureState_t highPressureDetected(void);


#endif // HIGH_PRESSURE_DETECTION_H_