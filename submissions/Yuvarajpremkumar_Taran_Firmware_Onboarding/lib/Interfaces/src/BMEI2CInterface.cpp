#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return _device.begin(BMEConstants::I2C_LOC);
}

void BMEI2CInterface::refresh()
{
    _tempC = _device.readTemperature();
}

float BMEI2CInterface::getTemp() const
{
    return _tempC;
}