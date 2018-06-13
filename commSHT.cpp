#include "commSHT.h"
#include "Arduino.h"

#include "ClosedCube_SHT31D.h"
///////////////////////////////////////////////////温湿度传感器数据
ClosedCube_SHT31D sht3xd;

struct SHT31D  result;


/*================================================================ 
* 函 数 名：
* shtInit 
* 
* 参 数：
* 传感器地址
*
* 功 能 描 述: 
* 需要开启Wire.begin();然后此函数初始化传感器。
* 
* 返 回 值：
* 获取的紫外线传感器电压值（mv）
* 
* 作 者：刘要坤 2018年5月24日14:31:48

================================================================*/ 
void shtInit(int add){
  //温湿度传感器设置 
  sht3xd.begin(add);//0x44
}


/*================================================================ 
* 函 数 名：
* getsht31d 
* 
* 参 数：
* 需要存放温度和湿度的变量地址
*
* 功 能 描 述: 
* 将读取的温湿度数据存储在指定地址的变量中
* 
* 返 回 值：
* 无
* 
* 作 者：刘要坤 2018年5月24日14:31:48

================================================================*/ 
void sht31dVal(float *tem,float *rh){

  result = sht3xd.readTempAndHumidity(SHT3XD_REPEATABILITY_LOW, SHT3XD_MODE_CLOCK_STRETCH, 50);

  *tem = result.t;
  *rh  = result.rh;
    }   
 
