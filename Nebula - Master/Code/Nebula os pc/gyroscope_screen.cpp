#include "gyroscope_screen.h"

void drawGyroscopeScreen(){
  tft.setCursor(centrex - 100, centrey - 30);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.print("Rotation X: ");
  tft.setCursor(centrex + 30, centrey - 30);
  tft.print(g.gyro.x);
  tft.setCursor(centrex+10, centrey);
  tft.print("Y: ");
  tft.setCursor(centrex +40, centrey);
  tft.print(g.gyro.y);
  tft.setCursor(centrex+10, centrey + 30);
  tft.print("Z: ");
  tft.setCursor(centrex +40, centrey + 30);
  tft.print(g.gyro.z);
    tft.setCursor(centrex-40,centrey+50);
  tft.print("temp: ");
  tft.setCursor(centrex+25,centrey+50);
  tft.print(temp.temperature);
  tft.setCursor(centrex - 40, centrey + 80);
  tft.print(" rad/s");
}
