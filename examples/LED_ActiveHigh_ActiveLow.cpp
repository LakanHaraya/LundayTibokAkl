#include <Arduino.h>
#include "LundayTibok.h"

#define LED_HIGH_PIN 6  // Active High LED
#define LED_LOW_PIN 7   // Active Low LED

LundayTibok ledHigh(LED_HIGH_PIN, NORMAL);  // Default: Active High
LundayTibok ledLow(LED_LOW_PIN, NORMAL);    // Gagawing Active Low sa `begin()`

void setup() {
    Serial.begin(115200);

    ledHigh.begin(true);   // Active High (HIGH = ON, LOW = OFF)
    ledLow.begin(false);   // Active Low (LOW = ON, HIGH = OFF)

    Serial.println("Simula ng dalawang LED test...");
}

void loop() {
    ledHigh.update();
    ledLow.update();
}