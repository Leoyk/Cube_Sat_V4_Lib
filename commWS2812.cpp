
 #include "commWS2812.h"
 
 #include <Arduino.h>
 #include <String.h>
 



  #define PINRIGHT  26   //为调试修改的灯板引脚号
  #define PINLEFT   25  
  #define PINMIDDLE 4
  
  
  #define BRIGHTLEFT   40//默认的灯板亮度
  #define BRIGHTRIGHT  40
  int     BRIGHTMIDDLE=40;
  
  
  
  
  
//控制左面板

//字阵
  Adafruit_NeoMatrix matrixLeft = Adafruit_NeoMatrix(8, 8, PINLEFT,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
//点阵
  Adafruit_NeoPixel pixelsLeft = Adafruit_NeoPixel(64, PINLEFT, NEO_GRB + NEO_KHZ800);

  
  
  
//控制右面板

//字阵
  Adafruit_NeoMatrix matrixRight = Adafruit_NeoMatrix(8, 8, PINRIGHT,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
//点阵
  Adafruit_NeoPixel pixelsRight = Adafruit_NeoPixel(64, PINRIGHT, NEO_GRB + NEO_KHZ800);

  
  
//控制中间灯

//点阵
  Adafruit_NeoPixel pixelsMiddle = Adafruit_NeoPixel(64, PINMIDDLE, NEO_GRB + NEO_KHZ800);

  
  
  
//初始化三个灯阵
void wsInit(){

//左	
  matrixLeft.begin();//开字阵
  pixelsLeft.begin();//开点阵
  pixelsLeft.setBrightness(BRIGHTLEFT);//设置点阵亮度
  
  matrixLeft.setTextWrap(false);//设置字阵出现形式
  matrixLeft.setBrightness(BRIGHTLEFT);//设置字阵亮度
  
  matrixLeft.setTextColor(matrixLeft.Color(0, 0, 0));  //设置清屏
  matrixLeft.show(); //执行清屏 
  
  
  matrixRight.begin();//开字阵
  pixelsRight.begin();//开点阵
  pixelsRight.setBrightness(BRIGHTRIGHT);//设置点阵亮度
  
  matrixRight.setTextWrap(false);//设置字阵出现形式
  matrixRight.setBrightness(BRIGHTRIGHT);//设置字阵亮度
  matrixRight.setTextColor(matrixRight.Color(0, 0, 0));   //设置清屏
  matrixRight.show(); //执行清屏   
  

  pixelsMiddle.begin();//开点阵
  pixelsMiddle.setBrightness(BRIGHTMIDDLE);//设置点阵亮度
}



//设置亮度值
void setBrightness(String lmr,int bright){
	
  if(lmr == "left"){//left   
	pixelsLeft.setBrightness(bright);//设置点阵亮度
    }
  else if(lmr == "right"){//right  
	pixelsRight.setBrightness(bright);//设置点阵亮度
    }
  else if(lmr == "middle"){//middle 
	pixelsMiddle.setBrightness(bright);//设置点阵亮度
   }	
	
}



//清空点阵

void clearPixels(String lmr){
	
  if(lmr == "left")//left   清空左灯阵
    for(int i = 0;i < 64;i ++){
      pixelsLeft.setPixelColor(i,pixelsLeft.Color(0,0,0)); // Moderately bright green color.
    }
  else if(lmr == "right")//right  清空右灯阵
    for(int i = 0;i < 64;i ++){
      pixelsRight.setPixelColor(i,pixelsRight.Color(0,0,0)); // Moderately bright green color.
	}
  else if(lmr == "middle")//middle 清空中间灯
    for(int i = 0;i < 64;i ++){
      pixelsMiddle.setPixelColor(i,pixelsMiddle.Color(0,0,0)); // Moderately bright green color.
    }
}







//设置点阵显示内容
//低位左对齐
void setPixels(String lmr,int hang,int hex,int red,int green,int blue){

  if(lmr == "left"){//left
    for(int i = 0;i < 8;i ++){
      if(hex& (1 << i)){
         pixelsLeft.setPixelColor(hang * 8 + i, pixelsLeft.Color(red,green,blue)); 
        }
      }
  }
  else if(lmr == "right"){//right
    for(int i = 0;i < 8;i ++){
      if(hex& (1 << i)){
         pixelsRight.setPixelColor(hang * 8 + i, pixelsRight.Color(red,green,blue)); 
        }
      } 
  }
  else if(lmr == "middle"){
    for(int i = 0;i < 8;i ++){
      if(hex& (1 << i)){
         pixelsMiddle.setPixelColor(hang * 8 + i, pixelsMiddle.Color(red,green,blue)); 
        }
      }
  }
 }


//开启点阵显示
void showPixels(String lmr){
	if(lmr == "left"){
		pixelsLeft.show();  
	}
	else if(lmr == "middle"){
		pixelsMiddle.show();  
	}
	else if(lmr == "right"){
		pixelsRight.show();  
	}
}





//设置左侧面板显示字符串
bool showStrLeft(String a,int red,int green,int blue){

static String ss = "";
static long x  = 0;
int flag = 1;
int sum = a.length();
  
  matrixLeft.setTextColor(matrixLeft.Color(red,green,blue));
   
  if(flag == 0)
    x = matrixLeft.width();
  
  else{  
    ss = a;
    
      matrixLeft.fillScreen(0);
      matrixLeft.setCursor(x, 0);
      matrixLeft.print(a);  
      
  if(--x < -6*sum) {
    x = matrixLeft.width();

      matrixLeft.show(); 
      return 1;
  }
      matrixLeft.show();  
  }
  return 0;
 }
 
 

//设置右侧面板显示字符串
bool showStrRight(String a,int red,int green,int blue){

static long x  = 0;
int flag = 1;
int sum = a.length();
  
  matrixRight.setTextColor(matrixRight.Color(red,green,blue));
   
  if(flag == 0)
    x = matrixRight.width();
  
  else{  
      matrixRight.fillScreen(0);
      matrixRight.setCursor(x, 0);
      matrixRight.print(a);  
      
  if(--x < -6*sum) {
    x = matrixRight.width();

      matrixRight.show(); 
      return 1;
  }
      matrixRight.show();  
  }
  return 0;
 }


 
 

/* void showStr(String a,int r,int g,int b,int spe){

static unsigned long LM = 0;
static long x  = 0;
int flag = 1;
int sum = a.length();
  
  matrixL.setTextColor(matrixL.Color(r,g,b)); 

  x = matrixL.width();
  
  while(flag){  
    if(millis() - LM > spe){
      LM = millis();
      
      matrixL.fillScreen(0);
      matrixL.setCursor(x, 0);
      matrixL.print(a);  
      
  if(--x < -6*sum) {
    x = matrixL.width();
    flag = 0;
  }
      matrixL.show();  
    }
  }
 } */
