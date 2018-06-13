#include "commUHF.h"
#include "Arduino.h"


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
  Serial3.begin(Boud);    
  while(Serial3.read()>= 0){}//clear portInbuffer
}


void testAt(){
   Serial3.println("AT");
  }



void setBoud(long a){
   Serial3.println("AT+B"+(String)a);
}


void setCh(long a){
 String Sa = "";
  
  if(a < 10){
   Serial3.println("AT+C00"+(String)a);
   }
  else if(a < 100){
   Serial3.println("AT+C0"+(String)a);
   }
  else {
   Serial3.println("AT+C"+(String)a);
   }
}