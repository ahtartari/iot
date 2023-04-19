/*
   Código para imprimir texto do bluetooth no display LCD I2C
*/

#include <LiquidCrystal_I2C.h>  //adicionar no gerenciador de bibliotecas
#include <SoftwareSerial.h> //biblioteca para comunicação UART com o HC-05
#include <Wire.h>

const int pinoRX = 2; //RX do Arduino - Conecte no TX do HC-05
const int pinoTX = 3; //TX do Arduino - Conecte no RX do HC-05

SoftwareSerial bluetooth(pinoRX, pinoTX); //cria uma objeto que representa o HC-05
LiquidCrystal_I2C lcd(0x27, 20, 4); //cria uma objeto que representa o LCD
void setup() {

  /*
     Inicializa o HC-05
     a velocidade, em bauds, depende da configuração do HC-05
     geralmente 9600 ou 38400
     para verificar, veja as instruções no arquivo BTConfig.ino, na pasta configuração
  */
  bluetooth.begin(38400);

  Serial.begin(9600);

  lcd.init();  // inicializa o LCD
  lcd.backlight();  // liga a luz do LCD
  lcd.clear();  // limpa o LCD
  lcd.setCursor(0, 0);  // coloca o cursor na primeira posição do LCD
  lcd.print("Olá, tudo bem?");  // imprime um texto inicial no LCD

  delay(100);
}

void loop() {
  if (bluetooth.available()) {  //se o bt está recebendo algo
    String msg = bluetooth.readString();  //lê a mensagem que vem do bt
    lcd.clear();  // limpa o LCD
    lcd.setCursor(0, 0);  // coloca o cursor na primeira posição do LCD
    lcd.print(msg);  //imprime a mensagem no LCD
    Serial.println(msg);  //imprime no monitor serial
  }
}
