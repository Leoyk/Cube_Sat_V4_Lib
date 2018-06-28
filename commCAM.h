#ifndef _COMMCAM_H__
#define _COMMCAM_H__

#include <SPI.h>
#include <SD.h>
 
 
 #define chipSelect 5
// #define commCAM Serial3

 
/*

#include"commINC.h"


void setup() {
  Serial.begin(115200);
  camInit();
  delay(200);
  clearInput();
  
  pinMode(4,1);
}

void loop() {
long len = 0;
String name = "";
long time;


//step 1: 停止刷新图像
    do{
      orderStop();
      delay(10);
    }while(!getStop());//check error 
      
    
    
//step 2: 获取数据长度到len
    do{
      orderLenth();
      delay(10);
    }while(!getLenth(&len));

    
//step 3:存入内存卡中
  
  //3.0 创建并开启文件
    preFile(&name);
    Serial.print("Begin write ");
    Serial.println(name);
    Serial.print("total lenth :");
    Serial.println(len);
    
    time = millis();
  //3.1写入文件 
    while(orderPic()){//如果还能order（返回 1）
      //灭灯      
      digitalWrite(4,0);
      //等数据
      delay(10);  
      //亮灯
      digitalWrite(4,1);
      //写数据
      getPic();       //则持续获取图片并写入文件  
      
    Serial.print(".");
    }
    Serial.println();
  //3.2完成后关闭文件
    closeFile(); 
    
    
//step 4:恢复刷新屏幕
    refreshImg();
    
    Serial.print(name);
    Serial.println(" is complated.");
    Serial.print("using ");
    Serial.print(millis()-time);
    Serial.println("ms.");
    Serial.println();
    
//灯灭掉2s
    digitalWrite(4,0);
    delay(2000);
}
*/ 
 
 
 
 
 
 
//初始化摄像头： 检测SD卡
void camInit(); 
 
//复位摄像头 不返回任何值，用后可能需要清空串口缓存
void orderReset();
 
//请求版本号 调用后需延时> 10ms才能获取版本号
void orderVersion();

//获得版本号 开启串口输出情况下会打印出版本号   返回0：无错误，返回1：错误；
bool getVersion();

//清空缓存
void clearInput();




//1 stop pic 
	//请求停止刷新图像 调用后需延时> 10ms才能获取反馈
	void orderStop();
	
	//获取停止状态： 1：操作成功，0：操作失败；
	bool getStop();

//2 get lenth 
	//请求获取图像数据长度 调用后需延时> 10ms才能获取反馈
	void orderLenth();
	
	//将获取的长度返回到*lenth中  1：操作成功，0：操作失败；
	bool getLenth(long *lenth);

//3 get pic
	//创建文件并打开
	void preFile(String* name);
	
	//请求获取图像数据 调用后需延时> 10ms才能获取反馈
	void orderPic();
	

	bool getPic(bool * a);
	
	//关闭文件
	void closeFile();

//4 refresh img 初始化变量并刷新图像
	void refreshImg();
	
	//初始化变量
	void initV();

#endif














