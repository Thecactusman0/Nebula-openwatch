#ifndef SELECTOR_MANAGEMENT_H
#define SELECTOR_MANAGEMENT_H
#include "Arduino.h"
#include "functions.h"
#include "counting_and_bezel.h"
void clearSelector(int angle,int radius,int iconRadius,int oAngle);
void drawSelector(int angle,int radius,int iconRadius);
void selector();
#endif
