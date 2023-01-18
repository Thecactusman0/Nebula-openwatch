#include "counting_and_bezel.h"
#define ms1 19
#define ms2 17
#define ms3 16

int lastState1;
int lastState2;
int lastState3;
int state1;
int state2;
int state3;
void serialItemCounting()//increments item variable 
{
   //Create a place to hold the incoming message
   static char message[12];
   static unsigned int message_pos = 0;

   //Read the next available byte in the serial receive buffer
   char inByte = Serial.read();

   //Message coming in (check not terminating character) and guard for over message size
   if ( inByte != '\n' && (message_pos < 12 - 1) )
   {
     //Add the incoming byte to our message
     message[message_pos] = inByte;
     message_pos++;
   }
   //Full message received...
   else
{
 
 //Add null character to string
 message[message_pos] = '\0';

 //Print the message (or do other things)


 //Or convert to integer and print
 int number = atoi(message);

 switch (menu)
    {
    case 1:
        if (number  == 1)
        {
           if(item>0){
            selectorRedrawProtect = false;
            item--;
           }else{
            selectorRedrawProtect = false;
            item=7;
           }

        selectorRedrawProtect = false;
        }
        if (number == 2)
        {
           if(item<7){
            selectorRedrawProtect = false;
            item++;
           }else{
            selectorRedrawProtect = false;
            item=0;   
           } 

        selectorRedrawProtect = false;
        }
       
        break;
        
    }
 //Reset for the next message
 message_pos = 0;
}
  
     
     
}

void bezelCounting(){
  pinMode(ms1, INPUT_PULLUP);
pinMode(ms2, INPUT_PULLUP);
pinMode(ms3, INPUT_PULLUP);
  state1 = digitalRead(ms1)  ;
state2 = digitalRead(ms2)  ;
state3 = digitalRead(ms3)  ;

  

if (state1 == 0){
  if (lastState2 == 0){
  item--;
  lastState2 = 1;
  lastState1 = 0;
  //redrawProtect = false;
  selectorRedrawProtect = false;

  }
  if (lastState3 == 0){
  item++;
  lastState3 = 1;
  lastState1 = 0;
//redrawProtect = false;
selectorRedrawProtect = false;
  }
}
if (state2 == 0){
  if (lastState1 == 0){
  item++;
  lastState1 = 1;
  lastState2 = 0;
 //redrawProtect = false;
 selectorRedrawProtect = false;
  }
  if (lastState3 == 0){
  item--;
  lastState3 = 1;
  lastState2 = 0;
//redrawProtect = false;
selectorRedrawProtect = false;
  }
}
if (state3 == 0){
  if (lastState1 == 0){
  item--;
  lastState1 = 1;
  lastState3 = 0;
 //redrawProtect = false;
 selectorRedrawProtect = false;
  }
  if (lastState2 == 0){
  item++;
  lastState2 = 1;
  lastState3 = 0;
//redrawProtect = false;
selectorRedrawProtect = false;
  }
}
}
