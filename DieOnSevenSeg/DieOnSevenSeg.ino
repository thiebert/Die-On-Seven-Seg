#include "dieInput.h"

DieInput d6pin(6, 2);
int onesPin = 3;

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
int roll = 0;

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

void setup()
{
  for (int pin=onesPin; pin < onesPin + 7; pin++) {
   pinMode(pin,OUTPUT);
  }
}

void loop()
{
  if (millis() - time > debounce)
  {
    if (d6pin.pressed()) roll = d6pin.roll();    
  }
  Num_Write(roll);
}

// this functions writes values to the sev seg pins  
void Num_Write(int number) 
{
  int ones = number % 10;
  int pin = onesPin;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[ones][j]);
   pin++;
  }
}
