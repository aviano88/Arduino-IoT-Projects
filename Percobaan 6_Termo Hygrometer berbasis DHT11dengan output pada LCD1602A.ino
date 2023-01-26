//Percobaan 6_Termo Hygrometer berbasis DHT11dengan output pada LCD1602A
//Menggunakan referensi dari https://github.com/BasOnTech/Arduino-Beginners-EN/tree/master/E13-dht11-dht22-temp-humid-sensor
// dan LCD examples yang disediakan arduino ide
// dilakukan modifikasi pada line code sesuai dengan kebutuhan.

#include "DHT.h"             // Library for DHT sensors

#define dhtPin 13            // data pin

/*
 * Uncomment the correct DHT chip
 */
#define dhtType DHT11        // DHT 11
//#define dhtType DHT22      // DHT 22 (AM2302), AM2321
//#define dhtType DHT21      // DHT 21 (AM2301)

DHT dht(dhtPin, dhtType);    // Initialise the DHT library

float humidityVal;           // humidity
float tempValC;              // temperature in degrees Celcius
float tempValF;              // temperature in degrees Fahrenheit
float heatIndexC;            // windchill in degrees Celcius
float heatIndexF;            // windchill in degrees Fahrenheit

// include the library code:


#include "Arduino.h"
#include "LiquidCrystal.h"
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);        // Initialise the serial monitor
  dht.begin();               // start with reading the DHT sensor
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    humidityVal = dht.readHumidity();        // get the humidity from the DHT sensor
  tempValC = dht.readTemperature();        // get the temperature in degrees Celcius from the DHT sensor
  tempValF = dht.readTemperature(true);    // get the temperature in degrees Fahrenheit from the DHT sensor

  // Check if all values are read correctly, if not try again and exit loop()
  if (isnan(humidityVal) || isnan(tempValC) || isnan(tempValF)) {
    Serial.println("Reading DHT sensor failed!");

    // end the loop() function
    return;
  }
  
  // Calculate the windchill in degrees Celcius
  heatIndexC = dht.computeHeatIndex(tempValC, humidityVal, false);

  // Calculate the windchill in degrees Fahrenheit
  heatIndexF = dht.computeHeatIndex(tempValF, humidityVal);

  // Print all values to the serial monitor
  // \t prints a tab character, \n a newline
  Serial.print(humidityVal);
  Serial.print("\t");
  Serial.print(tempValC);
  Serial.print("\n");
  
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Humid = ");
  lcd.print(humidityVal);
  lcd.print("%");
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("Temp  = ");
  lcd.print(tempValC);
  lcd.print((char)223);
  lcd.print("C");
  delay(1000);
}

