
////////https://olivertechnologydevelopment.wordpress.com/2017/08/17/esp8266-sensor-series-gy-521-imu-part-1/
#include "ESP8266WiFi.h"
 int x =0;
 int x1 =0;
 int x2 =0;
int counter=0;
void prinScanResult(int networksFound)
{

 int z =networksFound;
 int z1 =networksFound;
 int z2 =networksFound;
     Serial.print("[");    

///////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="STUDBME2"){
    z=networksFound-1;
    x=WiFi.RSSI(i);
    Serial.print(x);    Serial.print(",");


    
    }


   if (WiFi.SSID(i)=="CMP_LAB1"){
    z1=networksFound-1;
    x1=WiFi.RSSI(i);
    Serial.print(x1);    Serial.print(",");


    }

   if (WiFi.SSID(i)=="RehabLab"){
    z2=networksFound-1;
    x2=WiFi.RSSI(i);
    Serial.print(x2);    Serial.print(x2);



    }

    }


    if (z==networksFound){
    x = -100;
    Serial.print(x);    Serial.print(",");


      }

    if (z1==networksFound){
    x1 = -100;
    Serial.print(x2);    Serial.print(",");
      }
    
    if (z2==networksFound){
      x2= -100;
    Serial.print(x2);    Serial.print(",");
      } 

  Serial.print("0.3");      
         Serial.println("],");   
         counter = counter +1; 

    }




/*


  for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="kn"){
    Serial.printf("\",kn\" : ");
    Serial.printf(" %d, ", WiFi.RSSI(i));
    Serial.println();
    Serial.printf("},");
    Serial.println();
    Serial.println();



    }
    }

      for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)!="kn"){
    Serial.printf("\"kn\" : -100,");
    Serial.println();
    Serial.printf("},");
    Serial.println();
    Serial.println();

    }
    }

*/

















    //Serial.printf(" ''%s'': %d, ", WiFi.SSID(i).c_str(), WiFi.RSSI(i));

    
    //Serial.println("\"kijki\"");
    
    

    



void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);

}


void loop() {
  
    WiFi.scanNetworksAsync(prinScanResult);
      delay(100);
      if (counter == 100){
        
        Serial.println ();
                Serial.println ("//////////////");

        
        }

  }
