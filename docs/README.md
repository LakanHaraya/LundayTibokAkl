 
# 📖 `LundayTibokAkl` v2.1.1

📜 *Malapamantayan:* **LNDH-0051** *(Aktibo)*  
📅 *Petsa ng Paglalathala:* **27 Marso 2025**  
🔢 *Bersiyon:* **v2.1.1** *(Balangkas)*   
🛠️ *Huling Rebisyon:* **29 Marso 2025**  
👨‍💻 *May-akda:* **Lakan Haraya Dima**   
🌐 *Languages:*
🇵🇭 ***Filipino**** **(Up-to-date)** | 🇺🇸 [English](README_EN.md)  

## 1. Ano ang `LundayTibokAkl`?

Ang `LundayTibokAkl` ay isang aklatang Arduino-compatible na nagbibigay ng estandardisadong kontrol para sa pamamahala
ng mga tumitibok na indikador tulad ng LED, buzzer,vibration motors at iba pa.
Sinusunod nito ang pamantayang [IEC 60073:2002](https://webstore.iec.ch/en/publication/587) para sa iba't ibang antas ng alerto: ***EMERGENCY***, ***CRITICAL***, ***WARNING***, ***NORMAL***, at ***DISABLED***.

> Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* ngunit
> maaaring isama sa anumang proyekto ng mikrokontroler na
> nangangailangan ng malinaw na pidbak na natatanaw, nadidinig, o
> nahahaplos. 

## 2. Mga Pangunahing Tampok

✅ **Estandardisadong Moda ng Pagtibok:** *EMERGENCY*, *CRITICAL*, *WARNING*, *NORMAL*, at *DISABLED*  
✅ **PWM Support:** Para sa pagkontrol ng intensidad (hal., tingkad o lakas ng tunog)  
✅ **Kakayahang Magpagana/Di-magpagana:** Madaling paganahin o ihinto ang indikasyon  
✅ **Arduino-Compatible API:** Simple at madaling gamitin

## 3. Paano Mag-instal?

- I-clone ang repositoryo
    ```
    git clone https://github.com/LakanHaraya/LundayTibokAkl.git
    ```

- Ilagay sa Arduino libraries folder
    ``` 
    mv LundayTibokAkl ~/Documents/Arduino/libraries/
    ```

🔗 Mas detalyadong gabay: [Paano mag-instal?](INSTALLATION.md)

## 4. Halimbawa ng Paggamit

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

🔗 Marami pang halimbawa: [Mga Halimbawa](../examples/)

## 5. Dokumentasyon

📖 **API Reference:** Tingnan ang mga function [dito](API_REFERENCE.md)  
💡 **Konsepto at Disenyo:** Basahin ang detalye [dito](CONCEPTS.md)   
📌 **Changelog:** Mga pagbabago sa bawat bersiyon [dito](CHANGELOG.md)

## Suporta at Lisensiya

Ang `LundayTibokAkl` ay open-source sa ilalim ng [**MIT License**](LICENSE).   
📬 **May tanong?** Magbukas ng issue [dito](https://github.com/LakanHaraya/LundayTibokAkl/issues).