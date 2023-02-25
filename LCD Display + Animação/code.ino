// C++ code
//
#include <LiquidCrystal.h>

//Criei objeto --> Passando pinos q o display tá conectado
LiquidCrystal lcd(7,6,5,4,3,2);

void setup(){
  lcd.begin(16, 2);//Configura o modelo do display em nosso caso 16×2 --> Passo quantas colunas e linhas tem o Display
  lcd.clear(); //Comando pra limpar a tela
}

void loop(){
  //Posiciona o cursor na coluna e linha indicada no comando
  lcd.setCursor(5,0); //Setta texto - coluna x linha
  lcd.print("hello,"); //imprime o texto que vai ser expresso
  
  lcd.setCursor(5,1); //Setta texto - coluna x linha
  lcd.print("world!"); //imprime o texto que vai ser expresso
  
  delay(2000); // Delay a little bit to improve simulation performance

  
  //Esse for faz uma ilusão de animação 
  for(int pos=0; pos<5; pos++){ //Texto vai todo pro lado esquerdo
    lcd.scrollDisplayLeft(); //Move o conteúdo do display (texto+cursor) um espaço para a esquerda
    delay(100);
  }
  for(int pos=0; pos<10; pos++){ ////Texto vai todo pro lado direito
    lcd.scrollDisplayRight(); //Move o conteúdo do display (texto+cursor) um espaço para a direita
    delay(100);
  }
  for(int pos=0; pos<5; pos++){ //Texto volta pro meio do display
    lcd.scrollDisplayLeft(); //Move o conteúdo do display (texto+cursor) um espaço para a esquerda
    delay(100);
  }
  delay(1000);  
  
  //Vai fazer o LCD piscar 3 vezes
  lcd.noDisplay(); //Desliga o display sem perder os dados exibidos
  delay(500);
  lcd.display(); //Liga o display e restaura o texto escrito após comando “noDisplay()”
  delay(500);
  
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
}