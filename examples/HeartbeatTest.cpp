#include <LundayTibok.h>

LundayTibok led(13, NORMAL);

void setup() {
    led.begin();
}

void loop() {
    led.update();
}