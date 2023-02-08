void setup(){
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(1, OUTPUT);

  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(1, HIGH);
}

void loop(){
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  digitalWrite(1, HIGH);
  delay(600); // Wait for 600 millisecond(s)
}