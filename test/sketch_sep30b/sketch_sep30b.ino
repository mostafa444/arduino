#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
static const uint8_t D4   = 4;
uint8_t LED_Pin = D4;
static const uint8_t D3   = 0;
uint8_t LED_Pin1 = D3;

String z ;
double x1;
double x2;
double x4;
String x3 = "/" ;
String y = "http://f04ec07c.ngrok.io/hi/";

void prinScanResult(int networksFound)
{

 int z =networksFound;
 int z1 =networksFound;
 int z2 =networksFound;

///////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="STUDBME2"){
    z1=networksFound-1;
    x1=WiFi.RSSI(i);
    }
    }
    if (z1==networksFound){
    x1 = -100;
      }
//////////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="CMP_LAB1"){
    z2=networksFound-1;
    x2=WiFi.RSSI(i);

    }
    }
    if (z2==networksFound){
    x2 = -100;

      }
///////////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="RehabLab"){
    z2=networksFound-1;
    x4=WiFi.RSSI(i);

    }
    }
    if (z2==networksFound){
      x4= -100;
      }

      
    
    }






void setup() {
   pinMode(LED_Pin, OUTPUT);
   pinMode(LED_Pin1, OUTPUT);

  Serial.begin(115200);                                  //Serial connection
  
  
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  
  
  
  WiFi.begin("mostafa", "mostafa11");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
      delay(500);
   digitalWrite(LED_Pin1, HIGH);
    Serial.println("Waiting for connection");

  }
 
}
 
void loop() {



 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   digitalWrite(LED_Pin1, LOW);
   WiFi.scanNetworksAsync(prinScanResult);

   HTTPClient http;    //Declare object of class HTTPClient
   z = y + x1 + x3 + x2 +x3 + x4  ;
   http.begin(z);      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST("Message from ESP8266");   //Send the request
   digitalWrite(LED_Pin, HIGH);
   delay(1000);
   digitalWrite(LED_Pin, LOW);



   
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   if (httpCode ==-1){
    Serial.println(111111111);   //Print HTTP return code
   for (int i = 0; i < 10; i++)
   {
    digitalWrite(LED_Pin1, HIGH);
    delay (100);
    digitalWrite(LED_Pin1, LOW);
    delay (100);
    
   }
    
    }
   Serial.println(payload);    //Print request response payload
   Serial.println(z);    //Print request response payload

   http.end();  //Close connection
 
 }
 else{
     digitalWrite(LED_Pin1, HIGH);

    Serial.println("Error in WiFi connection");   
 
 }

  delay(3000);  //Send a request every 30 seconds
 
}
