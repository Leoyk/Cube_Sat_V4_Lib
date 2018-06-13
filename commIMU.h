#ifndef _COMMIMU_H__
#define _COMMIMU_H__

#include <Wire.h>



void imuInit();


class commIMU{
	public:
		int16_t  AX;
		int16_t  AY;
		int16_t  AZ;
		int16_t  GX;
		int16_t  GY;
		int16_t  GZ;
		int16_t  MX;
		int16_t  MY;
		int16_t  MZ;
		void getData();
	private:
	
};


#endif
