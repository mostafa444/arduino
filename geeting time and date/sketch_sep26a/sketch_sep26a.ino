#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
static const uint8_t D4   = 2;
static const uint8_t D3   = 0;
uint8_t LED_Pin = D4;
uint8_t LED_Pin1 = D3;

const char *ssid     = "mostafa";
const char *password = "mostafa11";

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {

    delay ( 500 );
    Serial.print ( "." );
  }
   Serial.println(WiFi.localIP()); 

  

  timeClient.begin();
}

void loop() {
  timeClient.update();
// Turn the LED off
      digitalWrite(LED_Pin, LOW);


  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());

  delay(10000);
}
