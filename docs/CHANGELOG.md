# CHANGELOG

## LundayTibokAkl v2.1.2 - Inilabas noong 2025-04-02

### 🔄 Mga Pagbabago

- Pangkalahatang pagsasaayos ng dokumentasyon
- Pinalitan ang file extensions ng mga `examples/` magmula sa `*.cpp` patungo sa `*.ino` para sa wastong pagbasa sa Arduino IDE.

---

## LundayTibokAkl v2.1.1 - Inilabas noong 2025-04-01

### 🔥 Bagong Tampok
- Dinagdagan ng isang simpleng halimbawa `examples/HeartbeatTest.cpp`

### 🔄 Mga Pagbabago
- Pangkalahatang pagsasaayos ng dokumentasyon
- Inayos ang mga ginamit na terminolohiya para sa konsistensi, kabilang ang mga halimbawang kodigo.
- Pinalitan ang `setBlinkMode()` ng `setHeartbeatLevel()`.
- Pinalitan ang `getBlinkMode()` ng `getHeartbeatLevel()`.

---

## LundayTibokAkl v2.1.0 - Inilabas noong 2025-03-29

### 🔥 Bagong Tampok
- Hinahanda ang suporta para sa "heartbeat mode" upang gawing mas malawak ang paggamit sa LED, at buzzer.
- Sinusuportahan na ngayon ang mas maraming uri ng alert patterns batay sa IEC 60073:2002 standard.
- Mas pinadali ang paggamit ng `setBlinkMode()` function.

### 🐞 Mga Pag-aayos ng Lisap (Bug)
- Inayos ang isyu kung saan hindi tumitigil ang LED kapag ginamit ang `disable()`.
- Na-optimize ang update() function upang maiwasan ang hindi kinakailangang CPU usage.

### 🔄 Mga Pagbabago
- Inayos ang dokumentasyon sa README.md para sa bagong bersiyon at sa mas malinaw na paggamit.

### ⚠️ Mga Kilalang Isyu
- Hindi pa nasusubukan sa iba pang microcontroller at development boards. (Ayusin sa susunod na bersiyon)