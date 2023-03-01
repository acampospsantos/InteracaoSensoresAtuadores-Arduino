// C++ code
//

#include <Servo.h> //Biblioteca do Servo

Servo servo1; //Objeto criado da biblioteca do Servo

//Função do Sensor de Distância
long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int var;
int varTemp;
int angulo;

void setup(){
  pinMode(4, OUTPUT); //Led do sensor distância
  pinMode(6, OUTPUT); //Led do Sensor temperatura
  pinMode(2, OUTPUT); //Buzzer
  pinMode(A5, INPUT); //Temperatura

  servo1.attach(7, 500, 2500); //Define que o Servo está conectado a Porta 7
}

void loop(){
  //INTERAÇÃO SENSOR DE DISTÂNCIA E LED
  if (0.01723 * readUltrasonicDistance(10, 9) < 100) { //unidade cm
    digitalWrite(4, HIGH);
     angulo = 90;
    servo1.write(angulo);
  } else {
    digitalWrite(4, LOW);
    angulo = 0;
    servo1.write(angulo);
  }
  
  //INTERAÇÃO SENSOR DE TEMPERATURA + BUZZER E LED
  var = analogRead(A5);  
  varTemp = map(var, 20, 358, -40, 125);
  if(varTemp > 30) {
    tone(2, 1500, 1000);    
    digitalWrite(6, HIGH);
  } else {
    noTone(2);
    digitalWrite(6, LOW);
  }  
  
  delay(100); // Delay a little bit to improve simulation performance
}