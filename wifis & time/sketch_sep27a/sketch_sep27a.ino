#include "ESP8266WiFi.h"
#include <NTPClient.h>
#include <WiFiUdp.h>




const char *ssid     = "mostafa";
const char *password = "mostafa11";

const long utcOffsetInSeconds = 3600;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);






void prinScanResult(int networksFound)
{
  Serial.printf("%d network(s) found\n", networksFound);
  for (int i = 0; i < networksFound; i++)
    {
    //distance =  pow(10,(measuredpower-WiFi.RSSI(i))/(10*n));
    Serial.printf("%d: %s, Ch:%d %d %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.channel(i), WiFi.RSSI(i) , WiFi.encryptionType(i) == ENC_TYPE_NONE ? "open" : "");
    }
}


void setup()
{
  
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);





  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();


  

}


void loop() {
  
    WiFi.scanNetworksAsync(prinScanResult);
      delay(10000);


  timeClient.update();

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
