# 📦 Instalasyon ng `LundayTibokAkl`

## Paraan ng Pag-instal

### 1️⃣ Manwal na Pag-instal

May tatlong paraan ng manwal na pag-instal ng **LundayTibokAkl**:

#### 1.1. **Pag-instal gamit ang `.zip` file sa Arduino IDE**

1. I-download ang pinakabagong labas ng **LundayTibokAkl** mula sa [GitHub Releases](https://github.com/LakanHaraya/LundayTibokAkl/releases).
2. Buksan ang **Arduino IDE**.
3. Pumunta sa **Sketch** → **Include Library** → **Add .ZIP Library...**.
4. Piliin ang na-download na **LundayTibokAkl.zip** at i-click ang **Open**.
5. I-restart ang **Arduino IDE** upang makilala ang library.

#### 1.2. **Manwal na Pag-instal (Extract and Move)**

1. I-download ang pinakabagong labas ng **LundayTibokAkl** mula sa [GitHub Releases](https://github.com/LakanHaraya/LundayTibokAkl/releases).
2. I-extract ang `.zip` file at ilagay ang folder sa:
    ```sh
    Documents/Arduino/libraries/
    ```
3. I-restart ang **Arduino IDE** upang makilala ang library.

### 2️⃣ Pag-instal gamit ang PlatformIO *(Para sa Advanced Users)*

1. Idagdag ito sa `platformio.ini` ng iyong proyekto:
    ```ini
    lib_deps = https://github.com/LakanHaraya/LundayTibokAkl.git
    ```
2. I-save at i-rebuild ang proyekto.

## ✅ Pagsusuri ng Tamang Instalasyon

Matapos ang pag-instal, subukan ang halimbawa sa pamamagitan ng pagbukas ng **Arduino IDE**:

1. Pumunta sa **File** → **Examples** → **LundayTibokAkl**.
2. Piliin ang **HeartbeatTest** at i-upload sa iyong board.

Kung gumagana nang tama, matagumpay mong na instal ang library! 🚀
