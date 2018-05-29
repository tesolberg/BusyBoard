////////////////////
//  POWER MODULE  //
////////////////////


#include "Arduino.h"
#include "Hex_Module.h"


Hex_Module::Hex_Module(int reedPin, int topLedPin, int leftLedPin, int rightLedPin)
{
	powerOn = false;
	poweringUpFinished = false;
	_reedPin = reedPin;
	_topLedPin = topLedPin;
	_leftLedPin = leftLedPin;
	_rightLedPin = rightLedPin;
}

void Hex_Module::startHexModule() 
{

	powerOn = true;
	//powerOn = digitalRead(powerSwitchPin) == HIGH;
}
