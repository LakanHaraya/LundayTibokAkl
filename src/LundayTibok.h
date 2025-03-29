/**
 * @file LundayTibok.h
 * @brief Kontrol ng pagtibok gamit ang IEC 60073 na mga pattern ng pagkislap.
 * 
 * Sinusuportahan ang PWM at ang iba't ibang moda ng pagtibok.
 * May kakayahang paganahin, huwag paganahin, at kunin ang kasalukuyang estado.
 * 
 * @author Lakan Haraya Dima
 * @date 29 Marso 2025
 */

#ifndef LUNDAYTIBOK_H
#define LUNDAYTIBOK_H

#include <Arduino.h>

/**
 * @enum BlinkMode
 * @brief Mga bilis ng pagkislap batay sa IEC 60073.
 */
enum BlinkMode {
    EMERGENCY = 125,  ///< 4 Hz (125ms SINDI, 125ms PINDI)
    CRITICAL = 250,   ///< 2 Hz (250ms SINDI, 250ms PINDI)
    WARNING = 500,    ///< 1 Hz (500ms SINDI, 500ms PINDI)
    NORMAL = 1000,    ///< 0.5 Hz (1s SINDI, 1s PINDI)
    DISABLED = -1     ///< Palaging nakapindi ang LED
};

/**
 * @class LundayTibok
 * @brief Pamamahala ng pagtibok gamit ang nakatakdang bilis ng pagkislap at PWM.
 */
class LundayTibok {
private:
    int _ledPin;                    ///< Numero ng LED pin.
    BlinkMode _interval;            ///< Kasalukuyang bilis ng pagkislap.
    unsigned long _lastToggleTime;  ///< Huling pagbabago ng estado.
    bool _ledState;                 ///< Kasalukuyang estado ng LED.
    bool _activeHigh;               ///< Kung aktibo sa HIGH o LOW.
    bool _usePWM;                   ///< Kung gumagamit ng PWM.
    int _brightness;                ///< Liwanag ng LED (0-255).
    bool _isDisabled;               ///< Kung hindi pinagana ang LED.

public:
    /**
     * @brief Gumagawa ng bagong LundayTibok objek.
     * @param ledPin Ang GPIO pin na nakakonekta sa LED.
     * @param mode Paunang moda ng pagkislap.
     * @param usePWM Gamitin ang PWM (pinatakda: `false`).
     */
    LundayTibok(int ledPin, BlinkMode mode, bool usePWM = false);

    /**
     * @brief Sinisimulan ang pagtibok na may nakatakdang antas ng lohika.
     * @param activeHigh Itakda sa `true` kung active HIGH, at `false` kung 
     * active LOW. (pinatakda: `true`)
     */
    void begin(bool activeHigh = true);

    /**
     * @brief Isinasapanahon ang estado ng LED ayon sa kasalukuyang moda.
     * 
     * Dapat itong tawagin sa `loop()` upang mapanatili ang tamang pagkislap.
     */
    void update();

    /**
     * @brief Itinatakda ang bagong moda ng pagkislap.
     * @param mode Ang bagong `BlinkMode`.
     */
    void setBlinkMode(BlinkMode mode);

    /**
     * @brief Itinatakda ang liwanag ng LED kung nasa moda ng PWM.
     * @param brightness Halaga mula 0 (pindi) hanggang 255 (pinakamaliwanag).
     */
    void setPWM(int brightness);

    /**
     * @brief Hinihinto ang pagkislap ng LED at pinipindi (OFF) ito.
     */
    void disable();

    /**
     * @brief Pinapagana muli (ON) ang pagkislap ng LED.
     */
    void enable();

    //* Getter methods!

    /**
     * @brief Kinukuha ang kasalukuyang moda ng pagkislap bilang teksto.
     * @return Pangalan ng moda bilang string.
     */
    const char* getBlinkMode() const;
};

#endif