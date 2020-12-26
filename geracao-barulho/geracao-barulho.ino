/**
 * Teste de geração de barulho com componente buzzer passivo.
 */

byte PINO_BUZZER = 12;
int FREQUENCIA = 2000;
int TEMPO = 1000;

void setup() {
  pinMode(PINO_BUZZER, OUTPUT); // configura pino buzzer como saida
}

void loop() {
  tone(PINO_BUZZER, FREQUENCIA); // gera frequencia no buzzer
  delay(TEMPO);
  noTone(PINO_BUZZER); // interrompe frequencia no buzzer
  delay(TEMPO);
}
