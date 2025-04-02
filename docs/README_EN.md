
# 📖 `LundayTibokAkl` v2.1.2 <sub><sub>🌐*EN*</sub></sub>

🌐 *Languages:*
🇵🇭 [***Filipino**** *(Up-to-date)*](README.md) | 🇺🇸 **English** 

📜 *Malapamantayan:* **LNDH-0051** *(Active)*  
📅 *Publication Date:* **27 March 2025**  
🔢 *Version:* **v2.1.2** *(Stable)*  
🛠️ *Last Revision:* **02 April 2025**  
👨‍💻 *Author:* **Lakan Haraya Dima**   

## 1. What is `LundayTibokAkl`?

`LundayTibokAkl` is an Arduino-compatible library that provides a standardized
control mechanism for managing pulsating indicators such as LEDs, buzzers,
vibration motors, and more. It adheres to the [IEC 60073:2002](https://webstore.iec.ch/en/publication/587)
standard for different alert levels: ***EMERGENCY***, ***CRITICAL***, ***WARNING***, ***NORMAL***, and ***DISABLED***.

> This library is part of the *LundayHangin Project* but can be integrated into any microcontroller project that requires clear visual, auditory, or tactile feedback.  

## 2. Key Features

✅ **Standardized Heartbeat Levels:** *EMERGENCY*, *CRITICAL*, *WARNING*, *NORMAL*, and *DISABLED*  
✅ **PWM Support:** Allows control of intensity (e.g., brightness or volume)  
✅ **Enable/Disable Functionality:** Easily activate or deactivate the indicator  
✅ **Arduino-Compatible API:** Simple and easy to use  

## 3. Installation Guide

- Clone the repository:
    ```sh
    git clone https://github.com/LakanHaraya/LundayTibokAkl.git
    ```

- Move it to the Arduino libraries folder:
    ```sh
    mv LundayTibokAkl ~/Documents/Arduino/libraries/
    ```

🔗 Detailed guide: [Installation Instructions](INSTALLATION.md)  

## 4. Example Usage

```cpp
#include <LundayTibok.h>

LundayTibok led(13, NORMAL);

void setup() {
    led.begin();
}

void loop() {
    led.update();
}
```

🔗 More examples [here](../examples/).

## 5. Documentation

📖 **API Reference:** See available functions [here](API_REFERENCE.md)  
💡 **Concepts and Design:** Read the details [here](CONCEPTS.md)  
📌 **Changelog:** Version history [here](CHANGELOG.md)  

## 6. Support and License
`LundayTibokAkl` is open-source under the [MIT License](LICENSE).  
📬 **Need help?** Open an issue [here](https://github.com/LakanHaraya/LundayTibokAkl/issues).