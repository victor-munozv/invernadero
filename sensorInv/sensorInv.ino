
// definiciones de sensor de temperatura y humedad (AM2302)
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// definiciones de micro sd card adapted
#include "SD.h"
#include "SPI.h"
#define SSpin 53
File archivo;

//definiciones de sensor de luz
#define light A0 // define entrada de pin
//definiciones de sensor de presión atmosferica(barometro)
#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;

float TEMPERATURA;
float PRESION;
//definiciones de reloj(DS3231)





void setup() {
  //comunicación con puerto serial
  Serial.begin(9600);
  Serial.println(F("green field by victor"));

  // primera ejecución de sensor de temperatura y humedad (AM2302)
  dht.begin();

  // definiciones de micro sd card adapted
  if (!SD.begin(SSpin)) {
    Serial.println("Fallo en inicializar memoria");
    return;
  }
  Serial.print("Inicializó correctamente la memoria");
  archivo = SD.open("datos.txt" , FILE_WRITE);
  if (archivo) {
    for (int i = 1; i < 1; i++) {
      float h = dht.readHumidity();
      float t = dht.readTemperature();

      archivo.print(i);
      archivo.print(",");
      archivo.print(t);
      archivo.print(",");
      archivo.print(h);
      Serial.print(F("Humidity: "));
      Serial.print(h);
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.println(F("°C "));
      delay(1000);
    }
    archivo.close();
  }
  //definiciones de sensor de luz

  //definiciones de sensor de presión atmosferica(barometro)
  if (!bmp.begin() ) {
    Serial.println("no encontrado");
  }

}









void loop() {
  /*
    TEMPERATURA = bmp.readTemperature();
    PRESION = bmp.readPressure()/100;
  */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" C ");
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println(" % ");
  delay(500);
  int Lvalue = analogRead(light);// read the light
  int mVolt = map(Lvalue, 0, 1023, 0, 5000); // map analogue reading to 5000mV
  float volt = (double)mVolt / 1000; // convert millivolt to volt

  Serial.print(mVolt);// print millivolt
  Serial.print( "mV ");
  Serial.print(volt, 3); // print volts with 3 decimal places
  Serial.println( "V ");
  delay(1000);// wait for 1000 milliseconds
}
