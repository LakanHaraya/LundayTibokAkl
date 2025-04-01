/**
 * @file HeartbeatTest.cpp
 * @brief Halimbawa ng paggamit ng LundayTibok library para sa indikador na LED.
 *
 * Ipinapakita ng halimbawa na ito kung paano mag-inisyalisa at i-update ang isang LED
 * gamit ang LundayTibok library. Ang LED ay kikislap sa isang pattern ng pagtibok.
 *
 * @details
 * - Mag-inisyalisa ng LED gamit ang `LundayTibok`.
 * - Ina-update ang LED sa `loop()` upang mapanatili ang pattern ng pagkislap.
 *
 * @note Ang LED ay dapat nakakonekta sa pin 13.
 *
 * @author Lakan Haraya Dima
 * @date 01 Abril 2025
 */

#include <LundayTibok.h>

// Subukan ang ibang mga antas: EMERGENCY, CRITICAL, WARNING, NORMAL, DISABLED
LundayTibok led(13, NORMAL);    

void setup() {
    led.begin();
}

void loop() {
    led.update();
}