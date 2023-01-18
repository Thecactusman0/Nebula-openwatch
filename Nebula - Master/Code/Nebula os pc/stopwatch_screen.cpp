#include "stopwatch_screen.h"

bool stopwatchIncrementProtect = true;
unsigned long elapsedMillis;
unsigned long startMillis;
unsigned long currentMillis;
String durMilliSec;

String timeMillis(unsigned long Hourtime,unsigned long Mintime,unsigned long Sectime,unsigned long MStime)
{
  String dataTemp = "";

  if (Hourtime < 10)
  {
    dataTemp = dataTemp + "0" + String(Hourtime)+ "h:";
  }
  else{
    dataTemp = dataTemp + String(Hourtime)+ "h:";
  }
  
  if (Mintime < 10)
  {
    dataTemp = dataTemp + "0" + String(Mintime)+ "m:";
  }
  else{
    dataTemp = dataTemp + String(Mintime)+ "m:";
  }
  
  if (Sectime < 10)
  {
    dataTemp = dataTemp + "0" + String(Sectime)+ "s:";
  }
  else{
    dataTemp = dataTemp + String(Sectime)+ "s:";
  }
  
  dataTemp = dataTemp + String(MStime);

  
  return dataTemp;
}

void stopwatchScreen()
{

   tft.setTextColor(TFT_WHITE,TFT_BLACK);
   long unsigned  int currentMillis = millis();
   elapsedMillis = (currentMillis - startMillis);
    int durMS = (elapsedMillis%1000);       //Milliseconds
    int durSS = (elapsedMillis/1000)%60;    //Seconds
   int durMM = (elapsedMillis/(60000))%60; //Minutes
   int durHH = (elapsedMillis/(3600000));  //Hours
   durHH = durHH % 24;
  if(selectPressed == true)
{

   if(stopwatchIncrementProtect==false)  {
     stopwatchIncrementProtect = true;

     
   
     if(running == true)
     {
      
        
        durMS = 0;
        durSS = 0;
        durMM = 0;
        durHH = 0;
        running = false; 
        Serial.print("running true to false");
        goto run;
        
     }
     
     if(running==false)
     {
 
        durMS = 0;
        durSS = 0;
        durMM = 0;
        durHH = 0;
        startMillis = millis();
        running = true;   
        Serial.print("running false to true");
        goto run;
        

      }
    }
  }

  run:
   if(running == false){
  tft.setTextColor(TFT_RED,TFT_BLACK);
  tft.setCursor(centrex-20,centrey+20);
  tft.print("Stopped");
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
   tft.setCursor(centrex-90,centrey);
   tft.print(durMilliSec);
  }

  if(running == true)
  {
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
    durMilliSec = timeMillis(durHH, durMM, durSS,durMS);
   tft.setCursor(centrex-90,centrey);
   tft.print(durMilliSec);
   tft.setTextColor(TFT_GREEN,TFT_BLACK);
   tft.setCursor(centrex-20,centrey+20);
   tft.print("Started");
   
  }
  
 
    if(selectPressed == false)
    {
    stopwatchIncrementProtect = false;
    }  
}
