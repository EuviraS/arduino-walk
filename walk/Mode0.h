#ifndef MODE0_H_INCLUDE
#define MODE0_H_INCLUDE

#include "ModeInterface.h"
#include "Display.h"

class Mode0 : public ModeInterface {
  public:
    Mode0(Display* display, int waitingPin, int* blinkingLeds);
    ~Mode0();
    void init();
    void loop();
    
  private:
    int _status;
    int idx;
    int *_blinkingLeds;
    unsigned long T_last_step;
    static const int STATUS_BLINKING = 0;
    static const int STATUS_WAITING = 1;
    static const unsigned long WAITING_MAX = 120000;
    static const unsigned long BLINK_DELAY = 500;
    static const int BLINK_COUNT = 4;
    Display* _display;
    void blinking(unsigned long t);
    void waiting(unsigned long t);
    int _pin;
};

#endif

