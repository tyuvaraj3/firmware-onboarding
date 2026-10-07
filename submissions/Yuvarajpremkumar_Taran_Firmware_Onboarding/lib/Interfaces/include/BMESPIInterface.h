#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;
    bool begin();
    void refresh();
    float getTemp() const;

private:
    Adafruit_BME280 _device{BMEConstants::CHIP_PIN};  
    float _tempC = 0.0f;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;