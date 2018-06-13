#include "commFM.h"
#include "Arduino.h"
#include "SoftwareSerial.h"


SoftwareSerial comm = SoftwareSerial(50,51);//R T
// 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

String fre="AT+FRE=";
String vol="AT+VOL=";

void FMinit(){
  comm.begin(38400);    
  while(comm.read()>= 0){}//clear portInbuffer
}

void setFre(int a){
  comm.println(fre+(String)a);
}
void setVol(int a){
  comm.println(vol+(String)a);
}
