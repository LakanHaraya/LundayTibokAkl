// LundayTibok.cpp - Implementation file
#include "LundayTibok.h"

LundayTibok::LundayTibok(int ledPin, unsigned long interval1, unsigned long interval2)
    : _ledPin(ledPin), _interval1(interval1), _interval2(interval2), _lastToggleTime(0), _ledState(false), _activeHigh(true) {}

void LundayTibok::begin(bool activeHigh) {
    _activeHigh = activeHigh;
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, _activeHigh ? LOW : HIGH);
}

void LundayTibok::update() {
    unsigned long currentMillis = millis();
    unsigned long currentInterval = _ledState ? _interval2 : _interval1;

    if (currentMillis - _lastToggleTime >= currentInterval) {
        _lastToggleTime = currentMillis;
        _ledState = !_ledState;
        digitalWrite(_ledPin, _ledState == _activeHigh ? HIGH : LOW);
    }
}

// Getter function implementations
int LundayTibok::getLedPin() const {
    return _ledPin;
}

unsigned long LundayTibok::getInterval1() const {
    return _interval1;
}

unsigned long LundayTibok::getInterval2() const {
    return _interval2;
}

bool LundayTibok::isActiveHigh() const {
    return _activeHigh;
}

bool LundayTibok::isLedOn() const {
    return _ledState;
}
