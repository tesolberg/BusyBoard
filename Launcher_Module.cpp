///////////////////////
//  LAUNCHER MODULE  //
///////////////////////

/*
To use the module instantiate a launcher module with the proper pin arguments and call its updateLauncherModule function in update.
*/

#include "Arduino.h"
#include "Launcher_Module.h"


Launcher_Module::Launcher_Module(int launcherVccPin, int launcherInputPin, int buzzerPin)
{
	_launcherVccPin = launcherVccPin;
	_launcherInputPin = launcherInputPin;
	_buzzerPin = buzzerPin;
	launching = false;
	startBuzzerHz = 0;
	maxBuzzerHz = 1750;
	currentBuzzerHz = startBuzzerHz;

	pinMode(launcherVccPin, OUTPUT);
	pinMode(launcherInputPin, INPUT);
	pinMode(buzzerPin, OUTPUT);
}

void Launcher_Module::runLaunch()
{
	if (launching)
	{
		tone(_buzzerPin, currentBuzzerHz);
		currentBuzzerHz++;
		delay(5);

		if (currentBuzzerHz > maxBuzzerHz)
		{
		launching = false;
		currentBuzzerHz = startBuzzerHz;
		}
	}
	else
	{
		noTone(_buzzerPin);
		currentBuzzerHz = startBuzzerHz;
	}

}


void Launcher_Module::updateLauncherModule() 
{
	if ((millis() / 1000) % 2 > 0)
	{
		digitalWrite(_launcherVccPin, HIGH);

		// LOW means user has toggled switch.
		launching = (digitalRead(_launcherInputPin) == LOW);
	} 
	else
	{
		digitalWrite(_launcherVccPin, LOW);
	}

	runLaunch();
}

