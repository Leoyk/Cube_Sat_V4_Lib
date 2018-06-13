#ifndef _COMMWS2812_H__
#define _COMMWS2812_H__

 #include <Adafruit_GFX.h>
 #include <Adafruit_NeoMatrix.h>
 #include <Adafruit_NeoPixel.h>
 
//初始化三个灯阵
void wsInit();

//设置亮度值 默认为40
void setBrightness(String lmr,int bright);

//清空点阵
void clearPixels(String lmr);

//设置点阵显示内容
//低位左对齐
void setPixels(String lmr,int hang,int hex,int red,int green,int blue);

//开启点阵显示
void showPixels(String lmr);

//在左侧面板显示字符串
bool showStrLeft(String a,int red,int green,int blue);

//在右侧面板显示字符串
bool showStrRight(String a,int red,int green,int blue);



#endif