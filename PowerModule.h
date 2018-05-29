#ifndef PowerModule_h
#define PowerModule_h

#include "Arduino.h"

class PowerModule
{
  public:
	PowerModule();
    void runPowerModule();
    boolean powerOn;
  private:
    boolean poweringUpFinished;
  };

  
#endif  
