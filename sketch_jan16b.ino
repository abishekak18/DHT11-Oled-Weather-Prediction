#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 7
#define DHTTYPE DHT11

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/* ======== FAN ICON (12x12) - 4 FRAMES ROTATION ======== */
const unsigned char fan1[] PROGMEM = {
  0x10,0x38,0x7C,0x10,0x10,0x10,0x7C,0x38,0x10
};
const unsigned char fan2[] PROGMEM = {
  0x10,0x10,0x38,0x7C,0x10,0x7C,0x38,0x10,0x10
};
const unsigned char fan3[] PROGMEM = {
  0x10,0x38,0x7C,0x10,0x10,0x10,0x7C,0x38,0x10
};
const unsigned char fan4[] PROGMEM = {
  0x10,0x10,0x38,0x7C,0x10,0x7C,0x38,0x10,0x10
};

/* ======== PULSING DROP (8x12) ======== */
const unsigned char dropPulse1[] PROGMEM = {
  0x10,0x38,0x7C,0x7C,0x7C,0x38,0x10
};
const unsigned char dropPulse2[] PROGMEM = {
  0x18,0x3C,0x7E,0x7E,0x7E,0x3C,0x18
};

int fanFrame = 0;
int pulseFrame = 0;
unsigned long lastAnim = 0;

void setup() {
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  display.clearDisplay();

  /* ===== HEADER ===== */
  display.setTextSize(1);
  display.setCursor(25, 0);
  display.print("TEAM A1 WEATHER");

  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);

  /* ===== ANIMATION TIMING ===== */
  if (millis() - lastAnim > 180) {
    fanFrame = (fanFrame + 1) % 4;
    pulseFrame = (pulseFrame + 1) % 2;
    lastAnim = millis();
  }

  /* ===== FAN ANIMATION (TEMP) ===== */
  switch(fanFrame) {
    case 0: display.drawBitmap(5, 20, fan1, 12, 12, 1); break;
    case 1: display.drawBitmap(5, 20, fan2, 12, 12, 1); break;
    case 2: display.drawBitmap(5, 20, fan3, 12, 12, 1); break;
    case 3: display.drawBitmap(5, 20, fan4, 12, 12, 1); break;
  }

  /* ===== TEMP TEXT ===== */
  display.setCursor(25, 22);
  display.setTextSize(1);
  display.print("Temp: ");
  if (!isnan(t)) {
    display.print(t, 1);
    display.print(" C");
  } else display.print("--C");

  /* ===== PULSE DROP (HUMIDITY) ===== */
  if (pulseFrame == 0)
    display.drawBitmap(5, 42, dropPulse1, 8, 12, 1);
  else
    display.drawBitmap(5, 42, dropPulse2, 8, 12, 1);

  /* ===== HUMIDITY TEXT ===== */
  display.setCursor(25, 44);
  display.print("Hum : ");
  if (!isnan(h)) {
    display.print(h, 0);
    display.print("%");
  } else display.print("--%");

  display.display();
}
