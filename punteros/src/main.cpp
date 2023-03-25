#include <Arduino.h>

void setup() {
  
}

int numero = 10;
int *punteroNumero = &numero;  //ACT. 2

void loop() {
  Serial.print(“En loop(): numero = “); 
  Serial.println(numero);
  duplicar( &numero ); 
}

void duplicar(int *punteroNumero) {
  *punteroNumero = *punteroNumero * 2 ;
  Serial.print(“En duplicar(): punteroNumero = “);
  Serial.println(*punteroNumero);
}