# 📓 API Reference: `LundayTibokAkl` v2.1.2

## Talaan ng API

| Function | Deskripsiyon |
| :-- | :-- |
| [`LundayTibok(int indicatorPin, HeartbeatLevel level, bool usePWM = false)`](#lundaytibokint-indicatorpin-heartbeatlevel-level-bool-usepwm--false) | Konstruktor: Nagsisimula ng isang objek ng indikador. |
| [`void begin(bool activeHigh = true)`](#void-beginbool-activehigh--true) | Sinisimulan ang indikador na may kaayusang active `HIGH` o `LOW`. |
| [`void update()`](#void-update) | Isinasapanahon ang estado ng indikador batay sa kasalukuyang antas. |
| [`void setHeartbeatLevel(HeartbeatLevel level)`](#void-setheartbeatlevelheartbeatlevel-level) | Itinatakda ang bagong antas ng pagtibok. |
| [`void setPWM(int intensity)`](#void-setpwmint-intensity) | Itinatakda ang intensidad kung gumagamit ng PWM. |
| [`void disable()`](#void-disable) | Pinipindi ang indikador at hinahadlangan ang pagtibok. |
| [`void enable()`](#void-enable) | Ibinabalik ang pangkaraniwang pagtibok ng indikador. |
| [`const char* getHeartbeatLevel() const`](#const-char-getheartbeatlevel-const) | Ibinabalik ang kasalukuyang antas ng pagtibok bilang string. |

## Mga Detalye ng API

### `LundayTibok(int indicatorPin, HeartbeatLevel level, bool usePWM = false)`

#### Deskripsiyon:

Funsiyong konstruktor na lumilikha ng objek ng LundayTibok para sa pamamahala ng indikador.

#### Mga Parameter:

- `indicatorPin` (*int*) - GPIO pin kung saan nakakabit ang indikador.

- `level` (*HeartbeatLevel*) - Paunang antas ng pagtibok ng indikador (`EMERGENCY`, `CRITICAL`, `WARNING`, `NORMAL`, `DISABLED`).

- `usePWM` (*bool*, pinatakda: `false`) - Kung gagamitin ang PWM para sa pagkontrol ng halagang analog, halimbawa, intensidad tulad ng tingkad ng LED o lakas ng pagtunog.

#### Halimbawa:

``` 
LundayTibok led(13, NORMAL);
```
---

### `void begin(bool activeHigh = true)`

#### Deskripsiyon:

Sinisimulan ang indikador sa kaayusang HIGH o LOW.

#### Mga Parameter:

- `activeHigh` (*bool*, pinatakda: `true`) - Tumutukoy kung ang indikador ay nakasindi sa HIGH (`true`) o LOW (`false`).

#### Halimbawa:

``` 
led.begin();
```
---

### `void update()`

#### Deskripsiyon:

Dapat itong tawagin sa loob ng `loop()` upang mapanatili ang tamang pattern ng pagtibok ng indikador.

#### Halimbawa:

``` 
void loop() {
    led.update();
}
```
---

### `void setHeartbeatLevel(HeartbeatLevel level)`

#### Deskripsiyon:

Binabago ang kasalukuyang antas ng pagtibok ng indikador.

#### Mga Parameter:

- `level` (*HeartbeatLevel*) - Ang bagong antas ng pagtibok (`EMERGENCY`, `CRITICAL`, `WARNING`, `NORMAL`, `DISABLED`).

#### Halimbawa:

``` 
led.setHeartbeatLevel(WARNING);
```
---

### `void setPWM(int intensity)`

#### Deskripsiyon:

Itinatakda ang intensidad ng indikador kung ito ay nasa moda ng PWM.

#### Mga Parameter:

- `intensity` (*int*) - Halaga mula `0` (pindi) hanggang `255` (pinakamatindi).

#### Halimbawa:

``` 
led.setPWM(128);
```
---

### `void disable()`

#### Deskripsiyon:

Pinipindi (off) ang indikador at hinahadlangan ang anumang pattern ng pagtibok.

#### Halimbawa:

``` 
led.disable();
```
---

### `void enable()`

#### Deskripsiyon:

Ibinabalik ang karaniwang asal ng pagtibok ng indikador.

#### Halimbawa:

``` 
led.enable();
```
---

### `const char* getHeartbeatLevel() const`

#### Deskripsiyon:

Ibinabalik ang kasalukuyang antas ng pagtibok bilang isang string.

#### Halimbawa:

``` 
Serial.println(led.getHeartbeatLevel());
```
---






