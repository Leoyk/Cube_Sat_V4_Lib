#include "commLight.h"
#include "Arduino.h"

/*
*预先处理：设定具体的对象以及延时时间变量
*/
SFE_TSL2561 light;
unsigned int shutterMs;  // Integration ("shutter") time in milliseconds





/*================================================================ 
* 函 数 名：
* TSL2561Init() 
* 
* 参 数：
* 无 
*
* 功 能 描 述: 
* 初始化光强计模式
*  
* 返 回 值：
* 无
* 
* 作 者：刘要坤 2018年5月18日
================================================================*/ 
void TSL2561Init(){
  light.begin();
  light.setTiming(0,1,shutterMs);// Gain setting, 0 = X1, 1 = X16;
  light.setPowerUp();
 }

/*================================================================ 
* 函 数 名：
* TSL2561Data() 
* 
* 参 数：
* 无 
*
* 功 能 描 述: 
* 获取当前光强
*  
* 返 回 值：
* 浮点型流明值
* 
* 作 者：刘要坤 2018年5月18日
================================================================*/ 
double lightVal(){
//  delay(shutterMs);
  
  unsigned int data0, data1;
  
  if (light.getData(data0,data1))
  {
    double lux;    // Resulting lux value
    boolean good;  // True if neither sensor is saturated


    if(light.getLux(0,shutterMs,data0,data1,lux))
    return lux;
  }
}