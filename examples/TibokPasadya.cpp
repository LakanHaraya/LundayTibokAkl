/*
  LundayTibok Example - Custom Blink Timing with Active Low

  Ang sketch na ito ay nagpapakita kung paano gamitin ang LundayTibok library 
  upang patibukin ang isang LED na may pasadyang tagal ng ON at OFF states.

  Hardware:
  - LED na nakakonekta sa pin 8 (gamit ang tamang resistor)
  - Arduino-compatible board

  Mga Setting:
  - ON duration: 300ms
  - OFF duration: 700ms
  - Active low mode (LED ay naka-ON kapag LOW, naka-OFF kapag HIGH)

  Ang `millis()` ay ginagamit upang mapanatili ang tuloy-tuloy na operasyon 
  nang walang paggamit ng `delay()`. 

  (C) 2025 LundayHangin Project
*/

#include "LundayTibok.h"

LundayTibok tibok(8, 300, 700); // LED sa pin 8, 300ms ON, 700ms OFF

void setup() {
    tibok.begin(false); // Active low (LOW = ON, HIGH = OFF)
}

void loop() {
    tibok.update();
}
