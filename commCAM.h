#ifndef _COMMCAM_H__
#define _COMMCAM_H__

#include <SPI.h>
#include <SD.h>
 
 
 #define chipSelect 53
 #define commCAM Serial2

 
/*
#include"commCAM.h"

long lenth;//get the pic lenth
String name;// get the pic name

long cntCam = 0;
long cntCamBuff = 0;
long time;
void setup() {
  
Serial.begin(115200);//begin debug serial
/********************print debug head info*******************************
Serial.println();
Serial.println("Cam begin");
Serial.println();

  camInit();//begin init camera
  Serial.println("Cam init over");
  
  delay(100);
  clearInput();
/********************get cam version*******************************
  do{
    orderVersion();delay(10);
  }while(getVersion() == 0);
  
  Serial.println("Cam get version over");
}

void loop() {

/********************stop pic*******************************
do{
    orderStop();delay(10);
  }while(getStop() == 0);

  Serial.println("Cam stop pic over"); 
  clearInput();

/********************get pic lenth and pirnt*******************************
  do{
    orderLenth();delay(10);
  }while(getLenth(&lenth) == 0);

  Serial.print("Cam get lenth :");  
  Serial.println(lenth);  
  clearInput();


/********************creat file for pic data*******************************
  preFile(&name);
  
  Serial.print("pic name is :");  
  Serial.println(name);  
  clearInput();
  
for(long a = lenth; a > 0;a -= 64*32){
    Serial.print("#");  
  }
    Serial.println("*");
/********************order picture******************************* 


time = millis();

while(orderPic())  {  
  delay(10);
  getPic();
   
  cntCam ++;
  if(cntCam -cntCamBuff > 64) {
    Serial.print("#");  
    cntCamBuff = cntCam;
    }

}
    Serial.println("#*");
/********************close file when read over*******************************
  closeFile();  
time = millis()-time;
/********************refresh image******************************* 
refreshImg(); 
  Serial.print("save PIC over,cost: ");  
  Serial.print(time);  
  Serial.println("ms");  


/********************delay for next shot*******************************
delay(50000);
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
	bool orderPic();
	

	void getPic();
	
	//关闭文件
	void closeFile();

//4 refresh img 初始化变量并刷新图像
	void refreshImg();
	
	//初始化变量
	void initV();

#endif














