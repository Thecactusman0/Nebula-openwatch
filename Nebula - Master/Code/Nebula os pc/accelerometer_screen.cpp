#include "accelerometer_screen.h"

void drawAccelerometerScreen(){
  tft.setCursor(centrex-70,centrey -60);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.print("Acceleration");
  tft.setCursor(centrex-40,centrey-30);
  tft.print("X: ");
  tft.setCursor(centrex -10, centrey -30);
  tft.print(a.acceleration.x);
  tft.setCursor(centrex-40,centrey);
  tft.print("Y: ");
  tft.setCursor(centrex-10,centrey);
  tft.print(a.acceleration.y);
  tft.setCursor(centrex-40,centrey+30);
  tft.print("Z: ");
  tft.setCursor(centrex-10,centrey+30);
  tft.print(a.acceleration.z);
  tft.setCursor(centrex-40,centrey+50);
  tft.print("temp: ");
  tft.setCursor(centrex+25,centrey+50);
  tft.print(temp.temperature);
  tft.setCursor(centrex-40,centrey+80);
  tft.print(" m/s^2");
}
