#include "commFM.h"
#include "Arduino.h"
#include "SoftwareSerial.h"


//SoftwareSerial comm = SoftwareSerial(10,11);//R T
SoftwareSerial comm = SoftwareSerial(A14,A15);//R T
//#define comm Serial2
// 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

static String fre="AT+FRE=";
static String vol="AT+VOL=";

void FMinit(){
  comm.begin(38400);    
  while(comm.read()>= 0){}//clear portInbuffer
}

void setFre(int a){
  a = constrain(a, 870, 1080);
  comm.println(fre + String(a));
}


int getEcho(){
 
  String vol = "";
  String inputString3 = "";
  
  vol  = "";
  inputString3 = "";
 while (comm.available()) {
	 
      char inChar = (char)comm.read();
	  
      if(isDigit(inChar))
        inputString3 += inChar;
    }

   return inputString3.toInt();  
}


void setVol(int a){
  a = constrain(a, 0, 30);
  
  if(a < 10)
   comm.println(vol + '0' + String(a));
  else 
   comm.println(vol + String(a));
}

void orderState(){
  while(comm.read()>= 0){}//clear serialbuffer
  comm.println("AT+RET"); 
}

bool getState(int *volume,int *frequncy){
  
  String vol = "";
  String freq = "";
  String inputString3 = "";
  
  vol  = "";
  freq  = "";
  inputString3 = "";
 while (comm.available()) {
	 
      char inChar = (char)comm.read();
	  
      if(isDigit(inChar))
        inputString3 += inChar;
    }

  vol += inputString3[0];
  vol += inputString3[1];

  
  for(int i = 2;i < inputString3.length();i ++){
    freq += inputString3[i];
  }
  *volume = vol.toInt();
  *frequncy =freq.toInt();
  if(*volume > 30 || *volume < 0 || *frequncy > 1080 || *frequncy < 870 ){
	 return 0;  
  }
  else 
	  return 1;
}



















