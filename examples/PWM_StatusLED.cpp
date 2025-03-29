/**
 * @file PWM_StatusLED.cpp
 * @brief Pagsasaayos ng liwanag at blinking mode ng LED gamit ang sensor input.
 * 
 * Ipinapakita ng sketch na ito kung paano gamitin ang LundayTibok library upang:
 * - Magpalit ng LED blinking mode batay sa sensor reading.
 * - Gumamit ng PWM upang isaayos ang liwanag ng LED depende sa sensor value.
 * 
 * **Pin Assignments:**
 * - **LED_PIN (6)** → LED na may PWM control.
 * - **SENSOR_PIN (A0)** → Analog sensor (hal. potentiometer o light sensor).
 * 
 * **Blinking Modes (Batay sa IEC 60073):**
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
    int sensorValue = analogRead(SENSOR_PIN);
    int brightness = map(sensorValue, 0, 700, 0, 255); // Isaayos ayon sa sensor range ng iyong hardware

    // Baguhin ang blink mode batay sa sensor value
    if (sensorValue > 600) {
        statusLED.setBlinkMode(EMERGENCY);
    } else if (sensorValue > 450) {
        statusLED.setBlinkMode(CRITICAL);
    } else if (sensorValue > 300) {
        statusLED.setBlinkMode(WARNING);
    } else {
        statusLED.setBlinkMode(NORMAL);
    }

    statusLED.setPWM(brightness);
    statusLED.update();

    // Ipakita ang status sa Serial Monitor
    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | Moda ng Kislap: ");
    Serial.print(statusLED.getBlinkMode());
    Serial.print(" | Tingkad: ");
    Serial.println(brightness);
}
