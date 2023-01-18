#include "buttonsMenu.h"
#include "functions.h"
//#include "wifi_update.h"
TFT_eSPI tft = TFT_eSPI();
Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;
RTC_PCF8523 rtc;
void setup() {
/*
WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
 arduinoOTA();
*/
    Wire.begin(12,13);
    mpu.begin();
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    rtc.start();
    tft.init();
    tft.begin();
    tft.setRotation(0);        // rotate screen to be right
    tft.fillScreen(TFT_BLACK);//clear screen
    //mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
   mpu.setGyroRange(MPU6050_RANGE_2000_DEG);
    //mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    pinMode(0,INPUT_PULLUP);
    pinMode(1,INPUT_PULLUP);//setup button pins as inputs
Serial.begin(115200);
Serial.print("we are up");
tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
}

void loop() {
homePressed = digitalRead(0);
selectPressed = digitalRead(1);
homeCheck();
selectCheck();
drawMenu();
// ArduinoOTA.handle();
}
