#include "selector_management.h"
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
    tft.drawCircle(x, y, iconRadius + 2, TFT_WHITE);
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
    tft.drawCircle(x, y, iconRadius + 2, TFT_BLACK);
    radian = (angle + oAngle) * 0.0174533;
    radian = -radian;
    y = radius * sin(radian);
    x = radius * cos(radian);
    y = y + centrey;
    x = x + centrex;
    tft.drawCircle(x, y, iconRadius + 2, TFT_BLACK);
}

void selector()//enables selector on correct menus
{
    //serialItemCounting();
    bezelCounting();
    switch (menu)
    {
    case 1:
        if (selectorRedrawProtect == false)
        {
            drawSelector(45 * item, 80, 25);
            clearSelector(45 * item, 80, 25, 45);
            selectorRedrawProtect = true;
        }
        break;
    }
}
