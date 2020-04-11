#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "Wire.h"
double value = 0 ;
int detection = 0 ;





/////////////////////////mPU/////////////
const uint8_t MPU_addr=0x68; // I2C address of the MPU-6050
 
const float MPU_GYRO_250_SCALE = 131.0;
const float MPU_GYRO_500_SCALE = 65.5;
const float MPU_GYRO_1000_SCALE = 32.8;
const float MPU_GYRO_2000_SCALE = 16.4;
const float MPU_ACCL_2_SCALE = 16384.0;
const float MPU_ACCL_4_SCALE = 8192.0;
const float MPU_ACCL_8_SCALE = 4096.0;
const float MPU_ACCL_16_SCALE = 2048.0;
 
  
 
struct rawdata {
int16_t AcX;
int16_t AcY;
int16_t AcZ;
int16_t Tmp;
int16_t GyX;
int16_t GyY;
int16_t GyZ;
};
 
struct scaleddata{
float AcX;
float AcY;
float AcZ;
float Tmp;
float GyX;
float GyY;
float GyZ;
};
 
bool checkI2c(byte addr);
void mpu6050Begin(byte addr);
rawdata mpu6050Read(byte addr, bool Debug);
void setMPU6050scales(byte addr,uint8_t Gyro,uint8_t Accl);
void getMPU6050scales(byte addr,uint8_t &Gyro,uint8_t &Accl);
scaleddata convertRawToScaled(byte addr, rawdata data_in,bool Debug);

///////////////////////////////////////////////















static const uint8_t D4   = 2;
uint8_t LED_Pin = D4;
static const uint8_t D3   = 0;
uint8_t LED_Pin1 = D3;
static const uint8_t D5   = 14;
uint8_t LED_Pin2 = D5;




String z ;
double x1;
double x2;
double x4;
String x3 = "/" ;
String y = "http://e1065622.ngrok.io/";

void prinScanResult(int networksFound)
{

 int z =networksFound;
 int z1 =networksFound;
 int z2 =networksFound;

///////////////////////////////////////////
 for (int i = 0; i < networksFound; i++)
    {    

   if (WiFi.SSID(i)=="mostafa"){
    z1=networksFound-1;
    x1=WiFi.RSSI(i);
rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
    
    }


   if (WiFi.SSID(i)=="CMP_LAB1"){
    z2=networksFound-1;
    x2=WiFi.RSSI(i);
    rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);


    }

   if (WiFi.SSID(i)=="RehabLab"){
    z2=networksFound-1;
    x4=WiFi.RSSI(i);
    rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);


    }
rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
    }


    if (z1==networksFound){
    x1 = -100;

rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

      }

    if (z2==networksFound){
    x2 = -100;
    rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

      }
    
    if (z2==networksFound){
      x4= -100;
      rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

      } 
rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
    
    }






void setup() {
   pinMode(LED_Pin, OUTPUT);
   pinMode(LED_Pin1, OUTPUT);
      pinMode(LED_Pin2, OUTPUT);


   ////////////////MPU//////////////
  Wire.begin();
  Serial.begin(115200);                                  //Serial connection
 
  
mpu6050Begin(MPU_addr);
 
  
    
    
    
    ////////////////////////////////
  
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
//digitalWrite(LED_Pin2, HIGH);


/////////////////////////////MPU/////////////////
rawdata next_sample;
setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

//////////////////////////////////////////////////

  



 //if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   digitalWrite(LED_Pin1, LOW);
   WiFi.scanNetworksAsync(prinScanResult);

   HTTPClient http;    //Declare object of class HTTPClient
   z = y + x1 + x3 + x2 +x3 + x4 +x3+ detection  ;
   http.begin(z);      //Specify request destination
   http.addHeader("Content-Type", "text/plain");  //Specify content-type header
 
   int httpCode = http.POST("Message from ESP8266");   //Send the request

setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);


   
   String payload = http.getString();                  //Get the response payload

setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

 
   Serial.println(httpCode);   //Print HTTP return code
   if (httpCode ==-1){
     for (int i = 0; i < 4; i++){
      digitalWrite(LED_Pin1, HIGH);

      setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
      digitalWrite(LED_Pin1, LOW); 

 
       }
     }
    else {
         digitalWrite(LED_Pin, HIGH);
          setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

          delay(100);
          setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
          digitalWrite(LED_Pin, LOW);
      }
   //Serial.println(payload);    //Print request response payload
   Serial.println(z);    //Print request response payload

   http.end();  //Close connection
 
/* else{
     digitalWrite(LED_Pin1, HIGH);
    Serial.println("Error in WiFi connection"); 
   
 }
*/
 delay(100);  //Send a request every 30 seconds

setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
  
  
delay(100);  //Send a request every 30 seconds


  setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
  
delay(100);  //Send a request every 30 seconds

setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);
  
  
delay(100);  //Send a request every 30 seconds

setMPU6050scales(MPU_addr,0b00000000,0b00010000);
next_sample = mpu6050Read(MPU_addr, true);
convertRawToScaled(MPU_addr, next_sample,true);

  




}








///////////////////////MPU/////////////////
void mpu6050Begin(byte addr){
// This function initializes the MPU-6050 IMU Sensor
// It verifys the address is correct and wakes up the
// MPU.
if (checkI2c(addr)){
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B); // PWR_MGMT_1 register
Wire.write(0); // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
 
delay(30); // Ensure gyro has enough time to power up
}
}
 
