🗃️ *Malapamantayan:* **LNDH-0051**  
# 📖 Documentation of `LundayTibokAkl\` 

📖 Available Versions:  
🇵🇭 [Filipino* (Up-to-date)](README.md) | 🇺🇸 ***English***  
  
📅 **Version:** 1.0.0 (27 March 2025)  
👨‍💻 **Author:** Lakan Haraya Dima  
📩 **Email:** lakanharaya@gmail.com  
🔗 **GitHub:** https://github.com/LakanHaraya  

## 🔍 Introduction

`LundayTibokAkl\` is an Arduino library that provides a mechanism for LED heartbeat effect using two intervals. It supports both active-high and active-low LED configurations.

This library was developed to minimize the use of `delay()` and ensure more efficient non-blocking LED blinking, which is useful for projects requiring multitasking within the Arduino loop.

# 📑 Table of Contents

- [📖 Documentation of `LundayTibokAkl\`](#📖-documentation-of-lundaytibokakl)
- [🔍 Introduction](#🔍-introduction)
- [🎯 Mga Tampok](#🎯-mga-tampok)
- [⚙️ Installation](#⚙️-installation)
  - [Manual Installation](#manual-installation)
  - [Installation from GitHub](#installation-from-github)
- [📌 API Reference](#📌-api-reference)
  - [🔹 Creating an Instance](#🔹-creating-an-instance)
  - [🔹 Initializing LED Heartbeat](#🔹-initializing-led-heartbeat)
  - [🔹 Updating LED Heartbeat](#🔹-updating-led-heartbeat-must-be-called-in-loop)
  - [🔹 Getter Functions](#🔹-getter-functions)
- [🛠 Usage Examples](#🛠-usage-examples)
  - [🔸 Simple Usage](#🔸-simple-usage)
  - [🔸 Dynamically Changing Intervals](#🔸-dynamically-changing-intervals)
- [📂 Library Structure](#📂-library-structure)
- [🛑 Debugging and Troubleshooting](#🛑-debugging-and-troubleshooting)
- [📝 License](#📝-license)
- [🔗 Changelog](#🔗-changelog)
  - [🆕 Version 1.0.0 (27 March 2025)](#🆕-version-100-27-march-2025)
- [📢 Questions?](#📢-questions)
- [🎯 Conclusion](#🎯-conclusion)


## 🎯 Features

✅ **Supports Active-High and Active-Low LED Configuration**  
✅ **Two Intervals for Flexible LED Heartbeat**  
✅ **Non-blocking LED Control Using `millis()`**  
✅ **Getter Methods for Real-Time Query of LED State**  
✅ **Simple API for Easy Integration**

---
## ⚙️ Installation

### Manual Installation

 1. Download the `LundayTibokAkl` repository.

 2. Place the folder inside `Arduino/libraries/`.

 3. Ensure the following files are inside `LundayTibokAkl/`:

    - `LundayTibok.h`

    - `LundayTibok.cpp`

    - `library.properties`

### Installation from GitHub

``` sh
git clone https://github.com/LakanHaraya/LundayTibokAkl.git
```

## 📌 API Reference

### 🔹 Creating an Instance

``` cpp
LundayTibok heartbeat(ledPin, interval1, interval2);
```

- `ledPin` (int) → The GPIO pin of the LED.
- `interval1` (unsigned long, default = 500) → First heartbeat interval (in milliseconds).
- `interval2` (unsigned long, default = 500) → Second heartbeat interval (in milliseconds).

### 🔹 Initializing LED Heartbeat

``` cpp
heartbeat.begin(activeHigh);
```
- `activeHigh` (bool, default = `true`) →   
  - `true` → LED is ON when **HIGH**
  - `false` → LED is ON when **LOW**

### 🔹 Updating LED Heartbeat *(Must be called in `loop()`)*

``` cpp
heartbeat.update(); // Updates LED state
```
When `update()` is called, the library checks the current time (`millis()`) and determines when the LED state should change.

**Flowchart**
``` txt
LED Pulse Logic


              +---------------------------+
    --------> |      Start of Loop        |
    ^         +---------------------------+
    |                       |
    |                       v
    |       +-----------------------------+
    |       | Get the current time using  |
    |       |         `millis()`          |
    |       +-----------------------------+
    |                       |
    |                       v
    |   +--------------------------------------------------------+
    |   |     Check if it's time to change the LED state         |
    |   | ((currentMillis - _lastToggleTime) >= currentInterval) |
    |   +--------------------------------------------------------+
    |                       |               |
    |               (No)    |               | (Yes)
    |                       v               |
    |   +------------------------------+    |
    |<--| Wait and return to the loop  |    |
        +------------------------------+    |
                                            |
                                            v
                +-------------------------------------+
                | Set the last toggle time variable  |
                +-------------------------------------+
                            |
                            v
              +---------------------------+
              |   Change LED State        |
              +---------------------------+
                            |
                            v
        +-----------------------------------------------------+
        |         Update the LED pin state accordingly        |
        | (HIGH/LOW depending on the `activeHigh` setting)    |
        +-----------------------------------------------------+
                            |
                            v
                +----------------------+
                |   End of Iteration   |
                +----------------------+
                            |
                            v
                +----------------------+
                |   Repeat the Loop    |
                +----------------------+
