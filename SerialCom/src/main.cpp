#include <Arduino.h>
#include <iostream>
byte set2000[] = {0xA5, 0xC3, 0xD0, 0x07, 0xC1};
byte set2000_inv[sizeof(set2000)];

byte set3500[] = {0xA5, 0xC3, 0x0D, 0xAC, 0x29};
byte set3500_inv[sizeof(set3500)];

byte set0[] = {0xA5, 0xC3, 0x00, 0x00, 0x95};
byte set0_inv[sizeof(set0)];

void setup() {
  Serial.begin(600); // Inicializa a comunicação serial com uma taxa de 600 bps
  // Inverte cada byte individualmente
  for (int i = 0; i < sizeof(set2000); i++) {
    set2000_inv[i] = ~set2000[i]; // Inverte os bits do byte
    set3500_inv[i] = ~set3500[i]; // Inverte os bits do byte
    set0_inv[i] = ~set0[i]; // Inverte os bits do byte
  }


}

void loop() {
  // Envia os bytes invertidos via serial
  std::cout << "Setando para 3500" << std::endl;
  Serial.write(set3500_inv, sizeof(set3500_inv));


if (Serial.available() > 0) {
    // Lê o byte recebido
    byte dado = Serial.read();
    
    // Faz o que você quer com o dado lido, por exemplo, imprimir na porta serial
    Serial.println(dado, HEX); // Imprime o dado em hexadecimal
  }else{
    
    std::cout << "Nenhum dado disponível" << std::endl;
  }
  
  delay(2000); // Espera 2 segundos
  
  std::cout << "Esperando 10 segundos" << std::endl;
  delay(10000); // Espera 10 segundos 
  
  std::cout << "Setando para 0" << std::endl;
  Serial.write(set3500_inv, sizeof(set3500_inv));
 
  delay(2000); // Espera 2 segundos

  std::cout << "Esperando 10 segundos" << std::endl;
  delay(10000); // Espera 10 segundos 
}


