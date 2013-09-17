#include "Display.h"
#include "Mode0.h"
#include "ModeOne.h"
#include "ModeBoth.h"
#include "ModeAlternate.h"

#include "common.h"

/*
const int STATUS_WAITING = 1;
const int STATUS_BLINKING = 2;
int BLINK_COUNT = 3;
unsigned long BLINK_DELAY = 500;
unsigned long WAITING_MAX = 120000;

unsigned long BLINK_MODE_MAX = 60000;

int idx = 0;
int l_status = STATUS_BLINKING;

unsigned long t_last_step = 0;

*/

// Analog input read
int pin = A0;

// Leds connected
int leds[2] = {2, 7};

// Interrup pin
int interrupt_pin = 1; // Means pin 3

// Default mode
int mode = 0;
int last_mode = -1;

// Display var
Display display(leds);


// Blinking leds for mode0
int blinking_leds[2] = {0, 1};
Mode0 mode0(&display, pin, blinking_leds);

ModeOne mode1(&display, 0);
ModeOne mode2(&display, 1);

ModeBoth mode3(leds);

ModeAlternate mode4(&display, pin);

ModeInterface* modes[] = {&mode0, &mode1, &mode2, &mode3, &mode4};

void setup()
{
#if DEBUG == 1
  Serial.begin(9600);
#endif
  
  attachInterrupt(interrupt_pin, change_mode, FALLING);
  
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);

  startup_demo();  
}

void startup_demo()
{
  // Small trick :)
  int demo_delay = 500;
  delay(demo_delay);
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], LOW);
  delay(demo_delay);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[0], LOW);
  delay(demo_delay);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[0], HIGH);
  delay(demo_delay);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  delay(2*demo_delay);
}

void loop()
{
  int cur_mode = mode;
  if (last_mode != cur_mode)
  {
    SPrint("Changing mode : now mode ");
    SPrintln(mode);
    last_mode = cur_mode;
    modes[cur_mode]->init();
  }
  modes[cur_mode]->loop();
}

void change_mode()
{
  mode = (mode + 1) % 5;
}


/*
void init_mode_4()
{
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
}

void loop_mode_4() { }
*/

/** MODE 3 BLINKING ALTERNATIVELY **/
/*
void init_mode_3()
{
  t_last_step = millis();
  idx = 0;
  show();
}

void loop_mode_3()
{
  unsigned long t = millis();
  int val = analogRead(pin);

  if ((t - t_last_step) > 60000 * val / 1023)
  {
    // switch idx
    idx = 1-idx;
    // Save last step
    t_last_step = t;
  }
  show();
}
*/

/** MODE 1 ONLY **/
/*
void init_mode_1()
{
  idx = 0;
  show();
}

void loop_mode_1() { }
*/

/** MODE 2 ONLY **/
/*
void init_mode_2()
{
  idx = 1;
  show();
}

void loop_mode_2() { }
*/

/** NORMAL MODE : WAITING, THEN BLINKING, THEN SWITCH A DO IT AGAIN **/

/*
void init_mode_0()
{
  t_last_step = millis();
  idx = 1;
  show();
}

void loop_mode_0() 
{
  unsigned long t = millis();
  switch(l_status)
  {
    case STATUS_BLINKING: blinking(t); break;
    case STATUS_WAITING: waiting(t); break;
  }
}

void waiting(unsigned long t)
{
  int val = analogRead(pin);
  //Serial.print("Waiting ");
  //Serial.print((int) 100 * (t - t_last_step) / (WAITING_MAX * val / 1023));
  //Serial.println("%");
  if ((t - t_last_step) > WAITING_MAX * val / 1023)
  {
    if (blinking_leds[idx] == 1)
    {
      l_status = STATUS_BLINKING;
      t_last_step = t;
    }
    else
    {
      // Skip blinking
      t_last_step = t;
      idx = 1 - idx;
      show();
    }
  }
}


void blinking(unsigned long t)
{
  int blink_step = (t - t_last_step) / BLINK_DELAY;
  //Serial.print("Blinking ");
  //Serial.println(blink_step);
  if (blink_step > 2*BLINK_COUNT)
  {
    // Finished blinking
    l_status = STATUS_WAITING;
    idx = 1-idx;
    show();
    t_last_step = t;
    return;
  }
  
  if ((blink_step % 2) == 0)
  {
    show();
  }
  else
  {
    hide();
  }
}
*/

/** GENERIC FUNCTIONS **/
/*
void show()
{
  digitalWrite(leds[1-idx], LOW);
  digitalWrite(leds[idx], HIGH);
}

void hide()
{
  digitalWrite(leds[1-idx], LOW);
  digitalWrite(leds[idx], LOW);
}
*/

