/**
 * @file DualLEDTest.cpp
 * @brief Pagsusuri ng dalawang LED (bilang indikador) gamit ang magkaibang antas ng lohika.
 * 
 * Ipinapakita ng sketch na ito kung paano paganahin ang dalawang LED
 * gamit ang iba't ibang aktibong antas ng lohika (active HIGH at active LOW).
 * Gumagamit ito ng `LundayTibok` library para sa awtomatikong pagtibok ng LED.
 * 
 * - LED sa pin 6: Active HIGH (HIGH = ON, LOW = OFF)
 * - LED sa pin 7: Active LOW  (LOW = ON, HIGH = OFF)
 * 
 * @note Tiyaking tama ang koneksiyon ng LED para maiwasan ang maling indikasyon.
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include <Arduino.h>
#include "LundayTibok.h"

#define LED_HIGH_PIN 6  ///< GPIO pin para sa Active High LED
#define LED_LOW_PIN 7   ///< GPIO pin para sa gagawing Active Low LED

// Paglikha ng dalawang LED gamit ang LundayTibok library
LundayTibok ledHigh(LED_HIGH_PIN, NORMAL);  ///< LED na Active High
LundayTibok ledLow(LED_LOW_PIN, NORMAL);    ///< LED na Active Low

void setup() {
    Serial.begin(115200);
    
    // Pagsisimula ng LED na may tamang antas ng lohika
    ledHigh.begin(true);   // Active HIGH mode
    ledLow.begin(false);   // Active LOW mode

    Serial.println("Simula ng dalawang LED test...");
}

void loop() {
    // Patuloy na i-update ang estado ng LED para sa tamang pagkislap
    ledHigh.update();
    ledLow.update();
}
