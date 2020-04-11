#include "ESP8266WiFi.h"
int counter = 0 ;

int z ;
void prinScanResult(int networksFound)
{
 int z =networksFound;
 int z1 =networksFound;
 int z2 =networksFound;
 Serial.printf("{");     
 Serial.println();
  /*for (int i = 0; i < networksFound; i++)  
    {    

   if (WiFi.SSID(i)=="STUDBME1"){
    z=networksFound-1;
    Serial.printf("\"STUDBME1\" : ");
    Serial.printf(" %d, ", WiFi.RSSI(i));
    Serial.println();
    }
    }
    if (z==networksFound){
    Serial.printf("\"STUDBME1\" : -100,");
    Serial.println();
      }*/
///////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="STUDBME2"){
    z1=networksFound-1;
    Serial.printf("\"STUDBME2\" : ");
    Serial.printf(" %d, ", WiFi.RSSI(i));
    Serial.println();
    }
    }
    if (z1==networksFound){
    Serial.printf("\"STUDBME2\" : -100,");
    Serial.println();
      }
//////////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="CMP_LAB1"){
    z2=networksFound-1;
    Serial.printf("\"CMP_LAB1\" : ");
    Serial.printf(" %d, ", WiFi.RSSI(i));
    Serial.println();
    }
    }
    if (z2==networksFound){
    Serial.printf("\"CMP_LAB1\" : -100,");
    Serial.println();
      }
///////////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="RehabLab"){
    z2=networksFound-1;
    Serial.printf("\"RehabLab\" : ");
    Serial.printf(" %d, ", WiFi.RSSI(i));
    Serial.println();
    }
    }
    if (z2==networksFound){
    
    Serial.printf("\"RehabLab\" : -100,");
    Serial.println();
      }

    Serial.printf("\"O\" : 0.2 ");
    Serial.printf("},");
    Serial.println();
    Serial.println();
    Serial.println();

    counter = counter+1;



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
    delay(400);
    if (counter==70){
      
       Serial.println ("/////////////////");
      }

  }
