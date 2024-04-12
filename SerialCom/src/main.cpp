#include <Arduino.h>
#include <iostream>


/*/ put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(600);

}

void loop() {
  // put your main code here, to run repeatedly:
  std::cout << Serial.available();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
*/

void setup() {
  // Inicializa a comunicação serial com uma taxa de transmissão de 115200 bps
  Serial.begin(115200);
}

void loop() {
  static String mensagemRecebida = ""; // Variável para armazenar a mensagem recebida
  static bool aguardandoEntrada = false; // Variável para controlar se estamos aguardando uma entrada
  
  // Se houver dados disponíveis para leitura do Serial Monitor
  if (Serial.available() > 0) {
    char caractere = Serial.read(); // Lê o próximo caractere recebido
    
    // Se o caractere recebido for uma nova linha ('\n'), indica que o usuário pressionou "Enter"
    if (caractere == '\n') {
      // Imprime a mensagem recebida no Serial Monitor
      Serial.print("Mensagem recebida: ");
      Serial.println(mensagemRecebida);
      
      // Limpa a variável de mensagem recebida
      mensagemRecebida = "";
      
      // Indica que não estamos mais aguardando uma entrada
      aguardandoEntrada = false;  
    } else {
      // Adiciona o caractere recebido à mensagem
      mensagemRecebida += caractere;
      
      // Indica que estamos aguardando uma entrada
      aguardandoEntrada = true;
    }
  }
  
  // Outras operações do loop
}
