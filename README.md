arduino-walk
============

Arduino script for a walk / don't walk lights.

How it works
------------

You define 2 pins that correspond to your leds / relay, and use one of 4 available modes :

* Mode 1 (default mode) : Red is on for some time, then Green goes one, red down, for the same time. After that period of time, green blinks, and the the lights go back to red only ;
* Mode 2 (ModeOne) : one light is on ;
* Mode 3 (ModeBoth) : both lights are on ;
* Mode 4 (ModeAlternate) : lights are blinking, green, then red, the green, and so on.

Add your own mode !
-------------------

You can add your own mode by creating a C++ class that extends ModeInterface abstract class.

    #include "ModeInterface.h"
    
    class MyMode : public ModeInterface {
      public:
        // Constructor
        MyMode();
        // Functionnal behaviors
        void init();
        void loop();
    };

