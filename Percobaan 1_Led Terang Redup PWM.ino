/* Percobaan pertama membuat led terang redup menggungakan pwm pada pin 11 */


int ledPin = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  }
  //fade out 
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  }
  //pause 1 second
  delay(1000);
}
