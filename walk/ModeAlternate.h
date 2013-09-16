#ifndef MODEALTERNATECLASS_H_INCLUDED
#define MODEALTERNATECLASS_H_INCLUDED

#include "Display.h"
#include "ModeInterface.h"

class ModeAlternate : public ModeInterface {
  public:
    ModeAlternate(Display* display, int waitingPin);
    void init();
    void loop();
  private:
    Display* _display;
    int _pin;
    static const unsigned long BLINKING_MAX_TIME = 30000;
    int _idx;
    unsigned long T_last_step;
};

#endif

