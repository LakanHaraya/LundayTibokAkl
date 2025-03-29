 
# Dokumentasyon ng `LundayTibokAkl` 

📜 *Malapamantayan:* **LNDH-0051** *(Aktibo)*  
📅 *Petsa ng Paglalathala:* **27 Marso 2025**  
🔢 *Bersiyon:* **2.1.0** *(Matatag)*   
🛠️ *Huling Rebisyon:* **29 Marso 2025**  
👨‍💻 *May-akda:* **Lakan Haraya Dima**  
📩 *Email:* lakanharaya@gmail.com  
🔗 *GitHub:* https://github.com/LakanHaraya    
📖 *Languages:*
🇵🇭 ***Filipino**** **(Up-to-date)** | 🇺🇸 [English](README_EN.md)  

## 1. Panimula 

Ang **`LundayTibokAkl`** ay isang malapamantayang aklatan para sa pamamahala
ng mga tumitibok na indikador pang-istatus (hal., LED, buzzer, motor vibrations, atbp.)
gamit ang iba't ibang heartbeat modes batay sa alert patterns sa pamantayan ng IEC 60073:2002 (*emergency, critical, warning, at normal*).
Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* at maaaring gamitin
sa mga sistemang nangangailangan ng malinaw na indikasyon ng estado, maging ito man ay visual, auditory, o haptic.

## Talaan ng Nilalaman

1. [Panimula](#1-panimula)
2. [Mga Tampok](#2-mga-tampok)
3. [Paggamit](#3-paggamit)  
   3.1 [Instalasyon](#31-instalasyon)  
   3.2 [Halimbawa ng Paggamit](#32-halimbawa-ng-paggamit)  
     - [Simpleng Pagkislap ng LED](#simpleng-pagkislap-ng-led)  
     - [Pagpapatigil at Pagpapagana ng LED](#pagpapatigil-at-pagpapagana-ng-led)  
4. [Estruktura ng Folder](#4-estruktura-ng-folder)  
5. [Lisensiya](#5-lisensiya)  
6. [Suporta at Katanungan](#6-suporta-at-katanungan)  


## 2. Mga Tampok

- **Estandardisadong Pulse Modes:** EMERGENCY, CRITICAL, WARNING, NORMAL, at DISABLED
- **PWM Support:** Para sa pagkontrol sa intensidad ng pagtibok (hal., lakas ng liwanag ng LED)
- **Enable/Disabled Functionality:** Para sa epektibong pamamahala ng mga indikador.
- **Arduino-Compatible API:** Madaling gamitin sa microcontroller-based projects.

## 3. Paggamit

### 3.1. Instalasyon

I-clone o i-download ang repositoryo at idagdag ito sa iyong Arduino libraries folder:

```
Arduino/libraries/LundayTibokAkl
```

### 3.2 Halimbawa ng Paggamit 

#### **Simpleng Pagkislap ng LED**

``` cpp
#include <LundayTibok.h>

LundayTibok led(13, NORMAL);

void setup() {
    led.begin();
}

void loop() {
    led.update();
}
```

#### **Pagpapatigil at Pagpapagana ng LED**

``` cpp
#include <LundayTibok.h>

LundayTibok led(13, WARNING);

void setup() {
    led.begin();
    delay(5000);
    led.disable(); // Ipindi ang LED pagkatapos ng 5 segundo
    delay(5000);
    led.enable(); // Ibalik ang pagkislap
}

void loop() {
    led.update();
}
```

Para sa higit pang mga halimbawa, magpunta sa `LundayTibokAkl/examples/`

## 4. Estruktura ng Folder

``` txt
LundayTibokAkl/
├── examples/             # Mga halimbawa ng code
├── src/                  # Source code ng library
|   ├── LundayTibok.h         # Declaration File
|   ├── LundayTibok.cpp       # Implementation File
├── docs/                 # Dokumentasyon
|   ├── README.md             # Filipino
|   ├── README_EN.md          # English
├── library.properties    # Para sa Arduino Library Manager
```

## 5. Lisensiya

Ang `LundayTibokAkl` ay open-source sa ilalim ng **MIT License**. Malaya itong gamitin at baguhin para sa iyong proyekto.

## 6. Suporta at Katanungan

Kung may katanungan o mungkahi, maaaring magbukas ng isang issue o magpadala ng pull request sa opisyal na repositoryo.
