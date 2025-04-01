/**
 * @file MultiStatusLEDs.cpp
 * @brief Sabayang pagpapailaw ng maraming LED (bilang indikador) gamit ang iba't ibang pattern ng pagtibok.
 * 
 * Ipinapakita ng sketch na ito kung paano gamitin ang LundayTibok library upang 
 * sabay-sabay na paganahin ang apat na LED na may magkakaibang pattern ng pagtibok.
 * 
 * - **EMERGENCY LED** (Pin 13) - Bilis ng tibok: 4 Hz (125ms ON, 125ms OFF)
 * - **CRITICAL LED** (Pin 8) - Bilis ng tibok: 2 Hz (250ms ON, 250ms OFF)
 * - **WARNING LED** (Pin 7) - Bilis ng tibok: 1 Hz (500ms ON, 500ms OFF)
 * - **NORMAL LED** (Pin 6) - Bilis ng tibok: 0.5 Hz (1s ON, 1s OFF)
 * 
 * @note Siguraduhin na ang mga LED ay nakakonekta nang tama sa mga itinakdang GPIO pins.
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include <Arduino.h>
#include "LundayTibok.h"

#define LED1_PIN 13 ///< Unang LED (EMERGENCY level)
#define LED2_PIN 8  ///< Pangalawang LED (CRITICAL level)
#define LED3_PIN 7  ///< Pangatlong LED (WARNING level)
#define LED4_PIN 6  ///< Pang-apat na LED (NORMAL level)

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
