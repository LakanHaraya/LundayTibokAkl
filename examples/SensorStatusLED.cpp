/**
 * @file SensorStatusLED.cpp
 * @brief Pagpapakita ng status ng sensor gamit ang LED blinking patterns.
 * 
 * Ipinapakita ng sketch na ito kung paano awtomatikong mabago ang blink
 * mode ng LED batay sa pagbabasa mula sa isang analog sensor (o potentiometer).
 * 
 * - Kapag mataas ang sensor value (> 450), ang LED ay titibok sa EMERGENCY mode.
 * - Kapag nasa pagitan ng 300 at 450, ang LED ay nasa CRITICAL mode.
 * - Kapag nasa pagitan ng 150 at 300, ang LED ay nasa WARNING mode.
 * - Kapag mababa ang sensor value (< 150), ang LED ay nasa NORMAL mode.
 * 
 * @note Ang sensor ay dapat konektado sa analog pin A0 (halimbawa: potentiometer).
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include <Arduino.h>
#include "LundayTibok.h"

LundayTibok statusLED(13, NORMAL);  ///< LED sa pin 13, default blink mode: NORMAL

void setup() {
    Serial.begin(115200);
    statusLED.begin();
}

void loop() {
    // Sinisimulasyon ang pagbabago ng status batay sa halaga ng analog sensor
    int sensorValue = analogRead(A0); // Halimbawa: pagbabasa mula sa sensor sa pin A0 (hal. potentiometer).
    
    if (sensorValue > 450) {
        statusLED.setBlinkMode(EMERGENCY);
    } else if (sensorValue > 300) {
        statusLED.setBlinkMode(CRITICAL);
    } else if (sensorValue > 150) {
        statusLED.setBlinkMode(WARNING);
    } else {
        statusLED.setBlinkMode(NORMAL);
    }
    
    statusLED.update(); // Isapanahon ang LED blink status

    // Ipakita ang kasalukuyang sensor value at LED status sa Serial Monitor
    Serial.print(sensorValue);
    Serial.print(" [");
    Serial.print(statusLED.getBlinkMode());
    Serial.println("]");
}
