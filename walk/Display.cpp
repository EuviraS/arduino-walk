#include "Display.h"
#include "Arduino.h"

Display::Display(int* leds)
{
  _leds = leds;
}

Display::~Display() { }

void Display::show(int idx)
{
  digitalWrite(_leds[1-idx], LOW);
  digitalWrite(_leds[idx], HIGH);  
}

void Display::hide()
{
  digitalWrite(_leds[0], LOW);
  digitalWrite(_leds[1], LOW);  
}
