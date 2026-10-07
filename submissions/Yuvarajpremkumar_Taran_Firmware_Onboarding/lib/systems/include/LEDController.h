#pragma once
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void refresh(float tempC, uint32_t time);   
    bool ledState() const;                       
    uint32_t getDelay() const;               

private:
    uint32_t calcDelay(float tempC) const;   

    uint32_t _blinkRate = BMEConstants::SLOWER_RATE;
    uint32_t _prevToggle = 0;
    bool _ledLit = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;