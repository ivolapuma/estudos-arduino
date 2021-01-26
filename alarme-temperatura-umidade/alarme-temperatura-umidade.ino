/**
 * Projeto exemplo de alarme com sensor de temperatura e umidade (DHT11).
 */

#include "DHT.h" // inclui a biblioteca com funcoes dos sensores tipo DHT

// definicao dos pinos dos componentes
const int SENSOR_DHT = 9; // DHT
const int LED_R = 11; // LED RGB vermelho
const int LED_G = 12; // LED RGB verde
const int LED_B = 13; // LED RGB azul
const int BUZZER = 10; // componente buzzer

// variaveis para armazenar temperatura e umidade
float temperatura;
float umidade;

DHT dht(SENSOR_DHT, DHT11); // define o pino e o tipo de DHT

void setup() {
  Serial.begin(9600); // inicia e configura a Serial a 9600 bps
  dht.begin(); // inicializa o sensor DHT
  // configura os pinos dos LEDs e buzzer
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BUZZER, OUTPUT);
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
    // acende LED branco
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
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
    if (temperatura > 35 || temperatura < 15) {
      // acende LED vermelho e aciona buzzer a 2000 Hz
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
      tone(BUZZER, 2000);
      delay(1000);
    } else if (temperatura > 30 || temperatura < 20) {
      // acende LED azul e aciona buzzer a 1000 Hz
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
      tone(BUZZER, 1000);
      delay(500);
    } else {
      // acende LED verde
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);      
    }
    // desliga buzzer
    noTone(BUZZER);
  }
}
