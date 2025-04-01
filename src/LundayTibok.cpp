#include "LundayTibok.h"

LundayTibok::LundayTibok(int indicatorPin, HeartbeatLevel level, bool usePWM)
    : _indicatorPin(indicatorPin), _interval(level), _lastToggleTime(0), _indicatorState(false),
      _activeHigh(true), _usePWM(usePWM), _intensity(128), _isDisabled(false) {}

void LundayTibok::begin(bool activeHigh) {
    _activeHigh = activeHigh;
    pinMode(_indicatorPin, OUTPUT);
    digitalWrite(_indicatorPin, _activeHigh ? LOW : HIGH);
}

void LundayTibok::update() {
    if (_isDisabled) return;

    unsigned long currentMillis = millis();
    if (currentMillis - _lastToggleTime >= static_cast<unsigned long>(_interval)) {
        _lastToggleTime = currentMillis;
        _indicatorState = !_indicatorState;

        if (_usePWM) {
            analogWrite(_indicatorPin, _indicatorState ? _intensity : 0);
        } else {
            digitalWrite(_indicatorPin, _indicatorState == _activeHigh ? HIGH : LOW);
        }
    }
}

void LundayTibok::setHeartbeatLevel(HeartbeatLevel level) {
    if (level != EMERGENCY && level != CRITICAL && level != WARNING && level != NORMAL && level != DISABLED) {
        Serial.println("[BALA] Maling `HeartbeatLevel`! Hindi ito itatakda.");
        return;
    }
    _interval = level;
}

void LundayTibok::setPWM(int intensity) {
    if (!_usePWM) {
        Serial.println("[BALA] Ang PWM ay hindi pinagana! Hindi puwedeng magtakda ng intensidad.");
        return; 
    }
    _intensity = constrain(intensity, 0, 255);
}

void LundayTibok::disable() {
    _isDisabled = true;
    digitalWrite(_indicatorPin, _activeHigh ? LOW : HIGH);
}

void LundayTibok::enable() {
    _isDisabled = false;
}

//* Getter Methods!!
const char* LundayTibok::getHeartbeatLevel() const {
    switch (_interval) {
        case EMERGENCY: return "KAGIPITAN";
        case CRITICAL: return "KRITIKAL";
        case WARNING: return "BABALA";
        case NORMAL: return "KARANIWAN";
        case DISABLED: return "HINDI AKTIBO";
        default: return "DI-BATID";
    }
}
