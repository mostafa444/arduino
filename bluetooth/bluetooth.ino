/* HC-05 interfacing with NodeMCU ESP8266
    Author: Circuit Digest(circuitdigest.com)
    
*/
int x ;
int y ;
char data;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;

#include <SoftwareSerial.h>

SoftwareSerial btSerial(7, 8); // Rx,Tx
//SoftwareSerial btSerial(D5, D6); // Rx,Tx

int led = D4;   // led also the internal led of NodemCU
int ledState = LOW;   // led state to toggle
String ledB = "";

unsigned long previousMillis = 0;  // millis instaed of delay
const long interval = 500;  // blink after ecery 500ms

void setup() {
 digitalWrite(D5, HIGH);
   digitalWrite(D6, LOW);

  delay(1000);
  Serial.begin(9600);     
  btSerial.begin(9600);     // bluetooth module baudrate 
  pinMode(D4, OUTPUT);
  Serial.println("Started...");
}

void loop() {

  if (btSerial.available() > 0) {    // check if bluetooth module sends some data to esp8266
    char data = btSerial.read();  // read the data from HC-05
      Serial.println (data);
  /*  switch (data)
    {
      case 'B':         // if receive data is 'B'
        ledB = "blink";   // write the string
        break;
      case 'S':              // if receive data is 'S'
        ledB = "stop";
        break;
      default:
        break;
    }*/
  }
  unsigned long currentMillis = millis();
  if (ledB == "blink") {          // if received data is 'B' the start blinking 
    Serial.println("blinking started");
       //btSerial.write("11");
       //SoftwareSerial btSerial(D5, D6);
       
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(led, ledState);
    }
  }
}
