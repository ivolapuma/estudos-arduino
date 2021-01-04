/**
 * Projeto exemplo de pixel com LED RGB.
 * Aciona e ajusta a intensidade de um LED RGB atraves de botoes e potenciometro.
 */

// definicao dos pinos
const int LED_R = 11;
const int LED_G = 10;
const int LED_B = 9;

const int BOTAO_R = 7;
const int BOTAO_G = 6;
const int BOTAO_B = 5;
const int BOTAO_AJUSTE = 4;

const int POTENCIOMETRO = A0;

// variaveis para armazenar estados dos botoes
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;
int leituraBotaoAjuste;
int leituraPotenciometro;
// variaveis para armazenar intensidade dos leds (pwm)
int pwmR;
int pwmG;
int pwmB;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BOTAO_R, INPUT_PULLUP);
  pinMode(BOTAO_G, INPUT_PULLUP);
  pinMode(BOTAO_B, INPUT_PULLUP);
  pinMode(BOTAO_AJUSTE, INPUT_PULLUP);
  pinMode(POTENCIOMETRO, INPUT);

  Serial.begin(9600);
}

void loop() {
  
  leituraBotaoR = digitalRead(BOTAO_R);
  leituraBotaoG = digitalRead(BOTAO_G);
  leituraBotaoB = digitalRead(BOTAO_B);
  
  leituraBotaoAjuste = digitalRead(BOTAO_AJUSTE);

  leituraPotenciometro = analogRead(POTENCIOMETRO);

  // se botao R pressionado (LOW), liga led Red, senao, apaga
  if (leituraBotaoR == LOW) {
    // se botao Ajuste pressionado, muda intensidade do led
    if (leituraBotaoAjuste == LOW) pwmR = map(leituraPotenciometro, 0, 1023, 0, 255);
    analogWrite(LED_R, pwmR);
  } else {
    analogWrite(LED_R, 0);
  }
  
  // se botao G pressionado (LOW), liga led Green, senao, apaga
  if (leituraBotaoG == LOW) {
    // se botao Ajuste pressionado, muda intensidade do led
    if (leituraBotaoAjuste == LOW) pwmG = map(leituraPotenciometro, 0, 1023, 0, 255);
    analogWrite(LED_G, pwmG);
  } else {
    analogWrite(LED_G, 0);
  }
  
  // se botao B pressionado (LOW), liga led Blue, senao, apaga
  if (leituraBotaoB == LOW) {
    // se botao Ajuste pressionado, muda intensidade do led
    if (leituraBotaoAjuste == LOW) pwmB = map(leituraPotenciometro, 0, 1023, 0, 255);
    analogWrite(LED_B, pwmB);
  } else {
    analogWrite(LED_B, 0);
  }

  logSerial(leituraPotenciometro, pwmR, pwmG, pwmB);

  delay(100); // aguarda .1 segundo para a proxima leitura
}

void logSerial(int pot, int r, int g, int b) {
  Serial.print(b);
  Serial.print(" ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print(pot);
  Serial.println();
}
