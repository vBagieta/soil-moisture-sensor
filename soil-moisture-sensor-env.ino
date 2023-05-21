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
int soilMoistureValue = 0;

void setup()
{
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);

  if(status) {
  status = -status; 

  hd44780::fatalError(status);
  }

  lcd.print("Wilgotnosc gleby");
  lcd.setCursor(0, 1);
  lcd.print("Czekam na zmiane");

  dht.setup(DHT11_PIN);

}

void loop() {
  soilMoistureValue = analogRead(A0);
  int envHumidity = dht.getHumidity();
  int envTemperature = dht.getTemperature();

  if(soilMoistureValue > wetValue && soilMoistureValue < (wetValue + intervals)) {

    lcd.print("Wilgotnosc gleby:");
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.print("B.Mokra H" + String(envHumidity) + "%T" + String(envTemperature) + "*  ");
    delay(90);

  } else if(soilMoistureValue > (wetValue + intervals) && soilMoistureValue < (dryValue - intervals)) {

    lcd.print("Wilgotnosc gleby:");
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.print("Mokra! H" + String(envHumidity) + "% T" + String(envTemperature) + "* ");
    delay(90);

  } else if(soilMoistureValue < dryValue && soilMoistureValue > (dryValue - intervals)) {

    lcd.print("Wilgotnosc gleby:");
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.print("Sucha! H" + String(envHumidity) + "% T" + String(envTemperature) + "* ");
    delay(90);
  }
}
