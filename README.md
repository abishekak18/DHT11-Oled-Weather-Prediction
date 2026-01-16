# Mini Weather Widget (DHT11 + OLED)

A compact weather widget built using Arduino, DHT11 sensor, and an SSD1306 OLED display.  
Shows **temperature** and **humidity** with a smooth **fan + droplet animation** for a clean visual look.

---

## 📸 Preview

![Preview 1](./preview1.jpg)


---

## ✨ Features

- Live Temperature & Humidity reading
- DHT11 sensor support
- SSD1306 OLED (128x64)
- Animated **fan** for temperature
- Pulsing **droplet** for humidity
- Minimal UI layout
- Low power & small footprint
- Great for desk or embedded use

---

## 🧰 Hardware Used

- Arduino Uno
- DHT11 Temperature & Humidity Sensor
- Monochrome OLED (SSD1306 128x64)
- Jumper wires
- Breadboard or PCB

---

## 📦 Libraries Required

Make sure you install:

Adafruit GFX Library

Adafruit SSD1306

DHT sensor library

Adafruit Unified Sensor


---

## 📝 Wiring Connections

| Component | Arduino |
|----------|---------|
| DHT11 VCC | 5V |
| DHT11 DATA | D7 |
| DHT11 GND | GND |
| OLED SDA | A4 |
| OLED SCL | A5 |
| OLED VCC | 5V |
| OLED GND | GND |

*(Change pins if using ESP32/ESP8266)*

---

## 💻 Code

Source code included 

Main animation elements:
- **fan** → rotating effect
- **droplet** → pulsing effect

---
