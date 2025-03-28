#include <Arduino.h>
#include "LundayTibok.h"

#define LED1_PIN 13 // Unang LED
#define LED2_PIN 8 // Pangalawang LED
#define LED3_PIN 7 // Pangatlong LED
#define LED4_PIN 6 // Pangapat na LED

LundayTibok emergencyLED(LED1_PIN, EMERGENCY);
LundayTibok criticalLED(LED2_PIN, CRITICAL);
LundayTibok warningLED(LED3_PIN, WARNING);
LundayTibok normalLED(LED4_PIN, NORMAL);

void setup() {
    emergencyLED.begin();
    criticalLED.begin();
    warningLED.begin();
    normalLED.begin();
}

void loop() {
    emergencyLED.update();
    criticalLED.update();
    warningLED.update();
    normalLED.update();
}