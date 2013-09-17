#include "ModeAlternate.h"
#include "Arduino.h"

ModeAlternate::ModeAlternate(Display* display, int waitingPin) {
  _display = display;
  _pin = waitingPin;
  _idx = 0;
}

void ModeAlternate::init() {
  _display->show(_idx);
  T_last_step = millis();
}

void ModeAlternate::loop() {
  unsigned long t = millis();
  unsigned long val = analogRead(_pin);

  if ((t - T_last_step) > BLINKING_MAX_TIME * val / 1023)
  {
    // switch idx
    _idx = 1 - _idx;
    // Save last step
    T_last_step = t;
  }
  _display->show(_idx);
}

