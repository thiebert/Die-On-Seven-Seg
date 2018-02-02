#ifndef Die_h
#define Die_h

#include "Arduino.h"

class DieInput
{
  public:
    DieInput(int dieSize, int pin);
    bool pressed();
    int roll();
  private:
    int _pin;
    int _size;
    int _reading;
    int _previous;
};
#endif

