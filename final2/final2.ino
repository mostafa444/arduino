

static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
//String data;
String data;
String DATA;
String z ;
double x1;
double x2;
double x4;
String x3 = "/" ;
String y = "http://abe415b4.ngrok.io/";


#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>



SoftwareSerial btSerial(D2, D3); // Rx,Tx
//SoftwareSerial btSerial(D5, D6); // Rx,Tx

void setup() {
  Serial.begin(115200);                                  //Serial connection
  btSerial.begin(9600);     // bluetooth module baudrate 
  pinMode(D4, OUTPUT);
  Serial.println("Started...");
  WiFi.begin("mostafa", "mostafa11");   //WiFi connection
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
  
  
  }
  
}

void loop() {
  if (btSerial.available() > 0  ) {    // check if bluetooth module sends some data to esp8266
      data = btSerial.readString();  // read the data from HC-0

          HTTPClient http;    //Declare object of class HTTPClient
      z = y + data;
      http.begin(z);
       Serial.println (z);
      // Serial.println (data);
      // Serial.println (data[1]);

      btSerial.write("ZFTTTTTTTTTTTTTTTTTTTT");
      http.addHeader("Content-Type", "text/plain");  //Specify conte nt-type header
      int httpCode = http.POST("Message from ESP8266");   //Send the request
     
     String payload = http.getString();                //Get the response payload
      Serial.println(payload);    //Print request response payload
      if (payload == "arr"){
   Serial.println(httpCode);   //Print HTTP return code
   btSerial.write("arr");}
   http.end();
   delay (100);
    }

   /* switch (data)
    {
      case 'B':         // if receive data is 'B'
        //ledB = "blink";   // write the string
      digitalWrite(D4, HIGH);
      delay(100);
      digitalWrite(D4, LOW);
      delay(100);
      digitalWrite(D4, HIGH);
      delay(100);
      digitalWrite(D4, LOW);
        break;
      case 'S':              // if receive data is 'S'
        //ledB = "stop";
      digitalWrite(D4, LOW);
      Serial.println("sdas");
        break;
      default:
        break;
    }*/
  
}
  
