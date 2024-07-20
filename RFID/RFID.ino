#include <SPI.h>
#include <MFRC522.h>


#define led1 2 //VERMELHO
#define led2 3 //AMARELO
#define led3 4 //VERDE
#define SS_PIN 10
#define RST_PIN 9

MFRC522 leitor(SS_PIN, RST_PIN);  // Cria a instancia do MFRC522

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  SPI.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  leitor.PCD_Init();    // Inicia o modulo MFRC522
  Serial.println("Aproxime seu cartão: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  // int valor_som = analogRead(A0);
  int tempo = 2000;

  if(! leitor.PICC_IsNewCardPresent()){
    return;
  }

  if(! leitor.PICC_ReadCardSerial()){
    return;
  }

  Serial.println("\nID da Tag: ");
  String conteudo = "";
  byte letra;

  for (byte i=0;i<leitor.uid.size; i++){
    //Serial.print(leitor.uid.uidByte[i] < 0x10 ? "0":"");
    Serial.print(leitor.uid.uidByte[i], HEX);
    //conteudo.concat(String(leitor.uid.uidByte[i] < 0x10 ? "0":""));
    conteudo.concat(String(leitor.uid.uidByte[i], HEX));
  }

  delay(tempo);
  
  if(conteudo.substring(1) == "7395CC13" ){
    Serial.print("Bem vindo tag");
    digitalWrite(led1, HIGH);
    delay(tempo);
    digitalWrite(led1, LOW);
    return;
  }
}

void cartao_lido(bool lido){
  bool cartaolido = lido;
  return cartaolido;

}










