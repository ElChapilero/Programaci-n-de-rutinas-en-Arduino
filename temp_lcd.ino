#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int ledPin   = 13;
const int fanPin   = 10;
const int sensorPin = A0;

float temperatura = 0;

void setup() {
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.print("Sistema Temp");
  delay(2000);
  lcd_1.clear();

  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(fanPin, LOW);
}
void loop() {
  int lectura = analogRead(sensorPin);
  float voltaje = lectura * (5.0 / 1023.0);
  temperatura = (voltaje - 0.5) * 100.0;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(temperatura, 1);
  lcd_1.print(" C   ");
  
  if (temperatura <= 10) {
    digitalWrite(fanPin, LOW);
    digitalWrite(ledPin, HIGH);
    lcd_1.setCursor(0, 1);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  
  else if (temperatura > 10 && temperatura <= 25) {
    digitalWrite(fanPin, LOW);
    digitalWrite(ledPin, LOW);
    lcd_1.setCursor(0, 1);
    delay(1000);
  }
  
  else if (temperatura >= 26) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(fanPin, HIGH);
    lcd_1.setCursor(0, 1);
    delay(1000);
  }
}
