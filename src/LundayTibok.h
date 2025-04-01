/**
 * @file LundayTibok.h
 * @brief Kontrol ng pagtibok gamit ang IEC 60073:2002 na mga pattern ng pagtibok batay sa antas ng alerto.
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
 * @enum HeartbeatLevel
 * @brief Mga bilis ng pagtibok batay sa IEC 60073:2002.
 */
enum HeartbeatLevel {
    EMERGENCY = 125,  ///< 4 Hz (125ms SINDI, 125ms PINDI)
    CRITICAL = 250,   ///< 2 Hz (250ms SINDI, 250ms PINDI)
    WARNING = 500,    ///< 1 Hz (500ms SINDI, 500ms PINDI)
    NORMAL = 1000,    ///< 0.5 Hz (1s SINDI, 1s PINDI)
    DISABLED = -1     ///< Palaging nakapindi (OFF) ang indikador
};

/**
 * @class LundayTibok
 * @brief Pamamahala ng tibok gamit ang nakatakdang antas ng pagtibok at PWM.
 */
class LundayTibok {
private:
    int _indicatorPin;              ///< Numero ng pin ng indikador.
    HeartbeatLevel _interval;       ///< Kasalukuyang antas ng pagtibok.
    unsigned long _lastToggleTime;  ///< Huling pagbabago ng estado.
    bool _indicatorState;           ///< Kasalukuyang estado ng indikador.
    bool _activeHigh;               ///< Kung aktibo sa HIGH o LOW.
    bool _usePWM;                   ///< Kung gumagamit ng PWM.
    int _intensity;                 ///< Intensidad ng indikador (0-255).
    bool _isDisabled;               ///< Kung hindi pinagana ang indikador.

public:
    /**
     * @brief Gumagawa ng bagong LundayTibok objek.
     * @param indicatorPin Ang GPIO pin na nakakonekta sa indikador.
     * @param level Paunang antas ng pagtibok.
     * @param usePWM Gamitin ang PWM (pinatakda: `false`).
     */
    LundayTibok(int indicatorPin, HeartbeatLevel level, bool usePWM = false);

    /**
     * @brief Sinisimulan ang tibok na may nakatakdang antas ng lohika.
     * @param activeHigh Itakda sa `true` kung active HIGH, at `false` kung 
     * active LOW. (pinatakda: `true`)
     */
    void begin(bool activeHigh = true);

    /**
     * @brief Isinasapanahon ang estado ng indikador ayon sa kasalukuyang antas.
     * 
     * Dapat itong tawagin sa `loop()` upang mapanatili ang tamang pagtibok.
     */
    void update();

    /**
     * @brief Itinatakda ang bagong antas ng pagtibok.
     * @param level Ang bagong `HeartbeatLevel`.
     */
    void setHeartbeatLevel(HeartbeatLevel level);

    /**
     * @brief Itinatakda ang intensidad ng indikador kung nasa moda ng PWM.
     * @param intensity Halaga mula 0 (pindi) hanggang 255 (pinakamatindi).
     */
    void setPWM(int intensity);

    /**
     * @brief Hinihinto ang pagtibok ng indikador at pinipindi (OFF) ito.
     */
    void disable();

    /**
     * @brief Pinapagana muli (ON) ang pagtibok ng indikador.
     */
    void enable();

    //* Getter methods!

    /**
     * @brief Kinukuha ang kasalukuyang antas ng pagtibok bilang teksto.
     * @return Pangalan ng antas bilang string.
     */
    const char* getHeartbeatLevel() const;
};

#endif