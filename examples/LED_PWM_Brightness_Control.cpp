#include <Arduino.h>
#include "LundayTibok.h"

#define LED_PIN 6       // PWM-capable pin (e.g., 3, 5, 6, 9, 10, 11 sa Arduino Uno)
#define SENSOR_PIN A0   // Analog input (potentiometer o light sensor)

LundayTibok statusLED(LED_PIN, NORMAL, true); // May PWM Support

void setup() {
    Serial.begin(115200);
    statusLED.begin();
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN);
    int brightness = map(sensorValue, 0, 700, 0, 255);    // Isaayos ayon sa saklaw ng hardware na ginagamit

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

    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | Moda ng Kislap: ");
    Serial.print(statusLED.getBlinkMode());
    Serial.print(" | Tingkad: ");
    Serial.println(brightness);
}
