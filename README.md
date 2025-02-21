# 🏭 AQI-Sense: Your Personal Air Quality Guardian 🌍💨  

🚀 **Breathe Smart, Stay Safe!**  
AQI-Sense is an intelligent **Air Quality Monitoring System** that keeps track of your environment in real-time. Whether it's pollution, temperature spikes, or humidity fluctuations, this system ensures you're always informed!  

⚡ Powered by **Arduino + DHT22 + OLED + Sensors + LEDs + Buzzer**, this project is your **mini-environmental watchdog**.  

---

## 🌟 Features  
✅ **Real-time Air Quality Monitoring** – Detects pollution levels in **PPM (Parts Per Million)**  
✅ **OLED Display** – Visual feedback for **Air Quality, Temperature, and Humidity**  
✅ **LED Alerts** – Indicates air quality status using **color-coded LEDs**  
✅ **Buzzer Alarm** – Notifies when **temperature exceeds safe levels**  
✅ **Engaging UI** – Fancy **"Booting Up"** animations to simulate system startup  
✅ **Automatic Warnings** – If pollution rises, the system warns with flashing LEDs  

---

## 🛠 Tech & Components Used  
📌 **Microcontroller:** Arduino  
📌 **Sensors:** DHT22 (Temperature & Humidity)  
📌 **OLED Display:** SSD1306 (128x64)  
📌 **Air Quality Sensor:** MQ-series or similar  
📌 **Buzzer:** Piezoelectric for alerts  
📌 **LED Indicators:** Red (Bad Air), Yellow (Moderate), Green (Good)  

---

## 🚀 How It Works  
### 1️⃣ System Boot-up 🚦  
🔹 OLED displays **"Booting Up..."** for 3 seconds to simulate initialization.  

### 2️⃣ Air Quality Analysis 💨  
🔹 **Air quality sensor** reads pollution levels and displays:  
   - **Good Air (PPM ≤ 40)** 🟢  
   - **Moderate Air (40 < PPM ≤ 60)** 🟡  
   - **Poor Air (PPM > 60)** 🔴 (LED blinks and warns)  

### 3️⃣ Temperature & Humidity Monitoring 🌡  
🔹 The **DHT22 sensor** measures temperature and humidity in real-time.  
🔹 If **Temperature > 30°C**, the buzzer sounds a **high-temperature alert**! 🚨  

---

## 🔧 Setup Instructions  
### 📌 Step 1: Wiring the Components  
🔹 Connect **DHT22** to Arduino:  
   - **VCC → 5V**, **GND → GND**, **Data → Pin 2**  

🔹 Connect **OLED Display** (SSD1306 I2C):  
   - **SDA → A4**, **SCL → A5**  

🔹 Connect **Air Quality Sensor** (MQ-Series or similar):  
   - **Analog output → A2**  

🔹 Connect **Buzzer & LEDs** to respective digital pins.  

---

### 📌 Step 2: Upload the Code  
1️⃣ Install the required libraries:  
   ```bash
   Arduino IDE → Sketch → Include Library → Manage Libraries
```
Install:

- DHT.h
- Adafruit GFX
- Adafruit SSD1306
  
2️⃣ Open the Arduino IDE and upload the provided AQI-Sense.ino file.

3️⃣ Power on the Arduino, and watch your environmental guardian come to life! 🚀
