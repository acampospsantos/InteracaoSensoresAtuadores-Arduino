#include <SoftwareSerial.h> //Biblioteca para conectar com o bluetooth (já vem instalado), não precisa baixar

SoftwareSerial serialdobluetooth(8, 9); // Portas para o serial do bluetooth (RX, TX)

int valordobluetooth; // Variável que vai ler o valor enviado pelo bluetooth

// Definição dos pinos dos leds
#define led1 4
#define led2 5
#define led3 6


void setup() {
  serialdobluetooth.begin(9600); //Início da serial do bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  //Garantir que os LEDs estejam desligados no início do programa
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  if (serialdobluetooth.available()) { //Se o bluetooth estiver funcionando, vai ser lido o "valor", para reproduzir o comando
    valordobluetooth = serialdobluetooth.read();
  }

  if (valordobluetooth == 'A') { //Leitura dos valores para saber se deve acender ou não o LED
    digitalWrite (led1, HIGH);
  }
  if (valordobluetooth == 'a') {
    digitalWrite (led1, LOW);
  }

  if (valordobluetooth == 'B') {
    digitalWrite (led2, HIGH);
  }
  if (valordobluetooth == 'b') {
    digitalWrite (led2, LOW);
  }

  if (valordobluetooth == 'C') {
    digitalWrite (led3, HIGH);
  }
  if (valordobluetooth == 'c') {
    digitalWrite (led3, LOW);
  }

  if (valordobluetooth == 'D') {
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);
    delay(350);
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    delay(350);
  }
  if (valordobluetooth == 'd') {
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
  }
}