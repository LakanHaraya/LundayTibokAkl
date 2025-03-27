/**
 * @file LundayTibok.h
 * @brief LED blinking library na may configurable intervals.
 */

#ifndef LUNDAYTIBOK_H
#define LUNDAYTIBOK_H

#include <Arduino.h>

/**
 * @class LundayTibok
 * @brief Class para sa LED blinking na may dalawang agwat ng pagpindi-sindi.
 */
class LundayTibok {
private:
    int _ledPin;                    ///< Pin na kinokontrol ang LED
    unsigned long _interval1;       ///< Tagal ng unang estado (ON o OFF)
    unsigned long _interval2;       ///< Tagal ng pangalawang estado (OFF o ON)
    unsigned long _lastToggleTime;  ///< Huling oras ng pagbabago ng estado
    bool _ledState;                 ///< Kasalukuyang estado ng LED (true = ON, false = OFF)
    bool _activeHigh;               ///< Uri ng LED control (true = active HIGH, false = active LOW)

public:
    /**
     * @brief Gumagawa ng LundayTibok object.
     * @param ledPin Ang LED pin number.
     * @param interval1 Tagal ng unang estado sa milliseconds (default: 500ms).
     * @param interval2 Tagal ng pangalawang estado sa milliseconds (default: 500ms).
     */
    LundayTibok(int ledPin, unsigned long interval1 = 500, unsigned long interval2 = 500);

    /**
     * @brief Sinisimulan ang LED blink system.
     * @param activeHigh Kung `true`, `HIGH` = ON. Kung `false`, `LOW` = ON (default: `true`).
     */
    void begin(bool activeHigh = true);

    /**
     * @brief Ina-update ang estado ng LED batay sa itinakdang intervals.
     */
    void update();

    /// @name Getter Functions
    /// Mga function upang kunin ang kasalukuyang configuration.
    /// @{

    /**
     * @brief Kinukuha ang LED pin number.
     * @return Pin number ng LED.
     */
    int getLedPin() const;

    /**
     * @brief Kinukuha ang unang interval duration.
     * @return Tagal ng unang estado sa milliseconds.
     */
    unsigned long getInterval1() const;

    /**
     * @brief Kinukuha ang pangalawang interval duration.
     * @return Tagal ng pangalawang estado sa milliseconds.
     */
    unsigned long getInterval2() const;

    /**
     * @brief Suriin kung active high o active low ang LED control.
     * @return `true` kung active high, `false` kung active low.
     */
    bool isActiveHigh() const;

    /**
     * @brief Kinukuha ang kasalukuyang estado ng LED.
     * @return `true` kung LED ay kasalukuyang naka-ON, `false` kung naka-OFF.
     */
    bool isLedOn() const;

    /// @}
};

#endif 
