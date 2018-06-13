#ifndef _COMMUV_H__
#define _COMMUV_H__
/*
UV传感器返回模拟量，经过等级分化之后返回0~11之间的UV等级
*/

//返回电压值
float s12sdValMv(int s12sdPin);//参数为s12sd模拟量读取口

//返回紫外线指数 可单独使用
int uvLevel(int s12sdPin);//参数为s12sd模拟量读取口

#endif
