
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Arduino.h"
#include "RTClib.h"
#include <SPI.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <TFT_eSPI.h>
#define centrey 120
#define centrex 120
#include "counting_and_bezel.h"

extern TFT_eSPI tft;

extern Adafruit_MPU6050 mpu;
extern sensors_event_t a, g, temp;
extern RTC_PCF8523 rtc;

extern int menu; // current menu
extern int item; // current item selected
extern bool redrawProtect;
extern bool homeIncrementProtect; //stops from immediately going through all menus
extern bool selectIncrementProtect; //stops from immediately going through all menus
extern unsigned long time_now;
extern bool running;
extern bool homePressed;
extern bool selectPressed;
extern bool selectorRedrawProtect;
extern bool BL;
extern String theTime;
extern int RTCSetting;

extern int currentHour;
extern int currentMinute;
void menuSwitching();
void drawRTCAdjust();

void sleepManager();
void timeRefresh();
void RTCtest();
void timeWithMillis();
#endif
