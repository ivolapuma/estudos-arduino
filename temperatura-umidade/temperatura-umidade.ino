/**
 * Projeto exemplo de uso de componente DHT11 (medição de temperatura e umidade)
 */

#include "DHT.h"

const int pinoDHT = 9; // pino do sensor DHT

float temperatura; // armazena valor da temperatura
float umidade; // armazena valor da umidade

DHT dht(pinoDHT, DHT11); // define o pino e o tipo de DHT

void setup() {
  Serial.begin(9600); // inicia e configura a Serial a 9600 bps
  dht.begin(); // inicializa o sensor DHT
}

void loop() {
  
  delay(2000); // aguarda 2 segundos para fazer a leitura

  // a leitura da temperatura ou umidade pode levar 250 ms
  // o atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // obtem a temperatura em Celsius
  umidade = dht.readHumidity(); // obtem a umidade

  // verifica se houve falha na leitura
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do Sensor DHT");
  } else {
    // imprime valor da temperatura
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");
    Serial.print("\t"); // tabulacao
    // imprime a umidade
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %");
    Serial.print("\t"); // tabulacao
    Serial.println(); // nova linha
  }
  
}
