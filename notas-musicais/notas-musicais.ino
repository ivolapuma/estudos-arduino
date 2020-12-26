/**
 * Teste com buzzer passivo.
 * Geracao de notas musicais.
 */


const byte PINO_BUZZER = 10;

const int C = 261; // nota DO
const int D = 293; // nota RE
const int E = 329; // nota MI
const int F = 349; // nota FA
const int G = 391; // nota SOL
const int A = 440; // nota LA
const int B = 493; // nota SI

void setup() {
  pinMode(PINO_BUZZER, OUTPUT); // configura pino buzzer como saida
}

void loop() {
  tocar(PINO_BUZZER, C, 1000);
  tocar(PINO_BUZZER, D, 1000);
  tocar(PINO_BUZZER, E, 1000);
  tocar(PINO_BUZZER, F, 1000);
  tocar(PINO_BUZZER, G, 1000);
  tocar(PINO_BUZZER, A, 1000);
  tocar(PINO_BUZZER, B, 1000);
  desligar(PINO_BUZZER, 3000);
}

void tocar(byte pino, int frequencia, int tempo) {
  tone(pino, frequencia);
  delay(tempo);
}

void desligar(byte pino, int tempo) {
  noTone(pino);
  delay(tempo);
}
