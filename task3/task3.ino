#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "Mostafa"
#define WIFI_PASSWORD "mostafa11"
#define FIREBASE_HOST "https://fir-56c20.firebaseio.com/"
#define FIREBASE_AUTH "D1GHg2BOCUzZb0L75LZEeumjv1vrowO0pRboCJ8Q"

static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;



FirebaseData firebaseData;

void setup() { 

   pinMode(D2, OUTPUT);
   pinMode(D3, OUTPUT);
   pinMode(D4, OUTPUT);
   pinMode(D5, OUTPUT);
      pinMode(D6, OUTPUT);
   digitalWrite(D2, LOW);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);

  
 Serial.begin(115200); 
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
 Serial.println(); 
 Serial.print("connecting"); 
 while (WiFi.status() != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500); 
 } 
 Serial.println(); 
 Serial.print("connected: "); 
 Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
} 

void loop() {
 // get the direction
 if (Firebase.getString(firebaseData, "/directions")) {
    //if  (firebaseData.dataType() == "float") {
      String val = firebaseData.stringData();
      Serial.print("directions= "); 
      Serial.println(val);

      //stop
      if (val=="0000")//stop
      {
   digitalWrite(D2, LOW);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);
        }
      else if (val=="3000")//up
      {
   digitalWrite(D2, HIGH);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);  
   analogWrite (D6, 300);
    
        }

        else if (val=="0100") //down
        {
   digitalWrite(D2, LOW);
   digitalWrite(D3, HIGH);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);   
      analogWrite (D6, 300);
   
        }
        else if (val=="0010") //right
        {
   digitalWrite(D2, HIGH);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);  
   analogWrite (D6, 400);     
        }
        else if (val=="0001") //left
        {
   digitalWrite(D2, HIGH);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);  
   analogWrite (D6, 500);     
        }
        else if (val=="1010") //right/up
        {
   digitalWrite(D2, HIGH);
   digitalWrite(D3, LOW);
   digitalWrite(D4, HIGH);
   digitalWrite(D5, LOW);  
      analogWrite (D6, 500);     
    
        }
        else if (val=="1001") //left/up
        {
   digitalWrite(D2, HIGH);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, HIGH);     
      analogWrite (D6, 500);     
 
        }
        else if (val=="0110") //down/right
        {
   digitalWrite(D2, LOW);
   digitalWrite(D3, HIGH);
   digitalWrite(D4, HIGH);
   digitalWrite(D5, LOW);      
      analogWrite (D6, 500);     

        }
        else if (val=="0101") //left/down
        {
   digitalWrite(D2, LOW);
   digitalWrite(D3, HIGH);
   digitalWrite(D4, LOW);
   digitalWrite(D5, HIGH);    
      analogWrite (D6, 500);     
  
        }
        

 } 
//Serial.println(val);
delay (100);
 
 // Set value of X

}
\
/*void stop(){
  digitalWrite(D2, LOW);
   digitalWrite(D3, LOW);
   digitalWrite(D4, LOW);
   digitalWrite(D5, LOW);
  }
 */
