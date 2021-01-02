/**
 * Projeto exemplo para sensor de luz (LDR, Light-Dependent Resistor).
 * 
 * Exercício
 * Monte um sensor de luminosidade que, ao invés de exibir os valores no monitor serial, mostra o valor lido por meio de LEDs. 
 * Você pode usar diferentes cores para reprensentar diferentes níveis de luminosidade.
 */

#include <math.h>

const int LDR          = A0;  // pino do LDR
const int LED_BRANCO   = 13;  // pino do LED branco
const int LED_VERDE    = 12;  // pino do LED verde
const int LED_AMARELO  = 11;  // pino do LED amarelo
const int LED_VERMELHO = 10;  // pino do LED vermelho 

const int INTERVALO_LEITURA = 1000;  // em milissegundos

int leituraADC = 0;     // valor lido pelo ADC (conversor análogico-digital)
float tensaoADC = 0.0;  // tensao calculada
int leitura0a10 = 0;   // conversao da leitura do ADC (0 a 10)

void setup() {
  // inicia e configura a Serial
  Serial.begin(9600); // 9600 bps

  // configura os pino com LDR e LED
  pinMode(LDR, INPUT);
  pinMode(LED_BRANCO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  leituraADC = analogRead(LDR); // le o valor de tensao no pino do LDR
  tensaoADC = calculaTensao(leituraADC);
  leitura0a10 = converteRange0a10(leituraADC);
  acendeLeds(leitura0a10, LED_BRANCO, LED_VERDE, LED_AMARELO, LED_VERMELHO);
  log_serial(leituraADC, tensaoADC, leitura0a10);
  delay(INTERVALO_LEITURA);
}

void acendeLeds(int valor, int led4, int led3, int led2, int led1) {

  boolean liga1 = false;
  boolean liga2 = false;
  boolean liga3 = false;
  boolean liga4 = false;
  
  switch (valor) {
    case 10:
      liga4 = true;
      liga3 = true;
      liga2 = true;
      liga1 = true;
      break;
    case 9:
      liga4 = true;
      liga3 = true;
      liga2 = true;
      liga1 = false;
      break;
    case 8:
      liga4 = true;
      liga3 = true;
      liga2 = false;
      liga1 = true;
      break;
    case 7:
      liga4 = true;
      liga3 = true;
      liga2 = false;
      liga1 = false;
      break;
    case 6:
      liga4 = true;
      liga3 = false;
      liga2 = true;
      liga1 = false;
      break;
    case 5:
      liga4 = true;
      liga3 = false;
      liga2 = false;
      liga1 = true;
      break;
    case 4:
      liga4 = true;
      liga3 = false;
      liga2 = false;
      liga1 = false;
      break;
    case 3:
      liga4 = false;
      liga3 = true;
      liga2 = false;
      liga1 = false;
      break;
    case 2:
      liga4 = false;
      liga3 = false;
      liga2 = true;
      liga1 = false;
      break;
    case 1:
      liga4 = false;
      liga3 = false;
      liga2 = false;
      liga1 = true;
      break;
    default:
      liga4 = false;
      liga3 = false;
      liga2 = false;
      liga1 = false;
  }

  if (liga4) digitalWrite(led4, HIGH); else digitalWrite(led4, LOW);
  if (liga3) digitalWrite(led3, HIGH); else digitalWrite(led3, LOW);
  if (liga2) digitalWrite(led2, HIGH); else digitalWrite(led2, LOW);
  if (liga1) digitalWrite(led1, HIGH); else digitalWrite(led1, LOW);
}

/**
 * Converte o valor da leitura ADC em tensao eletrica (V)
 */
float calculaTensao(int valor) {
  return valor * 5.0 / 1024.0;
}

/**
 * Converte o valor da leitura ADC proporcionalmente num numero entre 0 a 10.
 */
int converteRange0a10(int valor) {
  if (valor <= 0) return 0;
  return floor(valor * 10 / 1024) + 1;
}

/**
 * Envia log para porta Serial.
 */
void log_serial(int leitura, float tensao, int conversao) {
  Serial.print("leitura=");
  Serial.print(leitura);
  Serial.print("\t"); // TAB

  Serial.print("tensao=");
  Serial.print(tensao);
  Serial.print("V");
  Serial.print("\t"); // TAB

  Serial.print("conversao=");
  Serial.print(conversao);

  Serial.println(); // nova linha 
}