```

### 🔹 Getter Functions
``` cpp
int pin = heartbeat.getLedPin();               // Get LED pin
unsigned long i1 = heartbeat.getInterval1();   // Get first interval
unsigned long i2 = heartbeat.getInterval2();   // Get second interval
bool isHigh = heartbeat.isActiveHigh();        // Check if active-high or active-low
bool isOn = heartbeat.isLedOn();               // Check if LED is ON
```

## 🛠 Usage Examples

### 🔸 Simple Usage

``` cpp
#include <LundayTibok.h>

LundayTibok heartbeat(13, 500, 300); // LED on pin 13, 500ms and 300ms interval

void setup() {
    heartbeat.begin(true); // Active-high configuration
}

void loop() {
    heartbeat.update(); // Continuous LED heartbeat
}
```

### 🔸 Dynamically Changing Intervals

``` cpp
#include <LundayTibok.h>

LundayTibok heartbeat(13, 1000, 200);

void setup() {
    heartbeat.begin(true);
}

void loop() {
    heartbeat.update();
    
    if (millis() > 10000) { // After 10 seconds, change intervals
        heartbeat = LundayTibok(13, 200, 1000);
        heartbeat.begin(true);
    }
}
```

## 📂 Library Structure

``` sh
LundayTibokAkl/
 ├── library.properties
 ├── src/
 │   ├── LundayTibok.h
 │   ├── LundayTibok.cpp
 ├── examples/
 │   ├── TibokGetter.cpp
 │   ├── TibokPasadya.cpp
 │   ├── TibokSimple.cpp
 ├── docs/
 │   ├── README.md
 │   ├── README_EN.md
```

## 🛑 Debugging and Troubleshooting

| Issue | Possible Cause | Solution |
| :-- | :-- | :-- |
| **LED Does Not Blink** | *Incorrect LED wiring (missing resistor?)* | Ensure proper wiring and use a current-limiting resistor (220Ω ~ 1kΩ). |
| **Blinking Too Fast/Slow** | *Incorrect interval values* | Ensure correct `interval1` and `interval2` values are passed to the constructor. |
| **LED Not Synchronized with Other Code** | *`delay()` used elsewhere in the code* | Avoid `delay()`, use `millis()` for timing. | 

## 📝 License

`LundayTibokAkl` is open-source software under the MIT License. You are free to use, modify, and distribute it.

## 🔗 Changelog

### 🆕 Version 1.0.0 (27 March 2025)

✅ Initial release with core functionality.  
✅ Support for active-high and active-low LED configurations.  
✅ Two intervals for LED heartbeat.  
✅ Getter functions for easier debugging.

## 📢 Questions?

For inquiries, suggestions, or contributions, please contact:

📩 **Email:** lakanharaya@gmail.com  
🔗 **GitHub:** https://github.com/LakanHaraya

## 🎯 Conclusion

`LundayTibokAkl` is an efficient Arduino library designed to simplify and optimize **LED heartbeat effects** using a non-blocking approach.

If you want to contribute or share suggestions, **we welcome your ideas!** 🚀

