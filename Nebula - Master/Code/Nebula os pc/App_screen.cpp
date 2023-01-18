#include "App_screen.h"

void drawApp(int Angle, int appRadius, int appIconRadius, int colour) //function to draw an filled circle at angle 
{
    int x;
    int y;
    float radian = Angle * 0.0174533;
    radian = -radian;
    y = appRadius * sin(radian);
    x = appRadius * cos(radian);
    y = y + centrey;
    x = x + centrex;
    tft.fillCircle(x, y, appIconRadius, colour);
}
void drawAppScreen()
{
    drawApp(0, 80, 25, 0xF8E6);   // fire truck
    tft.drawBitmap(60+centrex,centrey-20,stopwatchIcon,40,40,TFT_WHITE);
    drawApp(45, 80, 25, 0x7215);  // violet
    tft.drawBitmap(37+centrex,centrey-75,accelerometerIcon,40,40,TFT_WHITE);
    drawApp(90, 80, 25, 0x4215);  // lavender
    tft.drawBitmap(centrex-20,centrey-100,gyroscopeIcon,40,40,TFT_WHITE);
    drawApp(135, 80, 25, 0x3B9B); // sky
    tft.drawBitmap(centrex-85,centrey-85,bluetoothIcon,60,60,TFT_WHITE);
    drawApp(180, 80, 25, 0x3E1B); // bodacious blue
    tft.drawBitmap(centrex- 99,centrey-20,microphoneIcon,40,40,TFT_WHITE);
    drawApp(225, 80, 25, 0x3EF7); // terrific turquoise
    tft.drawBitmap(centrex-80,centrey+35,speakerIcon,50,50,TFT_WHITE);
    drawApp(270, 80, 25, 0x3EEF); // razer green
    tft.drawBitmap(centrex-15,centrey+65,wrenchIcon,30,30,TFT_WHITE);
    drawApp(315, 80, 25, 0xDD07); // orange
    tft.drawBitmap(centrex+35,centrey+40,wifiIcon,40,40,TFT_WHITE);
   
    tft.setCursor(centrex - 20, centrey - 15);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.println(theTime);
}
