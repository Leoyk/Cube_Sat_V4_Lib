#ifndef _COMMSHT_H__
#define _COMMSHT_H__

/////////////////////////////////////////////头文件包含区
//温湿度
#include "ClosedCube_SHT31D.h"


////////////////////////////////////////////函数声明区

/*================================================================ 
* 函 数 1：
* shtInit 
* 
* 参 数：
* 传感器地址，默认SHT31的地址为0x44
*
* 功 能 描 述: 
* 需要开启Wire.begin();然后此函数初始化传感器。
* 
* 返 回 值：
* 获取的紫外线传感器电压值（mv）
* 
* 作 者：刘要坤 2018年5月24日14:31:48

================================================================*/ 
void shtInit(int add);



//在调用获取温湿度之前必须先执行此步骤，然后等待500ms
void orderTH();

void getTH(float *t,float *h);

#endif
