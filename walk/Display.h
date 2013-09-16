#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

class Display
{
  public:
    Display(int* leds);
    ~Display();
    void show(int idx);
    void hide();
    
  private:
    int* _leds;
};

#endif
