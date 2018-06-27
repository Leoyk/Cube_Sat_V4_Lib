#include"commCAM.h"
#include "SoftwareSerial.h"
//#define debugCam 

SoftwareSerial commCAM = SoftwareSerial(11,10);//R T

unsigned int inNum = 0;
long picLen[4];
long BA = 0;
long dl;
uint8_t aaa[32];


Sd2Card card;

File imgFile;

char filename[10];


void camInit(){
  commCAM.begin(115200);    
  pinMode(53, OUTPUT); // SS on Mega 	
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }   
  
  

    Serial.println("ok");  
  
  //复位摄像头  可选
  orderReset();//测试通过
}

void clearInput(){
  //清空缓存
  while(commCAM.read()>= 0);
}


//0 reset
void orderReset(){// tesk link order version
  byte cmd[]={0x56,0x00,0x26,0x00};

  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0])); 
}

 
//0 test
void orderVersion(){// tesk link order version
  byte cmd[]={0x56,0x00,0x11,0x00};

  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0])); 
}

bool getVersion(){//get version
  
String data = "";
String rge = "";
int i = 0;

byte rcv[]={0x76,0x00,0x11,0x00,0x0b};

  while (commCAM.available()){ 
   if(inNum < 5){
     rge += (char)commCAM.read();
   }
   else{
     data += (char)commCAM.read();
   }
   inNum ++;
  }
  
  inNum = 0;
  
  for(i = 0;i < 5;i ++){
    if(rge[i] != rcv[i])
      break;
    }
   if(i < 5){//check wrong
#ifdef debugCam    
      Serial.println("version error");
      return 0;
#endif
   }
   else {//check ok
#ifdef debugCam  
      Serial.println("version ok: ");  
      Serial.println(data);
#endif
      return 1;
   }
}


//1 stop pic
void orderStop(){// order stop image refresh
  byte cmd[]={0x56,0x00,0x36,0x01,0x00};

  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0])); 
}

bool getStop(){//get stop state
  
String data = "";
String rge = "";
int i = 0;

byte rcv[]={0x76,0x00,0x36,0x00};

  while (commCAM.available()){ 
     rge += (char)commCAM.read();
  }

  for(i = 0;i < 4;i ++){
    if(rge[i] != rcv[i])
      break;
    }

    
   if(i < 4){//check wrong  
      return 0;
   }
   else {//check ok
      return 1;
   }
}


//2 get lenth
void orderLenth(){// order PIC lenth
  byte cmd[]={0x56,0x00,0x34,0x01,0x00};

  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0])); 
}


bool getLenth(long *lenth){//get PIC lenth
  
String data = "";
String rge = "";
int i = 0;

byte rcv[]={0x76,0x00,0x34,0x00,0x04};

  inNum = 0;
  while (commCAM.available()){
    if(inNum < 5) 
     rge += (char)commCAM.read();
    else {
      picLen[inNum - 5] = commCAM.read();
    }
     
    inNum ++;
  }
  inNum = 0;
  
  for(i = 0;i < 5;i ++){
    if(rge[i] != rcv[i])
      break;
    }

   if(i < 4){//check wrong
    return 0;
   }
   else {//check ok
    dl += picLen[0] << 24;  
    dl += picLen[1] << 16; 
    dl += picLen[2] << 8; 
    dl += picLen[3] << 0; 
    
    *lenth = dl;
    return 1;
   }
}


//3 get pic

void preFile(String* name){
  
  strcpy(filename, "PIC00.jpg");
  
  for (int i = 0; i < 100; i++) {
    filename[3] = '0' + i/10;
    filename[4] = '0' + i%10;
    
    if (! SD.exists(filename)) {
        break;
      }
  }

  imgFile = SD.open(filename, FILE_WRITE);  
  *name = filename;
}

bool orderPic(){// order PIC data if over return 0

  if(BA >= dl){//如果起始地址小于总长
    return 0;
    }
    
  byte cmd[]={0x56,0x00,0x32,0x0C,0x00,0x0A,0,0,(BA >> 8)&0xFF,(BA >> 0)&0xFF,0,0,0,32,0x00,0x00};

  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0])); 

  
  return 1;
}

void getPic(){//get PIC data
  
String data = "";
String rcv = "";

  inNum = 0;
  while (commCAM.available()){
    if(inNum < 5)
     rcv += (char)commCAM.read();
    else if(inNum < 5 + 32)
      aaa[inNum -5] = commCAM.read();
      //data += (char)commCAM.read();
    else commCAM.read();
    
    inNum ++;
  } 


  BA += 32;  
  inNum = 0;

//  buffer = aaa;
  imgFile.write(aaa,32 ); 
}

//4 refresh img
void refreshImg(){
  byte cmd[]={0x56,0x00,0x36,0x01,0x02};
  commCAM.write(&cmd[0],sizeof(cmd)/sizeof(cmd[0]));
  initV();   
  }

//init
void initV(){
  inNum = 0;

  picLen[0] = 0;
  picLen[1] = 0;
  picLen[2] = 0;
  picLen[3] = 0;
  
  BA = 0;
  dl = 0;
  }
  
void closeFile(){
    imgFile.close();  //完成后关闭文件
	
}