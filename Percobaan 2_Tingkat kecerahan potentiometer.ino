
//Percobaan 2 : Mengatur tingkat kecerahan led builtin menggunakan potentiometer.

const int potPin = A2;
const int ledPin = LED_BUILTIN;
int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(potVal);

  digitalWrite(LED_BUILTIN, LOW);
  delay(potVal);

}
