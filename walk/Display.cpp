#include "Display.h"
#include "Arduino.h"
#include "common.h"

Display::Display(int* leds)
{
  _leds = leds;
}

Display::~Display() { }

void Display::show(int idx)
{
  SPrint("Showing ");
  SPrintln(idx);
  digitalWrite(_leds[1-idx], LOW);
  digitalWrite(_leds[idx], HIGH);  
}

void Display::hide()
{
  SPrintln("Hiding");
  digitalWrite(_leds[0], LOW);
  digitalWrite(_leds[1], LOW);  
}
