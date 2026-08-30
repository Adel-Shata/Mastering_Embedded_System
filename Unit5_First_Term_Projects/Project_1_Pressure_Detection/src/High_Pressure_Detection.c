#include "High_Pressure_Detection.h"

static enum{
    PRESSURE_READING,
    PRESSURE_CHECKING,
    PRESSURE_READING_WAITING
}pressureDetectionState = PRESSURE_READING;

static highPressureState_t pressureValue = PRESSURE_NOT_HIGH;
static int32_t pressure;

void highPressureDetectionfsmTick(void){
    switch(pressureDetectionState){
        case PRESSURE_READING:
            pressureSensorRead(&pressure);
            pressureDetectionState = PRESSURE_CHECKING;
            break;
        case PRESSURE_CHECKING:
            if(pressure >= HIGH_PRESSURE_THRESHOLD){
                pressureValue = PRESSURE_HIGH;
            } else {
                pressureValue = PRESSURE_NOT_HIGH;
            }
            pressureDetectionState = PRESSURE_READING_WAITING;
            break;
        case PRESSURE_READING_WAITING:
            delay(1000); // Wait 1 second before next reading
            pressureDetectionState = PRESSURE_READING;
            break;
    }
}

highPressureState_t highPressureDetected(void){
    return pressureValue;
}