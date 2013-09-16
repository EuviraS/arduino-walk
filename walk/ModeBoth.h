#ifndef MODEBOTHCLASS_H_INCLUDED
#define MODEBOTHCLASS_H_INCLUDED

#include "ModeInterface.h"

class ModeBoth : public ModeInterface {
  public:
    ModeBoth(int* leds);
    void init();
    void loop();
  
  private:
    int* _leds;
};

#endif

