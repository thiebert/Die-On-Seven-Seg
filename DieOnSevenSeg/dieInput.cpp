#include "DieInput.h"
#include "Arduino.h"

DieInput::DieInput(int dieSize, int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _size = dieSize;
  _previous = LOW;
}

bool DieInput::pressed()
{
  _reading = digitalRead(_pin);
  bool output = _reading == HIGH && _previous == LOW;
  _previous = _reading;
  return output;
}

int DieInput::roll()
{
  if (_size >= 100)
  {
    return random(100);
  }
  else
  {
    return random(1, _size + 1);
  }
}

