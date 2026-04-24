#include <Arduino.h>
#include <ESP32Time.h>
#include "time.h"
#include <WiFi.h>


//**********************************************************//
//* DECLARO DE FUN                                        **//
//**********************************************************//
void pedir_lahora(void);
void setup_rtc_ntp(void);

struct tm timeinfo;
ESP32Time rtc;


/// time
long unsigned int timestamp; // hora
const char *ntpServer = "south-america.pool.ntp.org";
const long gmtOffset_sec = -10800;
const int daylightOffset_sec = 0;

const char* ssid = "ORT-IoT";
const char* password = "OrtIOTnew22$2";

void setup() {
Serial.begin(115200);
  Serial.println("Connecting to Wi-Fi...");
 initWiFi();
setup_rtc_ntp();
}

void loop() {
int hora, min ;
 pedir_lahora();
delay (2000);

hora = timeinfo.tm_hour;
minuto = timeinfo.tm_min;

}

// Initialize WiFi
void initWiFi() {
  WiFi.begin(ssid , password );
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
}


//**********************************************************//
//* SETUP  rtc                                           **//
//**********************************************************//
void setup_rtc_ntp(void)
{
  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  timestamp = time(NULL);
  rtc.setTime(timestamp + gmtOffset_sec);
}

//**********************************************************//
//* PIDE LA HORA AL SERVER O AL ESP32                     **//
//**********************************************************//
void pedir_lahora(void)
{
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("veo la hora del rtc interno ");
    timestamp = rtc.getEpoch() - gmtOffset_sec;
    timeinfo = rtc.getTimeStruct();
     Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  }
  else
  {
    Serial.print("NTP Time:");
    timestamp = time(NULL);
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  }

  return;
}

