#include "Alarm.h"

static enum{
    ALARM_OFF,
    ALARM_ON,
    ALARM_WAITING
}alarmState = ALARM_OFF;


void alarmfsmTick(void) {
    switch(alarmState){
        case ALARM_OFF:
            alarmActuatorOff();
            if(highPressureDetected() == PRESSURE_HIGH){
                alarmState = ALARM_ON;
            }
            break;
        case ALARM_ON:
            alarmActuatorOn();
            alarmState = ALARM_WAITING;
            break;
        case ALARM_WAITING:
            delay(60000); // Wait 30 seconds before turning off the alarm
            alarmState = ALARM_OFF;
            break;
    }
}