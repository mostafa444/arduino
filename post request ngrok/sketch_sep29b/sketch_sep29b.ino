#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
String z ;
String y = "http://2308ffa1.ngrok.io/";
char data;
String response;
int xx;
int yy;

SoftwareSerial btSerial(D2, D3); // Rx,Tx



void setup() {
 
  Serial.begin(115200);                                  //Serial connection
  btSerial.begin(9600);     // bluetooth module baudrate 
  WiFi.begin("amr", "mritasks");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
    xx = 8;
    yy = 9;
   if (btSerial.available() > 0  ) {    // check if bluetooth module sends some data to esp8266
   HTTPClient http;    //Declare object of class HTTPClient
   data = btSerial.read();  // read the data from HC-0
   Serial.println(data);
   z = y + data;
   http.begin(z);      //Specify request destination
   Serial.println(z);

   //http.begin("http://abe415b4.ngrok.io/53");      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST("Message from ESP8266");   //Send the request
   String payload = http.getString();                  //Get the response payload
 
   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
   btSerial.write("user1");

   http.end();  //Close connection
   }
 
}
