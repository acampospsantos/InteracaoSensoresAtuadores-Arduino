int var;
int varTemp;

void setup(){
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(A0, INPUT); //Pino temperatura
}

void loop(){
  var = analogRead(A0);
  
  varTemp = map(var, 20, 358, -40, 125);
  
  //FAZER if de cada led 
  if(varTemp < -15){ //1º led
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if (varTemp < 10) { //2º led
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if(varTemp < 35) { //3º led
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if (varTemp < 60) { //4º led
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  } else if (varTemp < 85) { //5º led
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  } else { //varTemp => 85  //6º led
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
  
  Serial.print("Sensor Temperatura: ");
  Serial.println(analogRead(A0));
  Serial.print("Temperatura: ");
  Serial.println(varTemp);
  Serial.println("");
  
   
   delay(100);
}