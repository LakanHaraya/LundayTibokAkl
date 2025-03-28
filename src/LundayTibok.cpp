#include "LundayTibok.h"

LundayTibok::LundayTibok(int ledPin, BlinkMode mode, bool usePWM)
    : _ledPin(ledPin), _interval(mode), _lastToggleTime(0), _ledState(false),
      _activeHigh(true), _usePWM(usePWM), _brightness(128), _isDisabled(false) {}

void LundayTibok::begin(bool activeHigh) {
    _activeHigh = activeHigh;
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, _activeHigh ? LOW : HIGH);
}

void LundayTibok::update() {
    if (_isDisabled) return;

    unsigned long currentMillis = millis();
    if (currentMillis - _lastToggleTime >= static_cast<unsigned long>(_interval)) {
        _lastToggleTime = currentMillis;
        _ledState = !_ledState;

        if (_usePWM) {
            analogWrite(_ledPin, _ledState ? _brightness : 0);
        } else {
            digitalWrite(_ledPin, _ledState == _activeHigh ? HIGH : LOW);
        }
    }
}

void LundayTibok::setBlinkMode(BlinkMode mode) {
    if (mode != EMERGENCY && mode != CRITICAL && mode != WARNING && mode != NORMAL && mode != DISABLED) {
        Serial.println("[BALA] Maling `BlinkMode`! Hindi ito itatakda.");
        return;
    }
    _interval = mode;
}

void LundayTibok::setPWM(int brightness) {
    if (!_usePWM) {
        Serial.println("[BALA] Ang PWM ay hindi pinagana! Hindi puwedeng magtakda ng tingkad.");
        return; 
    }
    _brightness = constrain(brightness, 0, 255);
}

void LundayTibok::disable() {
    _isDisabled = true;
    digitalWrite(_ledPin, _activeHigh ? LOW : HIGH);
}

void LundayTibok::enable() {
    _isDisabled = false;
}

//* Getter Methods!!
const char* LundayTibok::getBlinkMode() const {
    switch (_interval) {
        case EMERGENCY: return "KAGIPITAN";
        case CRITICAL: return "KRITIKAL";
        case WARNING: return "BABALA";
        case NORMAL: return "KARANIWAN";
        case DISABLED: return "HINDI AKTIBO";
        default: return "DI-BATID";
    }
}
