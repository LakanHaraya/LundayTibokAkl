/*
  LundayTibok Example - Basic LED Blinking

  Ang sketch na ito ay nagpapakita kung paano gamitin ang LundayTibok library 
  upang awtomatikong patibukin ang isang LED nang hindi gumagamit ng delay().

  Hardware:
  - LED na nakakonekta sa pin 13 (o built-in LED)
  - Arduino-compatible board

  Gumagamit ito ng `millis()` upang mapanatiling hindi hadlang ang LED blinking 
  sa iba pang proseso sa `loop()`. 

  (C) 2025 LundayHangin Project
*/

#include "LundayTibok.h"

LundayTibok tibok(13); // Default: LED sa pin 13, 500ms interval1, 500ms interval2

void setup() {
    tibok.begin(); // Default: Active high
}

void loop() {
    tibok.update(); // Magpa-flash ang LED nang kusa
}
