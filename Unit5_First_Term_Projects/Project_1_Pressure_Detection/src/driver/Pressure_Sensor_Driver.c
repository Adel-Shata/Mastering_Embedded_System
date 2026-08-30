#include "driver/Pressure_Sensor_Driver.h"

static enum{
    PRESSURE_SENSOR_IDLE = 0,
    PRESSURE_SENSOR_READING
}pressureSensorState;


void pressureSensorInit(){
    pressureSensorState = PRESSURE_SENSOR_IDLE;
}

void pressureSensorRead(int32_t *pressure){
    if(pressureSensorState == PRESSURE_SENSOR_IDLE){
        pressureSensorState = PRESSURE_SENSOR_READING;
        *pressure = getPressureVal();
    }
    pressureSensorState = PRESSURE_SENSOR_IDLE;
}