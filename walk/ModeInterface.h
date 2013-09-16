#ifndef MODEINTERFACE_H_INCLUDED
#define MODEINTERFACE_H_INCLUDED

class ModeInterface
{
  public:
    virtual void init() = 0;
    virtual void loop() = 0;
};

#endif
