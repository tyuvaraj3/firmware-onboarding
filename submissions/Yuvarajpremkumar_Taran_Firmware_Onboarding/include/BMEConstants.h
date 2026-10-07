#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint32_t BAUDRATE = 115200;   
    constexpr uint8_t I2C_LOC = 0x76;     
    constexpr uint8_t CHIP_PIN = 10;        
    constexpr uint8_t LED_PIN = 9;
    constexpr float LOWTEMP = 20.0f;        
    constexpr float HIGHTEMP = 35.0f;        
    constexpr uint32_t SLOWER_RATE = 1000;
    constexpr uint32_t FASTER_RATE = 100;

}