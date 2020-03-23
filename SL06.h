#ifndef SL06_h
#define SL06_h

#include "inttypes.h"


#define APDS9960_ADDRESS 0x39

class SL06
{
	public:
		SL06(uint8_t addr = APDS9960_ADDRESS << 1);
		uint8_t* readBlockData(uint8_t reg, uint8_t length, uint8_t* buf);
		uint8_t i2cread(uint8_t reg, uint8_t *data, int len);
		uint8_t* data;
		
	private:
		uint8_t i2cAddr;
};

#endif