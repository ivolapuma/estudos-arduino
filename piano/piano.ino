/**
 * Geracao de notas musicais em buzzer de acordo com botoes pressionados.
 */

// pinos dos componentes
const byte BUZZER = 10;
const byte LED_VERMELHO = 13;
const byte LED_AMARELO = 12;
const byte LED_VERDE = 11;
const byte BOTAO_1 = 9;
const byte BOTAO_2 = 8;
const byte BOTAO_3 = 7;

// frequencia das notas musicais
const int C = 261; // nota DO
const int D = 293; // nota RE
const int E = 329; // nota MI
const int F = 349; // nota FA
const int G = 391; // nota SOL
const int A = 440; // nota LA
const int B = 493; // nota SI

void setup() {
  pinMode(BUZZER, OUTPUT); // configura pino buzzer como saida
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BOTAO_1, INPUT_PULLUP);
  pinMode(BOTAO_2, INPUT_PULLUP);
  pinMode(BOTAO_3, INPUT_PULLUP);
}

void loop() {

  // obtem status dos botoes
  boolean statusBotao1 = digitalRead(BOTAO_1);
  boolean statusBotao2 = digitalRead(BOTAO_2);
  boolean statusBotao3 = digitalRead(BOTAO_3);

  if (statusBotao1 == LOW) {
    tocar(BUZZER, C, 0);
    acendeLedVermelho();
  } else if (statusBotao2 == LOW) {
    tocar(BUZZER, D, 0);
    acendeLedAmarelo();    
  } else if (statusBotao3 == LOW) {
    tocar(BUZZER, E, 0);
    acendeLedVerde();        
  } else {
    desligar(BUZZER, 0);
    apagaTodosLeds();
  }
  
}

void tocar(byte pino, int frequencia, int tempo) {
  tone(pino, frequencia);
  delay(tempo);
}

void desligar(byte pino, int tempo) {
  noTone(pino);
  delay(tempo);
}

void acendeLedVermelho() {
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

void acendeLedAmarelo() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, LOW);
}

void acendeLedVerde() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
}

void apagaTodosLeds() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
}
