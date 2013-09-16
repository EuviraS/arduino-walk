#include "ModeOne.h"

ModeOne::ModeOne(Display* display, int idx) {
  _display = display;
  _idx = idx;
}

void ModeOne::init() {
  _display->show(_idx);
}

void ModeOne::loop() { }

