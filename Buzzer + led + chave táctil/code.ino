int toqueBotao;

//7 --> LED
//5 --> Botão
//2 --> Buzzer

void setup(){
   toqueBotao = 0;
  
   pinMode(7, OUTPUT);//led
   pinMode(5, INPUT);//botão
   pinMode(5, OUTPUT);//botão
   pinMode(2, OUTPUT);//buzzer
}

void loop(){
  if(digitalRead(5) == HIGH){ //Botão clicado
    
    if(toqueBotao == 0){
      digitalWrite(7, HIGH); //Liga o Led
      tone(2, 1500); //Liga o Buzzer
      toqueBotao = 1;
    } else { //toqueBotao == 1
      digitalWrite(7, LOW); //Desliga o Led
      noTone(2); //Desliga o Buzzer
      toqueBotao = 0;
    }
    
  } else {//digitalRead(5) == FALSE ---> Botão NÃO clicado
    if(toqueBotao == 0){
      digitalWrite(7, LOW); //Led permanece desligado
      noTone(2); //Buzzer permance desligado
      toqueBotao = 0;
    } else { //toqueBotao == 1
      digitalWrite(7, HIGH); //Led permance ligado
      tone(2, 1500); //Buzzer permance ligado
      toqueBotao = 1;
    }
  }
  delay(100);
}