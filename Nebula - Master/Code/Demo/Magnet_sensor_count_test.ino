#include <TFT_eSPI.h>


int lastState1; //last state of hall effect sensor 1
int lastState2; //last state of hall effect sensor 2
int lastState3; //last state of hall effect sensor 3
int state1;//current state of hall effect sensor 1
int state2;//current state of hall effect sensor 2
int state3;//current state of hall effect sensor 3
int count;//current incrementation count

#define ms1 19 //hall effect sensor pins
#define ms2 17
#define ms3 16

#define centrey 120 //graphics are all based around the defined centre of the screen
#define centrex 120


TFT_eSPI tft;


void setup() {
  tft.begin();//start display
  tft.fillScreen(TFT_BLACK);//flush display
  
 
pinMode(ms1, INPUT_PULLUP);
pinMode(ms2, INPUT_PULLUP);
pinMode(ms3, INPUT_PULLUP);


tft.setTextSize(2);
tft.setCursor(centrex-20,centrey-40);
tft.print("HES2");
tft.setCursor(centrex-80,centrey-40);
tft.print("HES1");
tft.setCursor(centrex+40,centrey-40);
tft.print("HES3");
tft.fillRect(centrex-20,centrey-20,50,20,TFT_RED);//set the indicators to red
tft.fillRect(centrex-80,centrey-20,50,20,TFT_RED);
tft.fillRect(centrex+40,centrey-20,50,20,TFT_RED);
tft.fillRect(centrex-20,centrey+10,50,20,TFT_RED);
tft.fillRect(centrex-80,centrey+10,50,20,TFT_RED);
tft.fillRect(centrex+40,centrey+10,50,20,TFT_RED);
}

void loop() {
 
state1 = digitalRead(ms1)  ;//read the state of the hall effect sensor
state2 = digitalRead(ms2)  ;
state3 = digitalRead(ms3)  ;


drawIndicators();//draw the graphical indicatosr for the statre of the hall effect sensors
check();//check if the state of the sensors have changed and apply the changes to the count variable

if(count>=24){//reset the count back to 0 when it reaches the end
  count = 0;
}
if(count<=-1){
  count = 23;
}

//print the count
tft.setCursor(centrex,centrey+50);
tft.setTextColor(TFT_WHITE,TFT_BLACK);
tft.fillRect(centrex,centrey+50,50,20,TFT_BLACK);
tft.print(count);

drawSelector(15 * count, 100, 5);//draw the white dot around the outside to show the count visually
clearSelector(15 * count, 100, 5, 15); //clear the dots
}

void drawSelector(int angle, int radius, int iconRadius)//draws TFT_white ring around current item
{
    int x;
    int y;
    float radian = angle * 0.0174533;
    radian = -radian;
    y = radius * sin(radian);
    x = radius * cos(radian);
    y = y + centrey;
    x = x + centrex;
    tft.fillCircle(x, y, iconRadius + 2, TFT_WHITE);
}

void clearSelector(int angle, int radius, int iconRadius, int oAngle)//removes last drawn selector
{
    int x;
    int y;
    float radian = (angle - oAngle) * 0.0174533;
    radian = -radian;
    y = radius * sin(radian);
    x = radius * cos(radian);
    y = y + centrey;
    x = x + centrex;
    tft.fillCircle(x, y, iconRadius + 2, TFT_BLACK);
    radian = (angle + oAngle) * 0.0174533;
    radian = -radian;
    y = radius * sin(radian);
    x = radius * cos(radian);
    y = y + centrey;
    x = x + centrex;
    tft.fillCircle(x, y, iconRadius + 2, TFT_BLACK);
}








void check(){
if (state1 == 0){
  if (lastState2 == 0){
  count--;
  lastState2 = 1;
  lastState1 = 0;

  }
  if (lastState3 == 0){
  count++;
  lastState3 = 1;
  lastState1 = 0;

  }
}
if (state2 == 0){
  if (lastState1 == 0){
  count++;
  lastState1 = 1;
  lastState2 = 0;
 
  }
  if (lastState3 == 0){
  count--;
  lastState3 = 1;
  lastState2 = 0;

  }
}
if (state3 == 0){
  if (lastState1 == 0){
  count--;
  lastState1 = 1;
  lastState3 = 0;
 
  }
  if (lastState2 == 0){
  count++;
  lastState2 = 1;
  lastState3 = 0;

  }
}

}

void drawIndicators(){
if (state2 == 0){
tft.fillRect(centrex-20,centrey-20,50,20,TFT_GREEN);  
}else{
tft.fillRect(centrex-20,centrey-20,50,20,TFT_RED);  
}

if(state1==0){
  tft.fillRect(centrex-80,centrey-20,50,20,TFT_GREEN);
}else{
  tft.fillRect(centrex-80,centrey-20,50,20,TFT_RED);
}

if(state3==0){
 tft.fillRect(centrex+40,centrey-20,50,20,TFT_GREEN); 
}else{
  tft.fillRect(centrex+40,centrey-20,50,20,TFT_RED);
}
if (lastState2 == 0){
tft.fillRect(centrex-20,centrey+10,50,20,TFT_GREEN);  
}else{
tft.fillRect(centrex-20,centrey+10,50,20,TFT_RED);  
}

if(lastState1==0){
  tft.fillRect(centrex-80,centrey+10,50,20,TFT_GREEN);
}else{
  tft.fillRect(centrex-80,centrey+10,50,20,TFT_RED);
}

if(lastState3==0){
 tft.fillRect(centrex+40,centrey+10,50,20,TFT_GREEN); 
}else{
  tft.fillRect(centrex+40,centrey+10,50,20,TFT_RED);
}

}
