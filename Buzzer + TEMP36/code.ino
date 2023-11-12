int var;
int varTemp;

void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT); //Temperatura
  pinMode(2, OUTPUT); //Buzzer
}

void loop(){
  var = analogRead(A5);  
  
  varTemp = map(var, 20, 358, -40, 125);
  
  Serial.print("Temperatura: ");
  Serial.println(varTemp);
  
  if(varTemp > 30) { //Se a temperatura for maior que 30º o buzzer é acionado
    tone(2, 1500, 1000);    
  } else {
    noTone(2);
  }  
  delay(100);
}