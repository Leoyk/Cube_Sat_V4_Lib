#include "commFM.h"
#include "Arduino.h"
#include "SoftwareSerial.h"


SoftwareSerial comm = SoftwareSerial(A10,A11);//R T
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
void setVol(int a){
  a = constrain(a, 0, 30);
  comm.println(vol + String(a));
}
