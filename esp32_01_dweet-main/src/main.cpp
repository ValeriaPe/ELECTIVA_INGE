#include "DHT.h"
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "covid";
const char* password = "abc12345";
const char* dweetIO = "https://dweet.io/dweet/for/CovidJunior";

#define DHTPIN 4  

#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE); //ACT. 6


void setup(){
   Serial.begin(9600);
   Serial.println("Ensayo del DHT22!");
   dht.begin();
}

void loop(){
   delay(2000);
   float humedad = dht.readHumidity(); 
   float temperatura = dht.readTemperature(); 
   float tempFarenheit = dht.readTemperature(true); 
   
   
   if(isnan(humedad) || isnan(temperatura) || isnan(tempFarenheit)){
     Serial.println("Fallo la lectura del sensor");
     return;
   }

   float indice = dht.computeHeatIndex(tempFarenheit, humedad);

   
   float indiceCelsius = dht.computeHeatIndex(temperatura, humedad, false);


   Serial.print(F("Humedad: ")); 
   Serial.print(humedad);
   Serial.print(F("%  Temperatura: ")); 
   Serial.print(temperatura);
   Serial.print(F("°C  Indice de calor: ")); 
   Serial.print(indice);
   Serial.print(F("°F  Indice de calor: ")); 
   Serial.print(indiceCelsius);
   Serial.println(F("°C")); 

     WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  
  HTTPClient http; 
  
  String url = dweetIO; 
  url += "?temperatura=";
  url += String(temperatura);
  url += "&humedad=";
  url += String(humedad);

  http.begin(url); 
  int httpCode = http.GET(); 
  
  if (httpCode == HTTP_CODE_OK) { 
    String payload = http.getString(); 
    Serial.println(payload); 
  }
  else {
    Serial.println("Error solicitud HTTP");
  }
  
  http.end(); 

}