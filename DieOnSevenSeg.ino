#include "dieInput.h"

DieInput d4pin(4, 2); 
DieInput d6pin(6, 3);
DieInput d8pin(8, 4);
DieInput d10pin(10, 5);
DieInput d12pin(12, 6);
DieInput d20pin(20, 7);
DieInput d00pin(100, 8);
int onesPin = 13;
int tensPin = 20;

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
  for (int pin=tensPin; pin < tensPin + 7; pin++) {
   pinMode(pin,OUTPUT);
  }
}

void loop()
{
  if (millis() - time > debounce)
  {
    if (d4pin.pressed()) roll = d4pin.roll();
    else if (d6pin.pressed()) roll = d6pin.roll();    
    else if (d8pin.pressed()) roll = d8pin.roll();    
    else if (d10pin.pressed()) roll = d10pin.roll();    
    else if (d12pin.pressed()) roll = d12pin.roll();    
    else if (d20pin.pressed()) roll = d20pin.roll();    
    else if (d00pin.pressed()) roll = d00pin.roll();
  }
  Num_Write(roll);
}

// this functions writes values to the sev seg pins  
void Num_Write(int number) 
{
  int ones = number % 10;
  int tens = number / 10;
  int pin = onesPin;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[ones][j]);
   pin++;
  }
  pin = tensPin;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[tens][j]);
   pin++;
  }
}
