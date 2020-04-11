  #include <FirebaseESP8266.h>
  #include <ESP8266WiFi.h>
  
  #define WIFI_SSID "mostafa"
  #define WIFI_PASSWORD "mostafa11"
  #define FIREBASE_HOST "https://task3-acbc6.firebaseio.com/"
  #define FIREBASE_AUTH "Mx3ODSA7H6ZwaZzAQsn4CGAYz94Z2IESDbJGUnEK"
  
  FirebaseData firebaseData;
  
  void setup() { 
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
   
   // get value of X
   if (Firebase.getFloat(firebaseData, "/up")) {
      //if  (firebaseData.dataType() == "float") {
        float val = firebaseData.floatData();
        Serial.print("up= "); 
        Serial.println(val);
        delay(1000);
        
        //}
   } 
  
  }
   // get value of Y
   /* if (Firebase.getFloat(firebaseData, "/Y")) {
      //if  (firebaseData.dataType() == "float") {
        float val = firebaseData.floatData();
        Serial.print("Y= "); 
        Serial.println(val);
        delay(1000);
       // }
   } 
   
   // Set value of X
   Firebase.setFloat(firebaseData,"/X",20.0);
  
   // Set value of Y
   Firebase.setFloat(firebaseData,"/Y",25.0);
  */
