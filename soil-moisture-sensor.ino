#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;
hd44780_I2Cexp lcd2(0x27);

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
const int dryValue = 603;
const int wetValue = 307;

int intervals = (dryValue - wetValue)/3;
float soilMoistureValue = 0;
float voltage = 0;

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
}

void loop() {
  soilMoistureValue = analogRead(A0);
  voltage = (soilMoistureValue * 5) / 1024;

  if(soilMoistureValue > wetValue && soilMoistureValue < (wetValue + intervals)) {
    addTitle();
    lcd.print("B. mokra! " + String(voltage) + "V ");
    delay(90);

  } else if(soilMoistureValue > (wetValue + intervals) && soilMoistureValue < (dryValue - intervals)) {
    addTitle();
    lcd.print("Mokra! " + String(voltage) + "V    ");
    delay(90);

  } else if(soilMoistureValue < dryValue && soilMoistureValue > (wetValue - intervals)) {
    addTitle();
    lcd.print("Sucha! " + String(voltage) + "V    ");
    delay(90);
  }
}

void addTitle() {
  lcd.setCursor(0, 0);
  lcd.print("Wilgotnosc gleby");
  lcd.setCursor(0, 1);
}
