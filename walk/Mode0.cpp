#include "Arduino.h"
#include "Mode0.h"

Mode0::Mode0(Display* display, int waitingPin, int* blinkingLeds) { 
  _display = display; 
  _pin = waitingPin;
  _blinkingLeds = blinkingLeds;
}
Mode0::~Mode0() { }

void Mode0::init() 
{
  _status = STATUS_BLINKING;
  T_last_step = millis();
  idx = 1;
  _display->show(idx);
}

void Mode0::loop()
{
  unsigned long t = millis();
  switch(_status)
  {
    case STATUS_BLINKING: blinking(t); break;
    case STATUS_WAITING: waiting(t); break;
  }
}

void Mode0::blinking(unsigned long t) {
  int blink_step = (t - T_last_step) / Mode0::BLINK_DELAY;
  //Serial.print("Blinking ");
  //Serial.println(blink_step);
  if (blink_step > 2*BLINK_COUNT)
  {
    // Finished blinking
    _status = STATUS_WAITING;
    idx = 1-idx;
    _display->show(idx);
    T_last_step = t;
    return;
  }
  
  if ((blink_step % 2) == 0)
  {
    _display->show(idx);
  }
  else
  {
    _display->hide();
  }
}

void Mode0::waiting(unsigned long t) {
  int val = analogRead(_pin);
  //Serial.print("Waiting ");
  //Serial.print((int) 100 * (t - t_last_step) / (WAITING_MAX * val / 1023));
  //Serial.println("%");
  if ((t - T_last_step) > Mode0::WAITING_MAX * val / 1023)
  {
    T_last_step = t;
    if (_blinkingLeds[idx] == 1)
    {
      _status = Mode0::STATUS_BLINKING;
    }
    else
    {
      // Skip blinking
      idx = 1 - idx;
      _display->show(idx);
    }
  }
}

