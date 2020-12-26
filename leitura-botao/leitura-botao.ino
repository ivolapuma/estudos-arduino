/**
 * Teste de leitura de um botao.
 */

int PINO_BOTAO = 9;
int PINO_LED = 12;

void setup() {
  pinMode(PINO_BOTAO, INPUT); // configura o pino com o botao como entrada
  pinMode(PINO_LED, OUTPUT); // configura o pino com o LED como saida
}

void loop() {
  if (digitalRead(PINO_BOTAO) == HIGH) { // se botao estiver pressionado
    digitalWrite(PINO_LED, HIGH); // acende o LED
  } else {
    digitalWrite(PINO_LED, LOW); // se nao estiver pressionado, apaga o LED
  }
}