bool checkI2c(byte addr){
// We are using the return value of
// the Write.endTransmisstion to see if
// a device did acknowledge to the address.
Serial.println(" ");
Wire.beginTransmission(addr);
 
if (Wire.endTransmission() == 0)
{
Serial.print(" Device Found at 0x");
Serial.println(addr,HEX);
return true;
}
else
{
Serial.print(" No Device Found at 0x");
Serial.println(addr,HEX);
return false;
}
}
 
  
 
rawdata mpu6050Read(byte addr, bool Debug){
// This function reads the raw 16-bit data values from
// the MPU-6050
 
rawdata values;
 
Wire.beginTransmission(addr);
Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(addr,14,true); // request a total of 14 registers
values.AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
values.AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
values.AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
values.Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
values.GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
values.GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
values.GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
 
 
if(Debug){
Serial.print(" GyX = "); Serial.print(values.GyX);
Serial.print(" | GyY = "); Serial.print(values.GyY);
Serial.print(" | GyZ = "); Serial.print(values.GyZ);
Serial.print(" | Tmp = "); Serial.print(values.Tmp);
Serial.print(" | AcX = "); Serial.print(values.AcX);
Serial.print(" | AcY = "); Serial.print(values.AcY);
Serial.print(" | AcZ = "); Serial.println(values.AcZ);
}
 
return values;
}
 
void setMPU6050scales(byte addr,uint8_t Gyro,uint8_t Accl){
Wire.beginTransmission(addr);
Wire.write(0x1B); // write to register starting at 0x1B
Wire.write(Gyro); // Self Tests Off and set Gyro FS to 250
Wire.write(Accl); // Self Tests Off and set Accl FS to 8g
Wire.endTransmission(true);
}
 
void getMPU6050scales(byte addr,uint8_t &Gyro,uint8_t &Accl){
Wire.beginTransmission(addr);
Wire.write(0x1B); // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(addr,2,true); // request a total of 14 registers
Gyro = (Wire.read()&(bit(3)|bit(4)))>>3;
Accl = (Wire.read()&(bit(3)|bit(4)))>>3;
}
 
  
 
scaleddata convertRawToScaled(byte addr, rawdata data_in, bool Debug){
 
scaleddata values;
float scale_value = 0.0;
byte Gyro, Accl;
 
getMPU6050scales(MPU_addr, Gyro, Accl);
 
if(Debug){
Serial.print("Gyro Full-Scale = ");
}
 
switch (Gyro){
case 0:
scale_value = MPU_GYRO_250_SCALE;
if(Debug){
Serial.println("±250 °/s");
}
break;
case 1:
scale_value = MPU_GYRO_500_SCALE;
if(Debug){
Serial.println("±500 °/s");
}
break;
case 2:
scale_value = MPU_GYRO_1000_SCALE;
if(Debug){
Serial.println("±1000 °/s");
}
break;
case 3:
scale_value = MPU_GYRO_2000_SCALE;
if(Debug){
Serial.println("±2000 °/s");
}
break;
default:
break;
}
 
values.GyX = (float) data_in.GyX / scale_value;
values.GyY = (float) data_in.GyY / scale_value;
values.GyZ = (float) data_in.GyZ / scale_value;
 
scale_value = 0.0;
if(Debug){
Serial.print("Accl Full-Scale = ");
}
switch (Accl){
case 0:
scale_value = MPU_ACCL_2_SCALE;
if(Debug){
Serial.println("±2 g");
}
break;
case 1:
scale_value = MPU_ACCL_4_SCALE;
if(Debug){
Serial.println("±4 g");
}
break;
case 2:
scale_value = MPU_ACCL_8_SCALE;
if(Debug){
Serial.println("±8 g");
}
break;
case 3:
scale_value = MPU_ACCL_16_SCALE;
if(Debug){
Serial.println("±16 g");
}
break;
default:
break;
}
values.AcX = (float) data_in.AcX / scale_value;
values.AcY = (float) data_in.AcY / scale_value;
values.AcZ = (float) data_in.AcZ / scale_value;
Serial.println();
Serial.println();

Serial.print(" GyX = "); Serial.print(values.GyX);
Serial.print(" °/s| GyY = "); Serial.print(values.GyY);
Serial.print(" °/s| GyZ = "); Serial.print(values.GyZ);
Serial.print(" °/s| Tmp = "); Serial.print(values.Tmp);
Serial.print(" °C| AcX = "); Serial.print(values.AcX);
Serial.print(" g| AcY = "); Serial.print(values.AcY);
Serial.print(" g| AcZ = "); Serial.print(values.AcZ);
Serial.println();
 Serial.println();
 if (values.AcX <-1.8){
      digitalWrite(LED_Pin2, HIGH);
      detection =1;
  }
 
 
//values.Tmp = (float) data_in.Tmp / 340.0 + 36.53;
 
/*if(Debug){
Serial.print(" GyX = "); Serial.print(values.GyX);
Serial.print(" °/s| GyY = "); Serial.print(values.GyY);
Serial.print(" °/s| GyZ = "); Serial.print(values.GyZ);
Serial.print(" °/s| Tmp = "); Serial.print(values.Tmp);
Serial.print(" °C| AcX = "); Serial.print(values.AcX);
Serial.print(" g| AcY = "); Serial.print(values.AcY);
Serial.print(" g| AcZ = "); Serial.print(values.AcZ);Serial.println(" g");
}*/
 
return values;
}
