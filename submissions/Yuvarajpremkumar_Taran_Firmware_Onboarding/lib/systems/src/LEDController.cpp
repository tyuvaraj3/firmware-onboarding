#include "LEDController.h"

uint32_t LEDController::calcDelay(float tempC) const
{
    if (tempC <= BMEConstants::LOWTEMP)
    {
        return BMEConstants::SLOWER_RATE;
    }
    if (tempC >= BMEConstants::HIGHTEMP)
    {
        return BMEConstants::FASTER_RATE;
    }

    float tempRatio = (tempC - BMEConstants::LOWTEMP)/(BMEConstants::HIGHTEMP - BMEConstants::LOWTEMP);

    uint32_t rateRange = BMEConstants::SLOWER_RATE - BMEConstants::FASTER_RATE;
    return BMEConstants::SLOWER_RATE - static_cast<uint32_t>(tempRatio * rateRange);
}

void LEDController::refresh(float tempC, uint32_t time)
{
    _blinkRate = calcDelay(tempC);

    if (time - _prevToggle >= _blinkRate)
    {
        _ledLit = !_ledLit;
        _prevToggle = time;
    }
}

bool LEDController::ledState() const
{
    return _ledLit;
}

uint32_t LEDController::getDelay() const
{
    return _blinkRate;
}