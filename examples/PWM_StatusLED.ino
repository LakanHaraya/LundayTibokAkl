/**
 * @file PWM_StatusLED.cpp
 * @brief Pagsasaayos ng tingkad at antas ng pagtibok ng LED (bilang indikador) gamit ang potentiometer (sensor) input.
 * 
 * Ipinapakita ng sketch na ito kung paano gamitin ang LundayTibok library upang:
 * - Baguhin ang antas ng pagtibok ng LED batay sa pagbasa sa potentiometer (o sensor).
 * - Gumamit ng PWM upang isaayos ang tingkad ng LED depende sa potentiometer (sensor) value.
 * 
 * **Pin Assignments:**
 * - **LED_PIN (6)** → LED na may PWM control.
 * - **SENSOR_PIN (A0)** → Analog sensor (hal. potentiometer o light sensor).
 * 
 * **Antas ng Pagtibok (Batay sa IEC 60073):**
 * - **EMERGENCY** (4 Hz) → Kapag mataas ang sensor value (> 600)
 * - **CRITICAL** (2 Hz) → Kapag nasa pagitan ng 451–600
 * - **WARNING** (1 Hz) → Kapag nasa pagitan ng 301–450
 * - **NORMAL** (0.5 Hz) → Kapag mababa ang sensor value (≤ 300)
 * 
 * @note Ang `map()` function ay ginagamit upang i-scale ang sensor reading (0-700)
 *       papunta sa PWM brightness range (0-255).
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include <Arduino.h>
#include "LundayTibok.h"

#define LED_PIN 6       ///< PWM-capable pin (e.g., 3, 5, 6, 9, 10, 11 sa Arduino Uno)
#define SENSOR_PIN A0   ///< Analog input pin (potentiometer o light sensor)

LundayTibok statusLED(LED_PIN, NORMAL, true); // LED na may PWM support

void setup() {
    Serial.begin(115200);
    statusLED.begin();
}

void loop() {
    int potValue = analogRead(SENSOR_PIN);
    int brightness = map(potValue, 0, 700, 0, 255); // Isaayos ayon sa potentiometer (sensor) range ng iyong hardware

    // Kusang babaguhin ang antas ng pagtibok batay sa pot (sensor) value
    if (potValue > 600) {
        statusLED.setHeartbeatLevel(EMERGENCY);
    } else if (potValue > 450) {
        statusLED.setHeartbeatLevel(CRITICAL);
    } else if (potValue > 300) {
        statusLED.setHeartbeatLevel(WARNING);
    } else {
        statusLED.setHeartbeatLevel(NORMAL);
    }

    statusLED.setPWM(brightness);
    statusLED.update();

    // Ipakita ang status sa Serial Monitor
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print(" | Antas ng Pagtibok: ");
    Serial.print(statusLED.getHeartbeatLevel());
    Serial.print(" | Tingkad: ");
    Serial.println(brightness);
}
