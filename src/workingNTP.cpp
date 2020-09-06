// #include <WiFi.h>
// #include "time.h"

// const char* ssid     = "z";
// const char* password = "packard1337!";

// const char* ntpServer = "pool.ntp.org";
// const long  gmtOffset_sec = 3600;
// const int   daylightOffset_sec = 3600;


// void printLocalTime(){
//   struct tm timeinfo;
//   if(!getLocalTime(&timeinfo)){
//     Serial.println("Failed to obtain time");
//     return;
//   }
//   Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
//   Serial.print("Day of week: ");
//   Serial.println(&timeinfo, "%A");
//   Serial.print("Month: ");
//   Serial.println(&timeinfo, "%B");
//   Serial.print("Day of Month: ");
//   Serial.println(&timeinfo, "%d");
//   Serial.print("Year: ");
//   Serial.println(&timeinfo, "%Y");
//   Serial.print("Hour: ");
//   Serial.println(&timeinfo, "%H");
//   Serial.print("Hour (12 hour format): ");
//   Serial.println(&timeinfo, "%I");
//   Serial.print("Minute: ");
//   Serial.println(&timeinfo, "%M");
//   Serial.print("Second: ");
//   Serial.println(&timeinfo, "%S");

//   Serial.println("Time variables");
//   char timeHour[3];
//   strftime(timeHour,3, "%H", &timeinfo);
//   Serial.println(timeHour);
//   char timeWeekDay[10];
//   strftime(timeWeekDay,10, "%A", &timeinfo);
//   Serial.println(timeWeekDay);
//   Serial.println();
// }

// void setup(){
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected.");
  
//   // Init and get the time
//   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//   printLocalTime();

//   //disconnect WiFi as it's no longer needed
//   WiFi.disconnect(true);
//   WiFi.mode(WIFI_OFF);
// }

// void loop(){
//   delay(1000);
//   printLocalTime();
// }











// #include <Arduino.h>
// #include <Wire.h>

// #include <Adafruit_GFX.h>    // Core graphics library
// #include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
// #include <SPI.h>

// const uint8_t soil[6]{34, 35, 32, 33, 25, 26};
// const uint8_t valve[6]{27, 14, 12, 13, 19, 5};

// #include <TimeLib.h>
// #include "WifiConfig.h"
// #ifndef WIFI_CONFIG_H
// #error Please create WifiConfig.h
// #endif // !WIFI_CONFIG_H
// #include <NtpClientLib.h>
// #include <WiFi.h>

// #define ONBOARDLED 5 // Built in LED on ESP-12/ESP-07
// #define SHOW_TIME_PERIOD 5000
// #define NTP_TIMEOUT 1500

// int8_t timeZone = 1;
// int8_t minutesTimeZone = 0;
// const PROGMEM char *ntpServer = "pool.ntp.org";
// bool wifiFirstConnected = false;

// void setup(void)
// {
//   Serial.begin(115200);
//   delay(100);
//   Serial.println("Startup...");

//   Serial.println("Startup: pin mode...");
//   for (uint8_t i = 0; i < sizeof(soil) / sizeof(soil[0]); i++)
//   {
//     pinMode(soil[i], INPUT);
//   }
//   for (uint8_t i = 0; i < sizeof(valve) / sizeof(valve[0]); i++)
//   {
//     pinMode(valve[i], OUTPUT);
//     digitalWrite(valve[i], true);
//   }

//   Serial.println("Startup: done.");
// }

