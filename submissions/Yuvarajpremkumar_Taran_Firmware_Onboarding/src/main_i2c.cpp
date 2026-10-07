#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup() {
    Serial.begin(BMEConstants::BAUDRATE);
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();
    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("ERROR");
        while (true) {} 
    }
    Serial.println("NO ERRORS");

}
void loop() {
    BMEI2CInterface& I2C = BMEI2CInterfaceInstance::instance();
    LEDController& led = LEDControllerInstance::instance();

    I2C.refresh();
    float temp = I2C.getTemp();

    led.refresh(temp, millis());
    digitalWrite(BMEConstants::LED_PIN, led.ledState() ? HIGH : LOW);

}