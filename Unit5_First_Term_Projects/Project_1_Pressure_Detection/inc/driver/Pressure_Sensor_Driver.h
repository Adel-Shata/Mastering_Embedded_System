#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

/*Section 1: Include Files*/
#include "driver.h"
/*Section 2: Macros*/
/*Section 3: Macro Functions*/
/*Section 4: Function Prototypes*/

/**
 * @brief Initialize the pressure sensor
 */
void pressureSensorInit();

/**
 * @brief Read the pressure value from the sensor
 * @param pressure Pointer to store the read pressure value
 */
void pressureSensorRead(int32_t *pressure);
#endif // PRESSURE_SENSOR_DRIVER_H_