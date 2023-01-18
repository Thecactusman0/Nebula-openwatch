#ifndef COUNTING_AND_BEZEL_H
#define COUNTING_AND_BEZEL_H
#include "Arduino.h"
#include "functions.h"
void serialItemCounting();
void bezelCounting();
extern int lastState1;
extern int lastState2;
extern int lastState3;
extern int state1;
extern int state2;
extern int state3;
#endif
