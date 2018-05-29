#ifndef Launcher_Module_h
#define Launcher_Module_h

#include "Arduino.h"

class Launcher_Module
{
  public:
	Launcher_Module(int launcherVccPin, int launcherInputPin, int buzzerPin);
    void updateLauncherModule();

  private:
	void runLaunch();
	int _launcherVccPin;
	int _launcherInputPin;
	int _buzzerPin;
	boolean launching;
	int startBuzzerHz;
	int maxBuzzerHz;
	int currentBuzzerHz;
  };

  
#endif 