#include "watch_face.h"

float distance = 1.23;
int battPercent = 0;
int stepCount = 2325;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void drawArc(int xdis, int ydis, int c, int s, int e, int r, int colour)
{ // x,y,circle radius,start angle, end angle, arc radius,colour
    // the coords are relative to the centrepoint of the arc, circle radius is the thickness of the arc, angles are given in unit circle form
    float radian = 0.0174533 * s;
    int x;
    int y;
    while (radian * 57.2958 < e)
    {
        y = r * sin(radian);
        x = r * cos(radian);
        y = y + ydis;
        x = x + xdis;
        tft.fillCircle(x, y, c, colour);
        radian = radian + 0.0174533;
    }
}
void drawHScreen() //draws the home screen in full
{
  // x,y,circle radius,start angle(unit circle 0 anticlockwise), end angle, arc radius,rgb 565 value i suggest this website http://www.rinkydinkelectronics.com/calc_rgb565.php
DateTime now = rtc.now();
    int battADC = analogRead(18);
    Serial.println(battADC);
    int y = map(battADC+55, 930, 1100, 90, 271);
    if(y>270){
      y = 270;
    }
    Serial.println(y);
    battPercent = map(battADC+55, 930, 1100, 0, 101);
    Serial.println(battPercent);
    //drawArc(centrex, centrey, 7, 90, 270, 60, 0x2046);
    //drawArc(centrex, centrey, 7, 90, 270, 80, 0x2046);
    //drawArc(centrex, centrey, 7, 90, 270, 100,0x2046);
    drawArc(centrex, centrey, 7, 90,y, 60, 0xFE20 ); 
    drawArc(centrex, centrey, 7, 90, 210, 80, 0xFC80);      
    drawArc(centrex, centrey, 7, 90, 180, 100,0xD881); 
    tft.setTextSize(1);
    tft.setCursor(centrex + 10, centrey + 55);
    tft.setTextColor(0xFE20);
    tft.println("Battery");
    tft.setCursor(centrex + 10, centrey + 75);
    tft.setTextColor(0xFC80);
    tft.println("Distance");
    tft.setCursor(centrex + 10, centrey + 95);
    tft.setTextColor(0xD881);
    tft.println("Steps");
    tft.setCursor(centrex + 10, centrey - 60);
    tft.setTextColor(0xFE20);
    tft.println(battPercent);
    tft.setCursor(centrex + 30, centrey - 60);
    tft.println("%");
    tft.setCursor(centrex + 45, centrey - 60);
    tft.println(battADC);
    tft.setCursor(centrex + 10, centrey - 80);
    tft.setTextColor(0xFC80);
    tft.print(distance);
    tft.setCursor(centrex + 10, centrey - 100);
    tft.setTextColor(0xD881);
    tft.println(stepCount);
    tft.setCursor(centrex - 40, centrey - 10);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(4);
    tft.println(theTime);
    tft.setCursor(centrex - 15, centrey + 25);
    tft.setTextSize(2);
    tft.println("16/1/2023");
    tft.setCursor(centrex - 15, centrey - 40);
    tft.println(daysOfTheWeek[now.dayOfTheWeek()]);
    //redrawProtect = true;

}
