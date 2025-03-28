#include <Arduino.h>
#include "LundayTibok.h"

LundayTibok statusLED(13, NORMAL); // LED sa pin 13, default blink mode: NORMAL

void setup() {
    Serial.begin(115200);
    statusLED.begin();
}

void loop() {
    // Sinisimulasyon ang pagbabago ng katayuan batay sa halaga ng analog sensor
    int sensorValue = analogRead(A0); // Halimbawa: pagbabasa mula sa sensor sa pin A0 (palitan ng potentiometer).
    
    if (sensorValue > 450) {
        statusLED.setBlinkMode(EMERGENCY);
    } else if (sensorValue > 300) {
        statusLED.setBlinkMode(CRITICAL);
    } else if (sensorValue > 150) {
        statusLED.setBlinkMode(WARNING);
    } else {
        statusLED.setBlinkMode(NORMAL);
    }
    
    statusLED.update(); // I-update ang LED blink status
    Serial.print(sensorValue);
    Serial.print(" [");
    Serial.print(statusLED.getBlinkMode());
    Serial.println("]");
}