int valor;
int valorLed;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  
  valor = analogRead(A0);
  
  valorLed = map(valor, 6, 679, 0, 255);
    
  analogWrite(3, valorLed);
  
  Serial.print("Valor da Luminosidade: ");
  Serial.println(valor);
  
  Serial.print("Valor do Led: ");
  Serial.println(valorLed);
  
  Serial.println("");
  
  delay(10);
}