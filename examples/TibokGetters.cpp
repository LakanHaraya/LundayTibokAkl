/*
  LundayTibok Example - Heartbeat LED with Serial Monitoring

  Ang sketch na ito ay nagpapakita kung paano gamitin ang LundayTibok library 
  upang patibukin ang isang LED gamit ang pasadyang agwat ng ON at OFF states. 
  Kasama rin ang Serial Monitor output upang ipakita ang kasalukuyang estado ng LED.

  Hardware:
  - LED na nakakonekta sa pin 13 (gamit ang tamang resistor)
  - Arduino-compatible board

  Mga Setting:
  - ON duration: 300ms
  - OFF duration: 700ms
  - Active low mode (LED ay naka-ON kapag LOW, naka-OFF kapag HIGH)

  Karagdagang Tampok:
  - Pagpapadala ng impormasyon sa Serial Monitor kabilang ang LED pin, agwat, 
    at kasalukuyang estado ng LED.
  - Gumagamit ng `delay(1000)` sa loop upang hindi maging masyadong mabilis ang 
    pag-update ng Serial Monitor.

  Ang `millis()` ay ginagamit upang mapanatili ang tuloy-tuloy na operasyon 
  nang walang paggamit ng `delay()` sa LED blinking logic.

  (C) 2025 LundayHangin Project
*/

#include "LundayTibok.h"

constexpr int heartbeatLED = 13;
LundayTibok tibok(heartbeatLED, 300, 700);  // Custom intervals: 300ms at 700ms

void setup() {
    Serial.begin(115200);
    Serial.println("Nagsisimula ang sistema...");

    tibok.begin(false); // Gumamit ng active low

    // Test Getter Functions
    Serial.print("Pin ng LED: "); Serial.println(tibok.getLedPin());
    Serial.print("Agwat 1: "); Serial.print(tibok.getInterval1()); Serial.println(" ms");
    Serial.print("Agwat 2: "); Serial.print(tibok.getInterval2()); Serial.println(" ms");
    Serial.print("Aktibong Mataas: "); Serial.println(tibok.isActiveHigh() ? "Oo" : "Hindi");
}

void loop() {
    tibok.update();
    Serial.print("Estado ng LED: "); Serial.println(tibok.isLedOn() ? "Nakasindi" : "Nakapindi");
    delay(1000);
}
