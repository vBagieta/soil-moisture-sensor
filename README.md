# Czujnik wilgotnośći gleby

## Wymagania
- Arduino UNO
- Czujnik wilgotności gleby
- Wyświetlacz LCD (2x16) wraz z modółem I2C

## Biblioteki
- [hd44780](https://www.arduinolibraries.info/libraries/hd44780)
## Podłączenia

### Wyświetlacz
Pin GND z pinem GND na Arduino

Pin VCC z pinem 5V na Arduino

Pin SDA z pinem SDA na Arduino

Pin SCL z pinem SCL na Arduino

### Czujnik wilgotności gleby
Pin GND z pinem GND na Arduino

Pin VCC z pinem 3.3V na Arduino

Pin AUOT z pinem A0 na Arduino

## Kalibracja czujnika wilgotnośći
Kod do kalibracji:

```
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  int val;
  val = analogRead(0); //connect sensor to Analog 0
  Serial.println(val); //print the value to serial port
  delay(100);
}
```
### Czynności
Na początku zapisz najwyższą wartość, jaką czujnik uzyskuje, gdy jest suchy. Zmień wartość w kodzie (domyślnie 603) na zmierzoną:
```
const int AirValue = 603; -> const int AirValue = TWOJA_WARTOŚĆ;
```


Sprawdź najniższą wartość, jaką osiagą czujnik po całkowitemu zamoczeniowi w wodzie.  Zmień wartość w kodzie (domyślnie 307) na zmierzoną:

```
const int WaterValue = 307; -> const int WaterValue = TWOJA_WARTOŚĆ;
```

