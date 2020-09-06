// #include <Arduino.h>
// #include <U8g2lib.h>
// #include <Wire.h>

// #define SENSOR_PIN 34
// #define OUTPUT_PIN 18
// #define TARGET_PERCENTAGE 40
// #define SENSOR_RAW_DRY 3395
// #define SENSOR_RAW_WET 1440
// #define WATERING_DURATION_MS 20000
// #define WATERING_DEAD_TIME_MS 1000 * 60 * 60 * 1 // Stunden
// // #define WATERING_DEAD_TIME_MS 1000 * 60 * 1 // Minuten

// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// void setup(void)
// {
//   Serial.begin(115200);
//   delay(100);
//   Serial.println("Startup...");

//   u8g2.begin();

//   pinMode(OUTPUT_PIN, OUTPUT);
//   digitalWrite(OUTPUT_PIN, true);
// }

// unsigned long millisLastWatering = 0;
// int wateringCount = 0;
// double rawValueSmoothed = 0.0;

// void loop(void)
// {
//   unsigned long currentMillis = millis();

//   int rawValue;
//   for (int i = 0; i < 10; i++)
//   {
//     rawValue = analogRead(SENSOR_PIN);

//     if (rawValueSmoothed == 0)
//       rawValueSmoothed = rawValue;

//     double factor = 0.1;
//     rawValueSmoothed = rawValueSmoothed * (1.0 - factor) + rawValue * factor;

//     delay(50);
//   }

//   double moisturePercentage = map(rawValueSmoothed, SENSOR_RAW_DRY, SENSOR_RAW_WET, 0, 10000) / 100.0;

//   u8g2.clearBuffer();
//   u8g2.setFont(u8g2_font_ncenB08_tr);

//   Serial.print(rawValue);
//   Serial.print("; \t");
//   u8g2.setCursor(0, 10);
//   u8g2.print("Raw: ");
//   u8g2.print(rawValue);

//   Serial.print(rawValueSmoothed);
//   Serial.print("; \t");
//   u8g2.setCursor(0, 20);
//   u8g2.print("RawS: ");
//   u8g2.print(rawValueSmoothed);

//   Serial.print(moisturePercentage);
//   Serial.print("%; \t");
//   u8g2.setCursor(0, 30);
//   u8g2.print("Feuchte: ");
//   u8g2.print(moisturePercentage);
//   u8g2.print(" %");

//   Serial.print(wateringCount);
//   Serial.print("; \t");
//   u8g2.setCursor(0, 40);
//   u8g2.print("WC: ");
//   u8g2.print(wateringCount);

//   float minutesSinceWatering = (currentMillis - millisLastWatering) / 1000.0 / 60.0;
//   Serial.print(minutesSinceWatering);
//   Serial.print("; \t");
//   u8g2.setCursor(0, 50);
//   u8g2.print("LW (m): ");
//   u8g2.print(minutesSinceWatering, 1);

//   float uptime = currentMillis / 1000.0 / 60.0 / 60.0;
//   Serial.print(uptime);
//   Serial.print("; \t");
//   u8g2.setCursor(0, 60);
//   u8g2.print("Uptime (h): ");
//   u8g2.print(uptime, 2);

//   Serial.println();
//   u8g2.sendBuffer();

//   if (currentMillis - millisLastWatering >= WATERING_DEAD_TIME_MS)
//   {
//     if (moisturePercentage < TARGET_PERCENTAGE)
//     {
//       Serial.print("Watering... ");
//       wateringCount++;
//       digitalWrite(OUTPUT_PIN, false);
//       delay(WATERING_DURATION_MS);
//       digitalWrite(OUTPUT_PIN, true);
//       Serial.println("Done.");

//       millisLastWatering = currentMillis;
//     }
//   }
//   delay(9000);
// }