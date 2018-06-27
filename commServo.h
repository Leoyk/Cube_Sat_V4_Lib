#ifndef _COMMSERVO_H__
#define _COMMSERVO_H__

#include "Arduino.h"

void ssInit();
void changeID(uint8_t oldID, uint8_t newID);
void moveToAngle(int ID,int angle,int time);
void unLoad(int ID);
void load(int ID);
double readAngle(int ID);


#endif