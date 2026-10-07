#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup() {
    Serial.begin(BMEConstants::BAUDRATE);
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();
    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println("ERROR");
        while (true) {} 
    }
    Serial.println("NO ERRORS");

}
void loop() {
    BMESPIInterface& SPI = BMESPIInterfaceInstance::instance();
    LEDController& led = LEDControllerInstance::instance();

    SPI.refresh();
    float temp = SPI.getTemp();

    led.refresh(temp, millis());
    digitalWrite(BMEConstants::LED_PIN, led.ledState() ? HIGH : LOW);

}