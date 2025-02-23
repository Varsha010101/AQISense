#include <Wire.h>
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define DHTTYPE DHT22
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
unsigned long delayTime;
uint8_t DHTPin = 2;
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;
float Temp_Fahrenheit;

int sensorValue;


void   setup()
{
  Serial.begin(115200);
  pinMode(DHTPin, INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(11,OUTPUT);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
  display.setTextSize(1.75);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("       AIR");
  display.setCursor(0, 17);
  display.print("   QUALITY");
  display.setCursor(0, 34);
  display.print("MONITORING");
  display.setCursor(0, 51);
  display.print("    SYSTEM");
  display.display();

delay(4000);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 18);
  display.print("Booting");
  display.setCursor(0, 38);
  display.print("Up ....");
  display.display();

  delay(3000);


}
void loop() {
  // Continue from the previous commit...

  // Update display with air quality, temperature, and humidity
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("Air");
  display.setCursor(0, 17);
  display.print("Quality : ");
  display.setTextSize(3);
  display.setCursor(0, 43);
  display.print(sensorValue, DEC);
  display.print(" ");
  display.setCursor(50, 50);
  display.setTextSize(2);
  display.print("PPM");
  display.display();
  delay(1600);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0, 12);
  display.print(Temperature);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity : ");
  display.setTextSize(2);
  display.setCursor(0, 47);
  display.print(Humidity);
  display.print(" %");
  display.display();
  delay(1600);

  // Check air quality status and update display
  if (sensorValue <= 40) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 10);
    display.print("AIR");
    display.setCursor(0, 28);
    display.print("QUALITY");
    display.setCursor(0, 46);
    display.print("IS GOOD");
    display.display();
    delay(1100);
  } else {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 10);
    display.print("AIR");
    display.setCursor(0, 28);
    display.print("QUALITY");
    display.setCursor(0, 46);
    display.print("IS BAD");
    display.display();
    delay(1100);
  }
}
