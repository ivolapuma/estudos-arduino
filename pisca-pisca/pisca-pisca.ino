/**
 * Projeto exemplo de pisca-pisca.
 * Com uso de potenciometro para controlar o periodo com que um LED pisca.
 */

const int POTENCIOMETRO = A0; // pino A0 para o potenciometro
const int LED = 12; // pino 12 para o LED
const int PERIODO = 1023;

int tempoLigado; // variavel para controlar o tempo que o LED fica ligado
int tempoDesligado; // variavel para controlar o tempo que o LED fica desligado

void setup() {
  pinMode(POTENCIOMETRO, INPUT); // configura pino do potenciometro como entrada
  pinMode(LED, OUTPUT); // configura pino do LED como saida
  Serial.begin(9600); // configura porta Serial a 9600 bps
}

void loop() {
  tempoLigado = analogRead(POTENCIOMETRO); // le valor da tensao no potenciometro (eh o tempo que o LED deve ficar ligado)
  tempoDesligado = PERIODO - tempoLigado; // calcula o tempo que o LED deve ficar desligado)

  digitalWrite(LED, HIGH); // liga o LED
  delay(tempoLigado);
  //delayMicroseconds(tempoLigado);

  digitalWrite(LED, LOW); // desliga o LED
  delay(tempoDesligado);
  //delayMicroseconds(tempoDesligado);

  // envia para Serial os valores de tempo ligado/desligado
  Serial.print(tempoLigado);
  Serial.print(" ");
  Serial.print(tempoDesligado);
  Serial.println();
}
