#include "commINC.h"

//#define debugSHT 
#define debugIMU 
//#define debugUV 
//#define debugCDC
//#define debugLV
//#define debugBMP180
//#define debugRTC

//数据定义
float 
TEMP = 0.00,//温度数据
RH = 0.00,  //空气湿度数据

AX,AY,AZ,//加速度值
GX,GY,GZ,//角速度值
MX,MY,MZ,//磁力计值
//YAW,PITCH,ROLL,//Y P R
DCVAL,//[6]//检测到的电压值

ALTI,PRESSURE,TEMPRETURE,

LV//光照强度
;


int 
UV//紫外线强度
,y,m,d,h,f,s
;






//初始化
void setup() {
  Serial.begin(115200);
  
  Wire.begin();
  
//  enAT(pin);
//  FMinit(9600);
//  delay(100);
//  setBoud(long a);
//  delay(100);
//  setCh(long a);
//  delay(100);
//  outAT(pin);

delay(50);
  
//  RTCinit();
//  FMinit();
  imuInit();
//  shtInit(0x44);//add：0x44   初始化温湿度传感器sht31
//  TSL2561Init();
//  pressureInit();
}

void loop() {
//
//setFre(1010);
//getTime(&y,&m,&d,&h,&f,&s); 
// 
//sht31dVal(&TEMP,&RH);
imuData(&AX,&AY,&AZ,&GX,&GY,&GZ,&MX,&MY,&MZ);
//UV = uvLevel(A0);
//DCVAL = dcVal(A1);
//LV = lightVal();
//ALTI = altitudeVal();
//PRESSURE = pressureVal();
//TEMPRETURE = tempVal();



#ifdef debugRTC
    Serial.print(y);
    Serial.print("/"); 
    Serial.print(m);
    Serial.print("/"); 
    Serial.print(d);
    Serial.print("/"); 
    Serial.print(h);
    Serial.print(":"); 
    Serial.print(f);
    Serial.print(":"); 
    Serial.println(s); 
#endif


#ifdef debugBMP180
    Serial.print(ALTI);
    Serial.print("\t"); 
    Serial.print(PRESSURE);
    Serial.print("\t");
    Serial.print(TEMPRETURE);
    Serial.println("\t");
#endif

#ifdef debugLV
    Serial.print(LV);
    Serial.println("\t");
#endif

#ifdef debugCDC
    Serial.print(DCVAL);
    Serial.println("\t");
#endif

#ifdef debugUV
    Serial.print(UV);
    Serial.println("\t");
#endif


#ifdef debugSHT
    Serial.print(TEMP);
    Serial.print("\t");
    Serial.print(RH);
    Serial.println("\t");
#endif

#ifdef debugIMU
    Serial.print("AX:"); Serial.print(AX);Serial.print("\t");
    Serial.print("|AY:"); Serial.print(AY);Serial.print("\t");
    Serial.print("|AZ:"); Serial.print(AZ);Serial.print("\t");
    Serial.print("|GX:"); Serial.print(GX);Serial.print("\t");
    Serial.print("|GY:"); Serial.print(GY);Serial.print("\t");
    Serial.print("|GZ:"); Serial.print(GZ);Serial.print("\t");
    Serial.print("|MX:"); Serial.print(MX);Serial.print("\t");
    Serial.print("|MY:"); Serial.print(MY);Serial.print("\t");
    Serial.print("|MZ:"); Serial.print(MZ);Serial.println("\t");
#endif

}


