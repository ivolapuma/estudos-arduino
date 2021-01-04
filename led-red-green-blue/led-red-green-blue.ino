/**
 * Projeto exemplo para uso do LED RGB.
 * Aciona as três cores do LED RGB atraves de botoes.
 */

// definicao dos pinos
const int LED_R = 11;
const int LED_G = 10;
const int LED_B = 9;

const int BOTAO_R = 7;
const int BOTAO_G = 6;
const int BOTAO_B = 5;

// variaveis para armazenar estados dos botoes
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BOTAO_R, INPUT_PULLUP);
  pinMode(BOTAO_G, INPUT_PULLUP);
  pinMode(BOTAO_B, INPUT_PULLUP);
}

void loop() {
  leituraBotaoR = digitalRead(BOTAO_R);
  leituraBotaoG = digitalRead(BOTAO_G);
  leituraBotaoB = digitalRead(BOTAO_B);

  // se botao R pressionado (LOW), liga led Red, senao, apaga
  if (leituraBotaoR == LOW) analogWrite(LED_R, 255); else analogWrite(LED_R, 0);
  // se botao G pressionado (LOW), liga led Green, senao, apaga
  if (leituraBotaoG == LOW) analogWrite(LED_G, 255); else analogWrite(LED_G, 0);
  // se botao B pressionado (LOW), liga led Blue, senao, apaga
  if (leituraBotaoB == LOW) analogWrite(LED_B, 255); else analogWrite(LED_B, 0);

  delay(100); // aguarda .1 segundo para a proxima leitura
}
