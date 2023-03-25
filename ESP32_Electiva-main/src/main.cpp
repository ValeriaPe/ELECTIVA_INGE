#include <Arduino.h>
#include <WiFi.h>

const char * ssid = "covid";
const char * password = "abc12345"; //ACT.3

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando red WiFi...");
  }

  Serial.println("Conectada a red Wifi.");

  int numero = 10;
  int *puntero = &numero;

  Serial.print("Valor: ");
  Serial.println(numero);



  Serial.print("Dirección de memoria puntero: ");
  Serial.printf("%p\n", (void*)puntero);

  Serial.print("Valor de *puntero: ");
  Serial.println(*puntero);
}

void loop() {
  
}