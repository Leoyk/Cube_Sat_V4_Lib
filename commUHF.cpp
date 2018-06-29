#include "commUHF.h"
#include "Arduino.h"


#define USerial Serial3

String boud = "AT+B";
String ch = "AT+C";

unsigned long BR = 0;



void enAT(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,0);
  }

void outAT(int pin){
  digitalWrite(pin,1);
  }



void FMinit(long Boud){
  USerial.begin(Boud);    
  while(USerial.read()>= 0){}//clear portInbuffer
}


void testAt(){
   USerial.println("AT");
  }



void setBoud(long a){
   USerial.println("AT+B"+(String)a);
}


void setCh(long a){
 String Sa = "";
  
  if(a < 10){
   USerial.println("AT+C00"+(String)a);
   }
  else if(a < 100){
   USerial.println("AT+C0"+(String)a);
   }
  else {
   USerial.println("AT+C"+(String)a);
   }
}