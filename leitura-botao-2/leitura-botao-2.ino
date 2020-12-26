/**
 * Teste de leitura com 2 botoes e 2 LEDs.
 */

int PINO_BOTAO = 10;
int PINO_BOTAO_2 = 9;
int PINO_LED = 13;
int PINO_LED_2 = 12;

void setup() {
  pinMode(PINO_BOTAO, INPUT);   // configura pino com botao como entrada
  pinMode(PINO_BOTAO_2, INPUT); // configura pino com botao como entrada
  pinMode(PINO_LED, OUTPUT);    // configura pino com LED como saida
  pinMode(PINO_LED_2, OUTPUT);  // configura pino com LED como saida
}

void loop() {

  if (digitalRead(PINO_BOTAO) == HIGH) { // se botao estiver pressionado
    digitalWrite(PINO_LED, HIGH); // acende o LED
  } else {
    digitalWrite(PINO_LED, LOW); // se nao estiver pressionado, apaga o LED
  }
  
  if (digitalRead(PINO_BOTAO_2) == HIGH) { // se botao estiver pressionado
    digitalWrite(PINO_LED_2, LOW); // apaga o LED
  } else {
    digitalWrite(PINO_LED_2, HIGH); // se nao estiver pressionado, acende o LED
  }

}
