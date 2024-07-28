#include <SPI.h>
#include <MFRC522.h>


#define led1 2 //LED VERMELHO
#define led2 3 //LED AMARELO
#define led3 4 //LED VERDE
int buzzer = 6; //BUZZER
#define RST_PIN 9
#define SS_PIN 10

MFRC522 leitor(SS_PIN, RST_PIN);  // Cria a instancia do MFRC522

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  SPI.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  leitor.PCD_Init();    // Inicia o modulo MFRC522
  Serial.println("Aproxime seu cartão: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  // int valor_som = analogRead(A0);
  int tempo = 2000;

  if(! leitor.PICC_IsNewCardPresent()){
    digitalWrite(led1, HIGH);
    Serial.println("Nenhum card");
    return;
  }

  if(! leitor.PICC_ReadCardSerial()){
    Serial.print("Erro ao ler cartao/tag");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzer, 150, 100);
    delay(140);
    tone(buzzer, 150, 100);
    delay(tempo);
    digitalWrite(led2, LOW);
    return;
  }
  
  digitalWrite(led1, LOW);
  digitalWrite(led3, HIGH);
  for (byte i = 0; i < leitor.uid.size; i++)
  {
    Serial.print(leitor.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println(" ");
  tone(buzzer, 250);
  delay(100);
  tone(buzzer, 740,100);
  delay(tempo);
  digitalWrite(led3, LOW);

  //Serial.println("\nID da Tag: ");
  //String conteudo = "";
  //byte letra;

  //for (byte i=0;i<leitor.uid.size; i++){
  //  //Serial.print(leitor.uid.uidByte[i] < 0x10 ? "0":"");
  //  Serial.print(leitor.uid.uidByte[i], HEX);
  //  //conteudo.concat(String(leitor.uid.uidByte[i] < 0x10 ? "0":""));
  //  conteudo.concat(String(leitor.uid.uidByte[i], HEX));
  //}
//
  //delay(tempo);
  //
  //if(conteudo.substring(1) == "7395CC13" ){
  //  Serial.print("Bem vindo tag");
  //  digitalWrite(led1, HIGH);
  //  delay(tempo);
  //  digitalWrite(led1, LOW);
  //  return;
  //}
}

void cartao_lido(bool lido){
  bool cartaolido = lido;
  return cartaolido;

}










