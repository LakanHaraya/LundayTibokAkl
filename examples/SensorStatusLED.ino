/**
 * @file SensorStatusLED.cpp
 * @brief Pagpapakita ng status ng sensor gamit ang LED pattern ng pagtibok.
 * 
 * Ipinapakita ng sketch na ito kung paano awtomatikong mababago ang antas ng
 * pagtibok ng LED batay sa pagbabasa mula sa isang analog
 * potentiometer (o sensor).
 * 
 * - Kapag mataas ang pot value (> 450), ang LED ay titibok sa EMERGENCY level.
 * - Kapag nasa pagitan ng 300 at 450, ang LED ay nasa CRITICAL level.
 * - Kapag nasa pagitan ng 150 at 300, ang LED ay nasa WARNING level.
 * - Kapag mababa ang pot value (< 150), ang LED ay nasa NORMAL level.
 * 
 * @note Ang potentiometer (o sensor) ay dapat konektado sa analog pin A0.
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include <Arduino.h>
#include "LundayTibok.h"

LundayTibok statusLED(13, NORMAL);  ///< LED sa pin 13, pinatakdang antas ng pagtibok: NORMAL

void setup() {
    Serial.begin(115200);
    statusLED.begin();
}

void loop() {
    // Sinisimulasyon ang pagbabago ng status batay sa halaga ng pot
    int potValue = analogRead(A0); // Halimbawa: pagbabasa mula sa pot sa pin A0 (hal. sensorValue).
    
    if (potValue > 450) {
        statusLED.setHeartbeatLevel(EMERGENCY);
    } else if (potValue > 300) {
        statusLED.setHeartbeatLevel(CRITICAL);
    } else if (potValue > 150) {
        statusLED.setHeartbeatLevel(WARNING);
    } else {
        statusLED.setHeartbeatLevel(NORMAL);
    }
    
    statusLED.update(); // Isapanahon ang status ng pagtibok ng LED

    // Ipakita ang kasalukuyang pot value at LED status sa Serial Monitor
    Serial.print(potValue);
    Serial.print(" [");
    Serial.print(statusLED.getHeartbeatLevel());
    Serial.println("]");
}
