
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
//definiciones de sensor de presión atmosferica(barometro)
//definiciones de reloj(DS3231)





void setup() {
  //comunicación con puerto serial
  Serial.begin(9600);
  Serial.println(F("green field by victor"));
  
  // primera ejecución de sensor de temperatura y humedad (AM2302)
  dht.begin();

  
  if (!SD.begin(SSpin)){
    Serial.println("Fallo en inicializar memoria");
    return;
  }
  Serial.print("Inicializó correctamente la memoria");
  archivo = SD.open("datos.txt" , FILE_WRITE);

  if(archivo){
    
    for (int i=1; i< 4000; i++){
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
}









void loop() {
}
