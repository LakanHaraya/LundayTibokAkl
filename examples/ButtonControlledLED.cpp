/**
 * @file ButtonControlledLED.cpp
 * @brief Pagkontrol sa LED (bilang indikador) gamit ang isang push button.
 * 
 * Ipinapakita ng sketch na ito kung paano paganahin at huwag paganahin 
 * ang LED gamit ang isang push button. Ginagamit nito ang `LundayTibok` 
 * library upang awtomatikong mapamahala ang epekto ng pagtibok ng LED.
 * 
 * - Kapag ang button ay pinindot, ang LED ay hindi pagaganahin (disable).
 * - Kapag binitawan ang button, ang LED ay muling titibok (enable).
 * 
 * @note Ang button ay dapat konektado sa pin 2 at nakakumpigura sa INPUT_PULLUP.
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#include "LundayTibok.h"

#define LED_PIN 13       ///< GPIO pin ng LED
#define BUTTON_PIN 2     ///< GPIO pin ng push button

LundayTibok led(LED_PIN, NORMAL);  ///< LED na may normal na heartbeat mode

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Gamitin ang internal pull-up resistor
    led.begin();
}

void loop() {
    led.update();  // Panatilihin ang tamang asal ng pagtibok

    if (digitalRead(BUTTON_PIN) == LOW) { // Kapag pinindot ang button (panatilihing nakadiin)
        Serial.println("LED Di-pinagana!");
        led.disable();
        delay(100); // Debounce delay upang maiwasan ang maramihang triggers
    } else {
        Serial.println("LED Pinagana!");
        led.enable();
    }
}
