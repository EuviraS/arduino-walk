#include "ModeBoth.h"
#include "Arduino.h"

ModeBoth::ModeBoth(int* leds) {
  _leds = leds;
}

void ModeBoth::init() {
  digitalWrite(_leds[0], HIGH);
  digitalWrite(_leds[1], HIGH);
}

void ModeBoth::loop() { }
