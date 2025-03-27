# 📖 Dokumentasyon ng `LundayTibokAkl\` 

📖 Available Versions:  
🇵🇭 ***Filipino**** (Up-to-date) | 🇺🇸 [English](README_EN.md)  

📅 **Bersiyon:** 1.0.0 (27 Marso 2025)  
👨‍💻 **May-akda:** Lakan Haraya Dima  
📩 **Email:** lakanharaya@gmail.com  
🔗 **GitHub:** https://github.com/LakanHaraya  

## 🔍 Panimula

Ang `LundayTibokAkl\` at isang Arduino library na nagbibigay ng mekanismo para sa **epekto ng pagtibok ng LED** gamit ang dalawang **agwat** (*intervals*). May kakayahan itong suportahan ang **aktibong-mataas** at **aktibong-mababa** na kumpigurasyon ng LED.

Ginawa ang aklatang ito upang mabawasan ang paggamit ng `delay()` at matiyak ang mas episyenteng **pagkislap ng LED na di-humahadlang** (*non-blocking LED blinking*), na kapaki-pakinabang sa mga proyektong nangangailangan ng sabayang proseso (*multitasking*) sa loob ng *loop* ng Arduino.

# 📑 Talaan ng Nilalaman

- [📖 Dokumentasyon ng `LundayTibokAkl\`](#📖-dokumentasyon-ng-lundaytibokakl)
- [🔍 Panimula](#🔍-panimula)
- [🎯 Mga Tampok](#🎯-mga-tampok)
- [⚙️ Instalasyon](#⚙️-instalasyon)
  - [Manwal na Pag-instal](#manwal-na-pag-instal)
  - [Pag-instal mula sa GitHub](#pag-instal-mula-sa-github)
- [📌 Sanggunian ng API](#📌-sanggunian-ng-api)
  - [🔹 Paggawa ng Instansiya](#🔹-paggawa-ng-instansiya)
  - [🔹 Pag-inisyalisa ng LED Tibok](#🔹-pag-inisyalisa-ng-led-tibok)
  - [🔹 Pagsasapanahon ng LED Tibok](#🔹-pagsasapanahon-ng-led-tibok-dapat-tawagin-sa-loop)
  - [🔹 Mga Pangunahing Funsiyon](#🔹-mga-panguhang-funsiyon)
- [🛠 Halimbawa ng Paggamit](#🛠-halimbawa-ng-paggamit)
  - [🔸 Simpleng Gamit](#🔸-simpleng-gamit)
  - [🔸 Dinamikong Pagbabago ng Agwat](#🔸-dinamikong-pagbabago-ng-agwat)
- [📂 Estruktura ng Kaligpitan](#📂-estruktura-ng-kaligpitan)
- [🛑 Pagdadalisap at Pagsisipat](#🛑-pagdadalisap-at-pagsisipat)
- [📝 Lisensiya](#📝-lisensiya)
- [🔗 Talabaguhan](#🔗-talabaguhan)
  - [🆕 Bersiyon 1.0.0 (27 March 2025)](#🆕-bersiyon-100-27-march-2025)
- [📢 May Katanungan?](#📢-may-katanungan)
- [🎯 Kongklusyon](#🎯-kongklusyon)


## 🎯 Mga Tampok

✅ **Suportado ang Aktibong-Mataas at Aktibong-Mababa na Kumpigurasyon ng LED**   
✅ **Dalawang Agwat para sa Flexible na Pagtibok ng LED**  
✅ **Non-blocking LED Control gamit ang `millis()`**   
✅ **May Getter Methods para sa Real-Time Query ng Estado ng LED**   
✅ **Simpleng API para sa Madaling Integrasyon**

---
## ⚙️ Instalasyon

### Manwal na Pag-instal

 1. I-download ang repositoryo ng `LundayTibokAkl`.
 2. Ilagay ang folder sa loob ng `Arduino/libraries/`.
 3. Tiyakin na nasa loob ng `LundayTibokAkl/` ang mga sumusunod na kaligpit (file):
 - `LundayTibok.h`
 - `LundayTibok.cpp`
 - `library.properties`

**Pag-instal mula sa GitHub**

``` sh
git clone https://github.com/LakanHaraya/LundayTibokAkl.git
```

## 📌 Sanggunian ng API

### 🔹 Paggawa ng Instansiya

``` cpp
LundayTibok tibok(ledPin, interval1, interval2);
```

- `ledPin` (int) → Ang GPIO pin ng LED.
- `interval1` (unsigned long, default = 500) → Unang agwat ng tibok (sa milisegundo).
- `interval2` (unsigned long, default = 500) → Ikalawang agwat ng tibok (sa milisegundo).

### 🔹 Pag-inisyalisa ng LED Tibok

``` cpp
tibok.begin(activeHigh);
```
- `activeHigh` (bool, default = `true`) →   
  - `true` → Ang LED ay nakasindi (on) kapag **HIGH**
  - `false` → Ang LED ay nakasindi (on) sa **LOW**

### 🔹 Pagsasapanahon ng LED Tibok *(Dapat tawagin sa `loop()`)*

``` cpp
tibok.update(); // Isinasapanahon ang estado ng LED
```
Kapag tinawag ang `update()`, sinusuri ng library ang kasalukuyang oras (`*millis()*`) at inaalam kung kailan dapat baguhin ang estado ng LED.

**Taladaluyan**
``` txt
Lohika ng Pagtibok ng LED


              +---------------------------+
    --------> |      Simula ng Loop       |
    ^         +---------------------------+
    |                       |
    |                       v
    |       +-----------------------------+
    |       | Kunin ang kasalukuyang oras |
    |       |     gamit ang `millis()`    |
    |       +-----------------------------+
    |                       |
    |                       v
    |   +--------------------------------------------------------+
    |   |      Suriin kung oras na upang palitan ang estado      |
    |   | ((currentMillis - _lastToggleTime) >= currentInterval) |
    |   +--------------------------------------------------------+
    |                       |               |
    |               (Hindi) |               | (Oo)
    |                       v               |
    |   +------------------------------+    |
    |<--| Maghintay at bumalik sa loop |    |
        +------------------------------+    |
                                            |
                                            v
                +-------------------------------------+
                | Itakda ang huling oras ng pagbabago |
                +-------------------------------------+
                            |
                            v
              +---------------------------+
              | Palitan ang Estado ng LED |
              +---------------------------+
                            |
                            v
        +-----------------------------------------------------+
        |               Isapanahon ang LED pin                |
        | (MATAAS/MABABA depende sa kaayusan ng `activeHigh`) |
        +-----------------------------------------------------+
                            |
                            v
                +----------------------+
                |  Wakas ng Iterasyon  |
                +----------------------+
                            |
                            v
                +----------------------+
                |   Ulitin ang Loop    |
                +----------------------+
