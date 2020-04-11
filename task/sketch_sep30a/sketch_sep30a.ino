#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>



void prinScanResult(int networksFound)
{
  Serial.printf("%d network(s) found\n", networksFound);
  for (int i = 0; i < networksFound; i++)
    {
    Serial.printf("%d: %s, Ch:%d %d %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.channel(i), WiFi.RSSI(i) , WiFi.encryptionType(i) == ENC_TYPE_NONE ? "open" : "");
    //distance[i]= WiFi.RSSI(i);

    }
}






void setup() {
 
  Serial.begin(115200);                                  //Serial connection
  
  
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  
  
  
  WiFi.begin("STUDBME2", "BME2Stud");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {



 WiFi.scanNetworksAsync(prinScanResult);
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;    //Declare object of class HTTPClient
 
   http.begin("http://f04ec07c.ngrok.io/hi/225/3");      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST("Message from ESP8266");   //Send the request
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(1000);  //Send a request every 30 seconds
 
}
