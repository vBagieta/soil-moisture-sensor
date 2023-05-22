#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "DHT.h"
#define DHT11_PIN 2

DHT dht;
hd44780_I2Cexp lcd;
hd44780_I2Cexp lcd2(0x27);

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
const int dryValue = 603;
const int wetValue = 307;

int intervals = (dryValue - wetValue)/3;
float soilMoistureValue = 0;
float voltage = 0;
int envHumidity = dht.getHumidity();
int envTemperature = dht.getTemperature();

void setup()
{
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);

  if(status) {
  status = -status; 

  hd44780::fatalError(status);
  }
  lcd.setCursor(0, 1);
  lcd.print("Czekam na zmiane");

  dht.setup(DHT11_PIN);
}

void loop() {
  soilMoistureValue = analogRead(A0);
  voltage = (soilMoistureValue * 5) /1024;

  if(soilMoistureValue > wetValue && soilMoistureValue < (wetValue + intervals)) {
     createDisplay("B.mokra!");

  } else if(soilMoistureValue > (wetValue + intervals) && soilMoistureValue < (dryValue - intervals)) {
     createDisplay("Mokra!");

  } else if(soilMoistureValue < dryValue && soilMoistureValue > (dryValue - intervals)) {
    createDisplay("Sucha!");
  }
}

void createDisplay(String sensorStatus) {
  lcd.setCursor(0, 0);
  lcd.print("W. gleby " + String(voltage) + "V  ");
  lcd.setCursor(0, 1);
  lcd.print(String(sensorStatus) + " " + String(envHumidity) + "%T" + String(envTemperature) + "*    ");
  delay(100);
}
