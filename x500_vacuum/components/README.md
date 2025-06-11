# ESPHome External Component for XY/X500 Robot Vacuum

This repository provides an ESPHome external component to integrate an XY/X500 robot vacuum (or compatible models) via UART.

## Features

- Status and error evaluation via UART
- Control (Start, Stop, Spot, Edge, Docking, manual driving commands)
- Battery level display
- Compatible with ESP8266 (esp12e recommended)

## Installation

1. Place this repository as a submodule or directly into your ESPHome `external_components` folder (e.g., `external_components/x500_vacuum/`).
2. In your `esphome:` YAML configuration:

```yaml
external_components:
  - source: github://<YOUR-GITHUB-USERNAME>/x500_vacuum
    refresh: 0s

x500_vacuum:
  uart_id: uart_bus
  rawstate_id: rawstate
  vacstate_id: vacstate
  errorstate_id: errorstate
  batdata_id: batdata
```

3. Additionally, define the required UART and WiFi components in your YAML.
4. The buttons and sensors will be created automatically.

## Configuration Options

| Option        | Type | Default      | Description                                 |
|---------------|------|-------------|---------------------------------------------|
| uart_id       | ID   | **Required**| UART component (e.g., `uart_bus`)           |
| rawstate_id   | ID   | *optional*  | Text sensor for raw status                  |
| vacstate_id   | ID   | *optional*  | Text sensor for vacuum status               |
| errorstate_id | ID   | *optional*  | Text sensor for error messages              |
| batdata_id    | ID   | *optional*  | Sensor for battery level                    |

## Notes

- Password and SSID configuration is handled as usual via secrets.
- The states and buttons are made available as ESPHome entities.

## Files

- `x500_vacuum.h` – Main component
- `x500_vacuum.cpp` – UART logic implementation
- `button_x500_vacuum.h/cpp` – Button implementation
- `sensor_x500_battery.h/cpp` – Battery sensor
- `text_sensor_x500_state.h/cpp` – Status/error sensors
