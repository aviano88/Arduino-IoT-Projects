//Percobaan 5_Sistem Alarm jarak menggunakan sensor hc sr04 dan led buzzer sebagai peringatan_copy_20230125162310 
// constants won't change. They're used here to set pin numbers:
const int triggerpin = 4;
const int echopin = 7;
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin
      int buzzerPin = 9;

float duration;
float distance;

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //inialisasi triggerpin sebagai input dan echopin sebagai output
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Jarak : ");
  Serial.println(distance);

  delay(100);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ( distance <= 30.000 ) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin,1000,5000);
    delay(500);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(500);
  }
}
