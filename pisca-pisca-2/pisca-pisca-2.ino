/**
 * Projeto exemplo de pisca-pisca 2.
 * Com uso de potenciometro para controlar o periodo com que um LED pisca.
 */

const int POTENCIOMETRO = A0; // pino A0 para o potenciometro
const int LED = 11; // pino 11 para o LED

//const int PERIODO = 1023;

int leitura; // variavel para leitura do ADC
int pwm; // variavel para o valor da razao ciclica (duty cicle)

void setup() {
  pinMode(POTENCIOMETRO, INPUT); // configura pino do potenciometro como entrada
  pinMode(LED, OUTPUT); // configura pino do LED como saida
  //Serial.begin(9600); // configura porta Serial a 9600 bps
}

void loop() {
  leitura = analogRead(POTENCIOMETRO); // le valor da tensao no potenciometro
  pwm = map(leitura, 0, 1023, 0, 255); // converte o valor lido no potenciometro para um valor entre 0 a 255
  analogWrite(LED, pwm);
}
