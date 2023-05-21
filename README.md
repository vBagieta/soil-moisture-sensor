# Czujnik wilgotnośći gleby
[Wersja zwykłya](https://github.com/vBagieta/soil-moisture-sensor/blob/main/soil-moisture-sensor.ino)

[Wersja z czujnikiem wilgotności i temperatury](https://github.com/vBagieta/soil-moisture-sensor/blob/main/soil-moisture-sensor-env.ino)
## Wymagania
- [Arduino UNO](https://botland.com.pl/arduino-seria-podstawowa-oryginalne-plytki/1060-arduino-uno-rev3-a000066-7630049200050.html)
- [Czujnik wilgotności gleby](https://botland.com.pl/gravity-czujniki-pogodowe/10305-dfrobot-gravity-analogowy-czujnik-wilgotnosci-gleby-odporny-na-korozje-sen0193-5903351243155.html?cd=18298825651&ad=&kd=&gclid=CjwKCAjwgqejBhBAEiwAuWHioMwWA4SEuGi1RUKJWuG2f7o5MhYemAxIOgkFh670djLlfkb2HUvX_BoCisoQAvD_BwE)
- [Wyświetlacz LCD (2x16) wraz z modułem I2C](https://botland.com.pl/wyswietlacze-alfanumeryczne-i-graficzne/2351-wyswietlacz-lcd-2x16-znakow-niebieski-konwerter-i2c-lcm1602-5904422309244.html)
- [Czujnik wilgotnośći i temperatury](https://botland.com.pl/czujniki-multifunkcyjne/1886-czujnik-temperatury-i-wilgotnosci-dht11-modul-przewody-5903351242448.html?cd=18298825138&ad=&kd=&gclid=CjwKCAjwgqejBhBAEiwAuWHioJbbUovxF6pOOuP1HUgdDNM5c0fvh1O-9PxHxg97GvXvbL3xxiLDmRoC1_MQAvD_BwE) *Jeżeli użyjesz wersji z czujnikiem wilgotnośći i temperatury*

## Biblioteki
- [hd44780](https://www.arduinolibraries.info/libraries/hd44780)
- [arduino-DHT](https://github.com/markruys/arduino-DHT) *Jeżeli użyjesz wersji z czujnikiem wilgotnośći i temperatury*
## Podłączenia

### Wyświetlacz
Pin `GND` z pinem `GND` na Arduino

Pin `VCC` z pinem `5V` na Arduino

Pin `SDA` z pinem `SDA` na Arduino

Pin `SCL` z pinem `SCL` na Arduino

### Czujnik wilgotności gleby
Pin `GND` z pinem `GND` na Arduino

Pin `VCC` z pinem `3.3V` na Arduino

Pin `AUOT` z pinem `A0` na Arduino

### Czujnik wilgotnośći i temperatury otoczenia
Pin `+` z pinem `5V` na Arduino

Pin `out` z pinem `2` na Arduino

Pin `-`z pinem `GND` na Arduino


## Kalibracja czujnika wilgotnośći
### Kod do kalibracji:
Pin danych z czujnika został podpięty do pinu `A0`!

```
void setup() {
  Serial.begin(9600);
}
void loop() {
  int val;
  val = analogRead(0);
  Serial.println(val);
  delay(100);
}
```
### Kroki
Na początku zapisz najwyższą wartość, jaką czujnik uzyskuje, gdy jest suchy. Zmień wartość w kodzie (domyślnie 603) na zmierzoną:
```
const int AirValue = 603; -> const int AirValue = TWOJA_WARTOŚĆ;
```


Sprawdź najniższą wartość, jaką osiagą czujnik po całkowitemu zamoczeniowi w wodzie.  Zmień wartość w kodzie (domyślnie 307) na zmierzoną:

```
const int WaterValue = 307; -> const int WaterValue = TWOJA_WARTOŚĆ;
```

Teraz wystarczy załadować kod do Arduino i wszytko powinno działać!

