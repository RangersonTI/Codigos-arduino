#include <SPI.h>


#define led1 2
#define led2 3
#define led3 4

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int valor_som = analogRead(A0);
  int tempo = 150;

  //digitalWrite(led2, valor_som > 30);
  //digitalWrite(led1, valor_som > 10);
  digitalWrite(led1, HIGH);
  //digitalWrite(led3, valor_som > 50);
  delay(tempo);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(tempo);
  digitalWrite(led2, LOW);
  
  //digitalWrite(led3, HIGH);
  //delay(tempo);
  //delay(tempo);
  //digitalWrite(led3, LOW);
  
}
