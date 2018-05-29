////////////////////
//  POWER MODULE  //
////////////////////


#include "Arduino.h"
#include "PowerModule.h"


PowerModule::PowerModule()
{
	powerOn = false;
	poweringUpFinished = false;
}

void PowerModule::runPowerModule() 
{
	powerOn = true;
	//powerOn = digitalRead(powerSwitchPin) == HIGH;
}
