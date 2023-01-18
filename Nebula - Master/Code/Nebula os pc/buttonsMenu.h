#ifndef BUTTONSMENU_H
#define BUTTONSMENU_H
#include "Arduino.h"
#include "functions.h"
#include "accelerometer_screen.h"
#include "gyroscope_screen.h"
#include "selector_management.h"
#include "counting_and_bezel.h"
#include "watch_face.h"
#include "stopwatch_screen.h"
#include "App_screen.h"
extern bool redrawProtect;
void homeCheck();
void selectCheck();
void drawMenu();
#endif
