#ifndef BB_Hex_Module_h
#define BB_Hex_Module_h

#include "Arduino.h"

class Hex_Module
{
  public:
	Hex_Module(int reedPin, int topLedPin, int leftLedPin, int rightLedPin);
    void startHexModule();
    boolean powerOn;
  private:
    boolean poweringUpFinished;
	int _reedPin;
	int _topLedPin;
	int _leftLedPin;
	int _rightLedPin;
  };

  
#endif 