#ifndef MODEONECLASS_H_INCLUDED
#define MODEONECLASS_H_INCLUDED

#include "ModeInterface.h"
#include "Display.h"

class ModeOne : public ModeInterface {
  public:
    ModeOne(Display* display, int idx);
    void init();
    void loop();
    
  private:
    int _idx;
    Display *_display;
};

#endif
