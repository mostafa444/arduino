/* Made by Tomas Kopunec
 *  1.11.2018
 *  
 *  By default SMART BLUETOOTH app
 *  sends 'a' when turning ON and 'b' when turning OFF
 * 
 *  If you have any questions or issues
 *  don't hesitate and send me a message here: devkopunec@gmail.com
 *  
 *  Don't forget to leave a 5-star rating and nice feedback
 *  
 *  Thanks, Kopunec
 */


const int led = 2;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  char c = Serial.read();
  if(c == 'a'){
    digitalWrite(led, HIGH);
  }
  else if(c == 'b'){
    digitalWrite(led, LOW);
  }
  else{
      
  }
  delay(25);
}
