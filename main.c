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
  // Read sensor data
  sensorValue = analogRead(A2);

  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  Temp_Fahrenheit = dht.readTemperature(true);

  if (isnan(Humidity) || isnan(Temperature) || isnan(Temp_Fahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Control LEDs based on sensor value (air quality)
  if (sensorValue <= 40) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if (sensorValue <= 60) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(200);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(200);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(200);
  }
}
