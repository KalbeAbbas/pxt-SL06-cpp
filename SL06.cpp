#include "SL06.h"
#include "pxt.h"

using namespace pxt;

uint8_t SL06::i2cread(uint8_t reg, uint8_t *data, int len) {
#ifdef CODAL_I2C
    auto sda = LOOKUP_PIN(SDA);
    auto scl = LOOKUP_PIN(SCL);
    codal::I2C *i2c = pxt::getI2C(sda, scl);
#endif
    int i2c_error_status = 0;

#ifdef CODAL_I2C
    i2c_error_status = i2c->write((uint16_t)i2cAddr, (uint8_t *)&reg, 1, true);
#else
    i2c_error_status = uBit.i2c.write(i2cAddr, (const char *)&reg, 1, true);
#endif

#ifdef CODAL_I2C
    if (len == 1)
        return i2c_error_status = i2c->read((uint16_t)i2cAddr, (uint8_t *)&data, len, false);
    else
        return i2c_error_status = i2c->read((uint16_t)i2cAddr, (uint8_t *)&data, len, false);
#else
    return i2c_error_status = uBit.i2c.read(i2cAddr, (char *)data, len, false);
#endif
}

SL06::SL06(uint8_t addr)
{
	i2cAddr = addr;
}

uint8_t* SL06::readBlockData(uint8_t reg, uint8_t len, uint8_t* buf)
{
	i2cread(reg, data, len);
	return data;
}


namespace sl06
{
	SL06 xSL06;
	
	uint8_t test_data[] = {1,2,3,4};
	
	//%
	uint8_t* readBytes(uint8_t reg, int len)
	{
		xSL06.readBlockData(reg, len, xSL06.data);
		return test_data;
		
	}
}
