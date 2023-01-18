#include "buttonsMenu.h"

//bool redrawProtect;

void homeCheck()
{
 
    if (homePressed == true)
    {
      if(homeIncrementProtect == false)
      {
       Serial.println("Home button pressed");
       BL = true;
       selectorRedrawProtect = false;
        switch (menu)
        {
        case 1:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
      
            menu = 0;
            item = 0;
            redrawProtect = false;
        break;
        case 2:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            menu = 1;
            item = 0;
            redrawProtect = false;
        break;
        case 3:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            menu = 1;
            item = 0;
            redrawProtect = false;
        break;
        case 4:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            menu = 1;
            item = 0;
            redrawProtect = false;
        break;
        case 5:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            menu = 1;
            item = 0;
            redrawProtect = false;
        break;

        }
        homeIncrementProtect = true;
      }
    }

    if(homePressed == false)
    {
    homeIncrementProtect = false;

    }
}

void selectCheck()
{
    if (selectPressed == true)
    {
      
      if(selectIncrementProtect == false)
      {
        Serial.println("Select button pressed");
        BL = true;
        selectorRedrawProtect = false;
        switch (menu)
        {
        case 0:
            //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            menu = 1;
            item = 0;
            redrawProtect = false;
        break;
        case 1:
           switch(item){
           case 0:
              redrawProtect = false;
              tft.fillScreen(TFT_BLACK);
            //tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
              menu = 4;
              item = 0;
              tft.setCursor(centrex-90,centrey);
              tft.print("00h:00m:00s:000");
             
           break;
           case 1:
              redrawProtect = false;
              //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
              menu = 3;
              item = 0;
           break;
           case 2:
              redrawProtect = false;
              //tft.fillScreen(TFT_BLACK);
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
              menu = 2;
              item = 0;
              
              

           break;
           case 3:
               redrawProtect = false;
              tft.fillScreen(TFT_BLACK);
            //tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
              menu = 5;
              item = 0;
           break;
           case 4:

           break;
           case 5:

           break;
           case 6:

           break;
           case 7:

           break;
           }
        break;
        case 2:
        
        break;
        case 3:
        
        break;
        case 4:
        
        break;
        case 5:
        RTCSetting++;
        if(RTCSetting == 3){
          RTCSetting = 0;
        }
        break;
        }

        selectIncrementProtect = true;

      }
    } 

    if(selectPressed == false)
    {
    selectIncrementProtect = false;
    }   
}

void drawMenu()//draws current menu
{
    selector();
    timeRefresh();//redrawProtect = false every 60 seconds
    timeWithMillis(); 
    switch (menu)
        {
        case 0:

          if (redrawProtect == false){
          
            redrawProtect = true;
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            drawHScreen();
          }
          break;
        case 1:

           if (redrawProtect == false){

            redrawProtect = true;
         
            drawAppScreen();
            selector();
           }
            break;
        case 2:
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            mpu.getEvent(&a, &g, &temp);
            drawGyroscopeScreen();
            time_now = millis();
            while(millis() < time_now + 600){
            }
        break;
        case 3:
            tft.fillRectVGradient(0, 0, 240,240,TFT_BLACK,0x7215);
            mpu.getEvent(&a,&g,&temp);
            drawAccelerometerScreen();
            time_now = millis();
            while(millis() < time_now + 600){
            }
        break;
        case 4:
            stopwatchScreen();
            
        break;
        case 5:
            drawRTCAdjust();
            
            //selector();
        break;
        }
    
}
