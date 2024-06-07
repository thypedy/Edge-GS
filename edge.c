#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

int led_verde = 3;
int led_vermelho = 4;
int buzzerPin = 7;
int potPin = A0;  // Definindo a porta do potenciômetro

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);  // Configurando o potenciômetro como entrada

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 3);
  lcd.print("Lernfeld LF07-V2");
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Lendo o valor do potenciômetro e mapeando para uma faixa de temperatura
  int potValue = analogRead(potPin);
  float tempAdjustment = map(potValue, 0, 1023, -10, 10);  // Ajusta a temperatura em +/- 10 graus
  float adjustedTemp = t + tempAdjustment;

  lcd.setCursor(2, 0);
  lcd.print("Sensor da praia");
  lcd.setCursor(0, 1);
  lcd.print("Temperatura: " + String(adjustedTemp, 1) + " C");
  lcd.setCursor(2, 2);
  lcd.print("Humidade: " + String(h, 1) + " %");

  if (adjustedTemp > 30 || adjustedTemp < 15) {
    digitalWrite(led_vermelho, HIGH);
    delay(1000);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, LOW);
    tone(buzzerPin, 100, 1000);
  } else {
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_verde, HIGH);
    delay(1000);
    digitalWrite(led_verde, LOW);
    noTone(buzzerPin);
  }
}