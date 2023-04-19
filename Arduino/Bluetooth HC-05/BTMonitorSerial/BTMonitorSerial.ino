/*
   Código para imprimir texto do bluetooth no Monitor Serial
*/

#include <SoftwareSerial.h> //biblioteca para comunicação UART com o HC-05

const int pinoRX = 2; //RX do Arduino - Conecte no TX do HC-05
const int pinoTX = 3; //TX do Arduino - Conecte no RX do HC-05

SoftwareSerial bluetooth(pinoRX, pinoTX); //cria uma objeto que representa o HC-05

void setup() {

  /*
     Inicializa o HC-05
     a velocidade, em bauds, depende da configuração do HC-05
     geralmente 9600 ou 38400
     para verificar, veja as instruções no arquivo BTConfig.ino, na pasta configuração
  */
  bluetooth.begin(38400);

  Serial.begin(9600);
  delay(100);
}

void loop() {
  if (bluetooth.available()) {  //se o bt está recebendo algo
    Serial.println(bluetooth.readString()); //lê a mensagem e imprime no monitor serial
  }
}
