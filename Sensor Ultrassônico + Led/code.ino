// FUNÇÃO DO SENSOR DISTÂNCIA
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

void setup(){
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (0.01723 * readUltrasonicDistance(10, 8) < 50) { //Quando estiver mt próximo --> Acende pino vermelho
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  } else if (0.01723 * readUltrasonicDistance(10, 8) < 100) { //Quando estiver distância média --> Acende pino amarelo
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  } else { //Quando estiver distante --> Acende pino verde
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
  Serial.print(0.01723 * readUltrasonicDistance(10, 8));
  Serial.println(" cm");
  delay(10); // Delay a little bit to improve simulation performance
}