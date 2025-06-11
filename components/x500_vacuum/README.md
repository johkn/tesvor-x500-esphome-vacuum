# ESPHome External Component für XY/X500 Staubsaugerroboter

Dieses Repository enthält eine ESPHome External Component zur Integration eines XY/X500 Staubsaugerroboters (bzw. kompatibler Modelle) via UART.

## Features

- Status- und Fehlerauswertung über UART
- Steuerung (Start, Stop, Spot, Edge, Docking, manuelle Fahrbefehle)
- Batteriestandsanzeige
- Kompatibel mit ESP8266 (esp12e empfohlen)

## Installation

1. Dieses Repository als Submodul oder direkt in deinen ESPHome `external_components` Ordner legen (z. B. `external_components/x500_vacuum/`).
2. In deiner `esphome:` YAML-Konfiguration:

```yaml
external_components:
  - source: github://<DEIN-GITHUB-USERNAME>/x500_vacuum
    refresh: 0s

x500_vacuum:
  uart_id: uart_bus
  rawstate_id: rawstate
  vacstate_id: vacstate
  errorstate_id: errorstate
  batdata_id: batdata
```

3. Definiere zusätzlich die benötigten UART- und WiFi-Komponenten in deiner YAML.
4. Die Buttons und Sensoren werden automatisch erzeugt.

## Konfigurationsoptionen

| Option         | Typ    | Standard    | Beschreibung                      |
|----------------|--------|-------------|-----------------------------------|
| uart_id        | ID     | **Erforderlich** | UART-Komponente (z.B. `uart_bus`)|
| rawstate_id    | ID     | *optional*  | TextSensor für Rohstatus          |
| vacstate_id    | ID     | *optional*  | TextSensor für Staubsaugerstatus  |
| errorstate_id  | ID     | *optional*  | TextSensor für Fehlermeldungen    |
| batdata_id     | ID     | *optional*  | Sensor für Batteriestand          |

## Hinweise

- Die Passwort- und SSID-Konfiguration erfolgt wie gewohnt über Secrets.
- Die States und Buttons werden als ESPHome-Entities verfügbar gemacht.

## Dateien

- `x500_vacuum.h` – Hauptkomponente
- `x500_vacuum.cpp` – Implementierung der UART-Logik
- `button_x500_vacuum.h/cpp` – Button-Implementierung
- `sensor_x500_battery.h/cpp` – Batteriesensor
- `text_sensor_x500_state.h/cpp` – Status-/Fehlersensoren