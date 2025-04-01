# 📦 Instalasyon ng `LundayTibokAkl`

## Paraan ng Pag-instal

### ~~1️⃣ Gamit ang Arduino Library Manager *(Inirerekomenda)*~~

<!-- 1. Buksan ang **Arduino IDE**.

2. Pumunta sa **Sketch** → **Include Library** → **Manage Libraries...**

3. Hanapin ang **LundayTibokAkl** sa search bar.

4. Piliin ang **LundayTibokAkl** at iklik ang **Install**. -->

### 2️⃣ Manwal na Pag-instal ~~*(Kung walang Library Manager)*~~

1. I-download ang pinakabagong labas ng **LundayTibokAkl** mula sa [GitHub Releases](https://github.com/LakanHaraya/LundayTibokAkl/releases).

2. I-extract ang `.zip` file at ilagay ang folder sa:
    ``` sh
    Documents/Arduino/libraries/
    ```
3. I-restart ang **Arduino IDE** upang makilala ang library.

### 3️⃣ Pag-instal gamit ang PlatformIO *(Para sa Advanced Users)*

1. Idagdag ito sa platformio.ini ng iyong proyekto:
    ``` 
    lib_deps = https://github.com/LakanHaraya/LundayTibokAkl.git
    ```
2. I-save at i-rebuild ang proyekto.

## ✅ Pagsusuri ng Tamang Instalasyon

Matapos ang pag-instal, subukan ang halimbawa sa pamamagitan ng pagbukas ng Arduino IDE:

1. Pumunta sa **File** → **Examples** → **LundayTibokAkl**.

2. Piliin ang "HeartbeatTest" at i-upload sa iyong board.

Kung gumagana nang tama, matagumpay mong nainstal ang library! 🚀