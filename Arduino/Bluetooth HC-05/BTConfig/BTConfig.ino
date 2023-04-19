/*
 *  Código para configurar o HC-05 com códigos AT
 *  Certifique-se que o pino EN do HC-05 está conectado no 3.3v
 *  
 *  Comandos AT úteis:
 *  Verificar nome: AT+NAME
 *  Verificar senha: AT+PSWD
 *  Mudar nome: AT+NAME=novonome
 *  Verificar velocidade do UART: AT+UART
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
  Serial.println("Comando AT:");
  delay(100);
}

void loop() {
  if (bluetooth.available()) {  //se o bt está recebendo algo
    Serial.write(bluetooth.read()); //envia a mensagem lida para o monitor serial
  }

  if (Serial.available()) { //se o monitor serial está recebendo algo
    bluetooth.write(Serial.read());  //envia a mensagem digitada para o bt
  }
}
