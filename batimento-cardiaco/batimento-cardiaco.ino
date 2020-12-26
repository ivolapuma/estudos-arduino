/*
 * Teste de piscagem de LED no pino 13 do UNO
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // simulacao do batimento cardiaco: 1 batida = LED aceso
  int pausa_rapida = 100;
  int pausa_lenta = 400;
  //int pausa_lenta = calcula_pausa_lenta(80);
  batida_coracao(pausa_rapida, pausa_lenta);
}

int calcula_pausa_lenta(int batimentos_minuto) {
  float batida = 60.0 / (float) batimentos_minuto;
  batida = batida * 100.0;
  batida = batida - 100.0;
  int retorno = (int) batida;
  return retorno;
}

void batida_coracao(int pausa_rapida, int pausa_lenta) {
  acende_led(pausa_rapida);
  apaga_led(pausa_rapida);
  acende_led(pausa_rapida);
  apaga_led(pausa_lenta);
}

void acende_led(int milisec) {
  digitalWrite(LED_BUILTIN, HIGH);  // acende LED
  delay(milisec);                 // delay minimo  
}

void apaga_led(int milisec) {
  digitalWrite(LED_BUILTIN, LOW);   // apaga LED
  delay(milisec);                 // delay minimo  
}
