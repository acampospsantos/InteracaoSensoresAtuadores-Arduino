void setup(){
  pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(2, INPUT);

  digitalWrite(10, HIGH);
  digitalWrite(2, LOW);
  delay(700); // Wait for 700 millisecond(s)
}

void loop(){
  if (digitalRead(2) == HIGH) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}