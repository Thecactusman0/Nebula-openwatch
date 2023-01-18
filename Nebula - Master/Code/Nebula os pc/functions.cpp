#include "functions.h"
#include "buttonsMenu.h"

int lastState12;
int lastState22;
int lastState32;
int state12;
int state22;
int state32;
bool selectorRedrawProtect = false;
int menu =0;
int item =0;
bool redrawProtect = false;
bool homeIncrementProtect = true; //stops from immediately going through all menus
bool selectIncrementProtect = true; //stops from immediately going through all menus
bool homePressed = true;
bool selectPressed = true;

unsigned long time_now = 0;
bool running = false;
bool replayProtect = false;

  unsigned long previousMillis = 0;

  const long interval = 15000;

unsigned long theMillis;

String theTime;
bool BL = true;
  unsigned int durMM2;
   unsigned int durHH2;
   


int currentHour;
int currentMinute;
int RTCSetting;








String timeMillis2(unsigned long Hourtime,unsigned long Mintime)
{
  String dataTemp = "";

  if (Hourtime < 10)
  {
    dataTemp = dataTemp + "0" + String(Hourtime)+':';
  }
  else if (Hourtime >9&&Hourtime < 13)
  {
    dataTemp = dataTemp + String(Hourtime)+':';
  }
  else{
    dataTemp = dataTemp + String(Hourtime-12)+':';
  }
  
  if (Mintime < 10)
  {
    dataTemp = dataTemp + "0" + String(Mintime);
  }
  else{
    dataTemp = dataTemp + String(Mintime);
  }
 
  return dataTemp;
}

void timeWithMillis(){
DateTime now = rtc.now();
int beans;
if (beans = 0){
 currentHour = now.hour();
 currentMinute = now.minute();
 beans = 1;
}
unsigned long int  timeMillis = (now.hour()*3600000)+(now.minute()*60000)+millis();
//Serial.println(timeMillis);
  
  
    durMM2 = ( timeMillis/60000)%60; //Minutes
   durHH2 = ( timeMillis/3600000);  //Hours
   durHH2 = durHH2 % 24;
//Serial.println(durMM2);
//Serial.println(durHH2);
   theTime = timeMillis2(durHH2,durMM2);
   //Serial.print(theTime);
}


void drawRTCAdjust(){
  pinMode(16, INPUT_PULLUP);
pinMode(17, INPUT_PULLUP);
pinMode(19, INPUT_PULLUP);
  state12 = digitalRead(19)  ;
state22 = digitalRead(17)  ;
state32 = digitalRead(16)  ;
if(RTCSetting == 1){
  tft.setTextColor(TFT_BLACK,TFT_WHITE);
  tft.setCursor(centrex-50,centrey);
  tft.println(currentHour);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setCursor(centrex-20,centrey);
  tft.println(":");
  tft.setCursor(centrex+10,centrey);
  tft.println(currentMinute);
}else if (RTCSetting == 2){
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setCursor(centrex-50,centrey);
  tft.println(currentHour);

  tft.setCursor(centrex-20,centrey);
  tft.println(":");
    tft.setTextColor(TFT_BLACK,TFT_WHITE);
  tft.setCursor(centrex+10,centrey);
  tft.println(currentMinute);
}else{
      tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setCursor(centrex-50,centrey);
tft.println(currentHour);
tft.setCursor(centrex-20,centrey);
  tft.println(":");
  tft.setCursor(centrex+10,centrey);
  tft.println(currentMinute);
  
}
 if (RTCSetting == 1){
  if (state12 == 0){
  if (lastState22 == 0){
  currentHour--;
  lastState22 = 1;
  lastState12 = 0;
  redrawProtect = false;
  selectorRedrawProtect = false;
tft.fillScreen(TFT_BLACK);
  }
  if (lastState32 == 0){
  currentHour++;
  lastState32 = 1;
  lastState12 = 0;
redrawProtect = false;
selectorRedrawProtect = false;
tft.fillScreen(TFT_BLACK);
  }
}
if (state22 == 0){
  if (lastState12 == 0){
  currentHour++;
  lastState12 = 1;
  lastState22 = 0;
 redrawProtect = false;
 selectorRedrawProtect = false;
 tft.fillScreen(TFT_BLACK);
  }
  if (lastState32 == 0){
  item--;
  lastState32 = 1;
  lastState22 = 0;
redrawProtect = false;
selectorRedrawProtect = false;
tft.fillScreen(TFT_BLACK);
  }
}
if (state32 == 0){
  if (lastState1 == 0){
  currentHour--;
  lastState12 = 1;
  lastState32 = 0;
 redrawProtect = false;
 selectorRedrawProtect = false;
 tft.fillScreen(TFT_BLACK);
  }
  if (lastState22 == 0){
  currentHour++;
  lastState22 = 1;
  lastState32 = 0;
redrawProtect = false;
selectorRedrawProtect = false;
tft.fillScreen(TFT_BLACK);
  }
}
if(currentHour == 25){
  currentHour=0;
}else if (currentHour == -1){
  currentHour=24;
}
Serial.print(currentHour);

}
}







void sleepManager(){

}


void timeRefresh(){
mpu.getEvent(&a, &g, &temp);

theMillis = millis();
if (g.gyro.x < -13 && a.acceleration.y > 8.5){
BL = true;
Serial.print("with the flick of my wrist");
 previousMillis = theMillis-58000;
}
//Serial.println(g.gyro.x);
  if (theMillis - previousMillis >= interval) {
    previousMillis = theMillis;
    redrawProtect = false;
    BL = false;
     esp_sleep_enable_ext0_wakeup(GPIO_NUM_1,0); //1 = High, 0 = Low
  }
  if(BL == false){
    digitalWrite(2,LOW);
    esp_light_sleep_start();
    menu = 0;
    Serial.print("this where we left off");
    BL = true;
    
    }else{
    digitalWrite(2,HIGH);
    }
}
void RTCtest(){
DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    //print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(3000);
}
