#include <Arduino.h>

/**
 * @brief 
 * 
 */
void setup() {
  pinMode(2, OUTPUT);  //ACT. 1
}


/**
 * @brief 
 * 
 */
void loop() {
  digitalWrite(2,HIGH);  
  delay(500);  
  digitalWrite(2,LOW); 
  delay(500);  
}