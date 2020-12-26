/**
 * Teste de geração de barulho com componente buzzer passivo e dois botoes.
 */

const byte PINO_BUZZER = 12;
const byte PINO_BOTAO_MAIS = 11;
const byte PINO_BOTAO_MENOS = 10;
const int TEMPO = 1000;

int frequencia = 400;

void setup() {
  pinMode(PINO_BUZZER, OUTPUT); // configura pino buzzer como saida
  pinMode(PINO_BOTAO_MAIS, INPUT_PULLUP); // configura pino botao como entrada (INPUT) e habilita um resistor interno no chip (PULLUP)
  pinMode(PINO_BOTAO_MENOS, INPUT_PULLUP); // configura pino botao como entrada (INPUT) e habilita um resistor interno no chip (PULLUP)
}

void loop() {
  if (digitalRead(PINO_BOTAO_MAIS) == LOW) { // se botao estiver pressionado, vai retornar LOW devido a ser PULLUP
    frequencia += 100;
  }
  if (digitalRead(PINO_BOTAO_MENOS) == LOW) { // se botao estiver pressionado, vai retornar LOW devido a ser PULLUP
    frequencia -= 100;
  }
  tone(PINO_BUZZER, frequencia); // gera frequencia no buzzer
  delay(TEMPO);
  noTone(PINO_BUZZER); // interrompe frequencia no buzzer
  delay(TEMPO);
}