```

### 🔹 Mga Panguhang Funsiyon
``` cpp
int pin = tibok.getLedPin();               // Kunin ang pin ng LED
unsigned long i1 = tibok.getInterval1();   // Kunin ang unang agwat
unsigned long i2 = tibok.getInterval2();   // Kunin ang ikalawang agwat
bool isHigh = tibok.isActiveHigh();        // Alamin kung aktibong-mataas o aktibong-mababa
bool isOn = tibok.isLedOn();               // Alamin kung nakasindi ang LED
```

## 🛠 Halimbawa ng Paggamit

### 🔸 Simpleng Gamit

``` cpp
#include <LundayTibok.h>

LundayTibok tibok(13, 500, 300); // LED sa pin 13, 500ms at 300ms na agwat

void setup() {
    tibok.begin(true); // Kumpigurasyong aktibong mataas
}

void loop() {
    tibok.update(); // Patulot na pagtibok ng LED
}
```

### 🔸 Dinamikong Pagbabago ng Agwat

``` cpp
#include <LundayTibok.h>

LundayTibok tibok(13, 1000, 200);

void setup() {
    tibok.begin(true);
}

void loop() {
    tibok.update();
    
    if (millis() > 10000) { // Pagkatapos ng 10 segundo, baguhin ang agwat
        tibok = LundayTibok(13, 200, 1000);
        tibok.begin(true);
    }
}
```

## 📂 Estruktura ng Kaligpitan

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

## 🛑 Pagdadalisap at Pagsisipat

| Isyu | Posibleng Sanhi | Solusyon |
| :-- | :-- | :-- |
| **Walang Tibok ang LED** | *Mali ang LED wiring (walang resistor?)* | Tiyaking tama ang koneksiyon ng kawad at may tamang resistor panlimita ng amperahe (220Ω ~ 1kΩ). |
| **Masyadong mabilis/mabagal ang tibok** | *Maling halaga ng agwat* | Tiyaking tama ang `interval1` at `interval2` na ibinigay sa konstruktor. |
| **Hindi sumasabay ang LED sa ibang bahagi ng code** | *Ginagamit ang `delay()` sa ibang bahagi ng code* | Iwasan ang `delay()`, gamitin ang `millis()` para sa pagtitiyempo. | 

## 📝 Lisensiya

Ang `LundayTibokAkl` ay open-source software sa ilalim ng MIT License. Malaya itong gamitin, baguhin, at ipamahagi.

## 🔗 Talabaguhan

### 🆕 Bersiyon 1.0.0 (27 March 2025)

✅ Unang labas ng aklatan na may pangunahing kakayahan.  
✅ Suporta para sa aktibong-mataas at aktibong-mababa na kumpigurasyon ng LED  
✅ Dalawang agwat para sa pagtibok ng LED  
✅ Mga panguhang funsiyon (*getter functions*) para sa mas madaling pagdadalisap  

## 📢 May Katanungan?

Kung may mg katanungan, suhestiyon, o nais na baguhin sa aklatan, mangyaring makipag-ugnayan sa:

📩 **Email:** lakanharaya@gmail.com  
🔗 **GitHub:** https://github.com/LakanHaraya

## 🎯 Kongklusyon

Ang `LundayTibokAkl` ay isang mahusay na Arduino library na naglalayong gawing mas madali at episyente ang **mga epektong pagtibok ng LED** gamit ang non-blocking approach.

Kung nais mong mag-ambag o magbigay ng suhestiyon, **bukás kami sa inyong mga ideya!** 🚀

