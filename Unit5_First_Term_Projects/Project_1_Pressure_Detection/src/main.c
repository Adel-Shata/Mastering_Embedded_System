#include <stdint.h>
#include <stdio.h>


#include "Alarm.h"
#include "High_Pressure_Detection.h"

void setup(){
	gpioInit();
	pressureSensorInit();
	alarmActuatorInit();
}

int main(){
	setup();
	while (1)
	{
		alarmfsmTick();
		highPressureDetectionfsmTick();
	}

}
