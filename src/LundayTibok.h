#ifndef LUNDAYTIBOK_H
#define LUNDAYTIBOK_H

#include <Arduino.h>

// IEC 60073 Blink Modes
enum BlinkMode {
    EMERGENCY = 125,  // 4 Hz (125ms ON, 125ms OFF)
    CRITICAL = 250,   // 2 Hz (250ms ON, 250ms OFF)
    WARNING = 500,    // 1 Hz (500ms ON, 500ms OFF)
    NORMAL = 1000,    // 0.5 Hz (1s ON, 1s OFF)
    DISABLED = -1     // Para sa "LED OFF" mode
};

class LundayTibok {
private:
    int _ledPin;
    BlinkMode _interval;
    unsigned long _lastToggleTime;
    bool _ledState;
    bool _activeHigh;
    bool _usePWM;
    int _brightness;
    bool _isDisabled;

public:
    LundayTibok(int ledPin, BlinkMode mode, bool usePWM = false);
    void begin(bool activeHigh = true);
    void update();
    void setBlinkMode(BlinkMode mode);
    void setPWM(int brightness);
    void disable();
    void enable();

    // Getter methods
    const char* getBlinkMode() const;
};

#endif