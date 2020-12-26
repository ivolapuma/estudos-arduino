/**
 * Geracao de notas musicais de Asa Branca, de Luiz Gonzaga
 */

const byte BUZZER = 10;
const byte BOTAO = 9;

const int C = 261; // nota DO
const int D = 293; // nota RE
const int E = 329; // nota MI
const int F = 349; // nota FA
const int G = 391; // nota SOL
const int A = 440; // nota LA
const int B = 493; // nota SI

const int TEMPO = 1000;

int notas[] = {
  C, D, E, G, G, E, F, F, 0, C, D, E, G, G, F, E, 0, C, C, D, E, G, 0, G, F, E, C, F, 0, F, E, D, D, E, 0, D, D, C, C, 0
};

int tempos[] = {
  4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 1, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 1, 1
};

int i;

const int TAMANHO = 40;

void setup() {
  pinMode(BUZZER, OUTPUT); 
  pinMode(BOTAO, INPUT_PULLUP);
  for (i = 0; i < TAMANHO; i++) {
    tempos[i] = TEMPO / tempos[i];
  }
}

void loop() {
  boolean statusBotao = digitalRead(BOTAO);
  if (statusBotao == LOW) {
    for (i = 0; i < TAMANHO; i++) {
      if (notas[i] == 0) {
        noTone(BUZZER);
      } else {
        tone(BUZZER, notas[i]);
      }
      delay(tempos[i]);
    }
  }
  
}
