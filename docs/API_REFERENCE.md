# 📓 API Reference: `LundayTibokAkl` v2.1.0

## Talaan ng API

| Function | Deskripsiyon |
| :-- | :-- |
| [`LundayTibok(int ledPin, BlinkMode mode, bool usePWM = false)`](#lundaytibokint-ledpin-blinkmode-mode-bool-usepwm--false) | Constructor: Nagsisimula ng isang objek ng indikador. |
| [`void begin(bool activeHigh = true)`](#void-beginbool-activehigh--true) | Sinisimulan ang indikador na may kaayusang active `HIGH` o `LOW`. |
| [`void update()`](#void-update) | Isinasapanahon ang estado ng indikador batay sa kasalukuyang moda. |
| [`void setBlinkMode(BlinkMode mode)`](#void-setblinkmodeblinkmode-mode) | Itinatakda ang bagong moda ng pagtibok. |
| [`void setPWM(int brightness)`](#void-setpwmint-brightness) | Itinatakda ang tingkad kung gumagamit ng PWM. |
| [`void disable()`](#void-disable) | Pinipindi ang indikador at hinahadlangan ang pagtibok. |
| [`void enable()`](#void-enable) | Ibinabalik ang karaniwang pagtibok ng indikador. |
| [`const char* getBlinkMode() const`](#const-char-getblinkmode-const) | Ibinabalik ang kasalukuyang moda ng pagtibok bilang string. |

## Mga Detalye ng API

### `LundayTibok(int ledPin, BlinkMode mode, bool usePWM = false)`

#### Deskripsiyon:

Constructor function na lumilikha ng LundayTibok object para sa pamamahala ng LED indicator.

#### Mga Parameter:

- `ledPin` (*int*) - GPIO pin kung saan nakakabit ang indikador.

- `mode` (*BlinkMode*) - Paunang moda ng pagtibok ng indikador.

- `usePWM` (*bool*, default: `false`) - Kung gagamitin ang PWM para sa pagkontrol ng halagang analog, tulad ng tingkad o lakas ng paghugong.

#### Halimbawa:

``` 
LundayTibok led(13, NORMAL);
```
---

### `void begin(bool activeHigh = true)`

#### Deskripsiyon:

Sinisimulan ang indikador sa kaayusang HIGH o LOW.

#### Mga Parameter:

- `activeHigh` (*bool*, default: `true`) - Kung ang indikador ay nakasindi sa HIGH (`true`) o LOW (`false`).

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

### `void setBlinkMode(BlinkMode mode)`

#### Deskripsiyon:

Binabago ang kasalukuyang blink mode ng LED.

#### Mga Parameter:

- `mode` (*BlinkMode*) - Ang bagong moda ng pagtibok (`EMERGENCY`, `CRITICAL`, `WARNING`, `NORMAL`, `DISABLED`).

#### Halimbawa:

``` 
led.setBlinkMode(WARNING);
```
---

### `void setPWM(int brightness)`

#### Deskripsiyon:

Itinatakda ang tingkad ng indikador kung ito ay nasa moda ng PWM.

#### Mga Parameter:

- `brightness` (*int*) - Halaga mula `0` (madilim) hanggang `255` (pinakamatingkad).

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

### `const char* getBlinkMode() const`

#### Deskripsiyon:

Ibinabalik ang kasalukuyang moda n g pagtibok bilang isang string.

#### Halimbawa:

``` 
Serial.println(led.getBlinkMode());
```
---






