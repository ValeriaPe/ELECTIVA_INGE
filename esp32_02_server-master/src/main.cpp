#include <Arduino.h>
#include "libwifi.h"
#include <WiFi.h>
 
const char * ssid = "covid";
const char * password = "abc12345";
const int puerto = 80;
WiFiServer servidor(puerto);  //ACT. 6

/**
 * @brief 
 * 
 */
void setup() {
  pinMode(2, OUTPUT);  
  Serial.begin(115200);
  Serial.println("Inicializando dispositivo");
  conectarWifi(ssid, password);
  servidor.begin();  
}


/**
 * @brief 
 * 
 */
void loop() {

  WiFiClient cliente = servidor.available(); 

  if(cliente){  
    String mensaje="";
    Serial.println("Se conecto un cliente");
    while(cliente.connected()){  
       if(cliente.available()){ 
        char letra = cliente.read();  
        Serial.print(letra);
        if(letra == '\n'){  
          if(mensaje.length()==0){            
              cliente.println("HTTP/1.1 200 OK");
              cliente.println("Content-type:text/html");
              cliente.println();   

              cliente.println("Haga clic <a href=\"/H\">aqui</a> para encender el LED <br>");
              cliente.println("Haga clic  <a href=\"/L\">aqui</a> para apagar el LED");
              cliente.println();  
              break;
          } else {
            mensaje="";
          }
        } else if (letra != '\r'){
             mensaje+=letra;  
        }

        if(mensaje.endsWith("GET /H")){
           digitalWrite(2, HIGH);
        }
        else if(mensaje.endsWith("GET /L")){   
          digitalWrite(2, LOW);
        }
       }
    }
    Serial.println("Cerrando conexion");
    cliente.stop();
  }
}
