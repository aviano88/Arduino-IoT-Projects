// Project 3 : Membuat swtich on off pada led builtin menggunakan switch button di breadboard

int switchPin = 12; // << Input pin 12 
int ledPin = LED_BUILTIN; // << deklarasi led yang digunakan
int switchState = LOW; // << keadaan awal swtich adalah low atau tidak ada tegangan

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //<< memulai serial monitor dengan 9600 baud rate
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  Serial.println(switchState);

  if (switchState == HIGH){ // << ketika switch kondsi high maka led pin menyala
    digitalWrite(ledPin, HIGH); 
  } else { // << ketika kondisi swith low maka led pin mati
      digitalWrite(ledPin, LOW);
  }

}
