#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return _device.begin();
}

void BMESPIInterface::refresh()
{
    _tempC = _device.readTemperature();
}

float BMESPIInterface::getTemp() const
{
    return _tempC;
}