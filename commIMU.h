#ifndef _COMMIMU_H__
#define _COMMIMU_H__

#include <Wire.h>



void imuInit();


class commIMU{
	public:
		float AX;
		float AY;
		float AZ;
		float GX;
		float GY;
		float GZ;
		float MX;
		float MY;
		float MZ;
		void getData();
	private:
	
};


#endif