///////////////////////
//  LAUNCHER MODULE  //
///////////////////////

/*
To use the module instantiate a launcher module with the proper pin arguments 
and call its updateLauncherModule function in update. Add a delay of a few
milliseconds to get tone to go from starting hz to max hz in the proper time.
*/

#include "Arduino.h"
#include "Launcher_Module.h"

Launcher_Module::Launcher_Module(int launcherVccPin, 
								 int launcherInputPin, 
								 int buzzerPin)
{
	_launcherVccPin = launcherVccPin;
	_launcherInputPin = launcherInputPin;
	_buzzerPin = buzzerPin;
	launching = false;
	startBuzzerHz = 0;
	maxBuzzerHz = 1750;
	currentBuzzerHz = startBuzzerHz;
	launchFinished = false;

	pinMode(launcherVccPin, OUTPUT);
	pinMode(launcherInputPin, INPUT);
	pinMode(buzzerPin, OUTPUT);
}

void Launcher_Module::runLaunch()
{
	if (launching && !launchFinished)
	{
		tone(_buzzerPin, currentBuzzerHz);
		currentBuzzerHz++;

		if (currentBuzzerHz > maxBuzzerHz)
		{
		launchFinished = true;
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
	// Every other second.
	if ((millis() / 1000) % 2 > 0)
	{
		// Turns on power to switch.
		digitalWrite(_launcherVccPin, HIGH);

		// LOW means user has toggled switch.
		launching = (digitalRead(_launcherInputPin) == LOW);
		
		// If write is on but switch is off -> launchFinished set to false.
		if (!launching)
		{
			launchFinished = false;
		}
	} 
	else
	{
		digitalWrite(_launcherVccPin, LOW);
	}

	runLaunch();
}

