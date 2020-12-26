/**
 * Projeto de um semáforo de carros e pedestres.
 * v2 - Na fase fechando, o LED vermelho do pedestre vai piscar.
 */

int CARRO_VERMELHO = 13;
int CARRO_AMARELO = 12;
int CARRO_VERDE = 11;
int PEDESTRE_VERMELHO = 10;
int PEDESTRE_VERDE = 9;
int FASE_ABERTO = 1;
int FASE_FECHANDO = 2;
int FASE_FECHADO = 3;
int TEMPO_FASE_ABERTO = 7500;
int TEMPO_FASE_FECHANDO = 2500;
int TEMPO_FASE_FECHADO = 10000;
int TEMPO_PISCA_FECHANDO = 250;

void setup() {
  // configura os pinos de LEDs de saida
  pinMode(CARRO_VERMELHO, OUTPUT); // LED vermelho carro
  pinMode(CARRO_AMARELO, OUTPUT); // LED amarelo carro
  pinMode(CARRO_VERDE, OUTPUT); // LED verde carro
  pinMode(PEDESTRE_VERMELHO, OUTPUT); // LED vermelho pedestre
  pinMode(PEDESTRE_VERDE, OUTPUT); // LED verde pedestre

  // apaga os LEDs
  semaforo(0, 0);
}

void loop() {
  semaforo(FASE_ABERTO, TEMPO_FASE_ABERTO);
  semaforo(FASE_FECHANDO, TEMPO_FASE_FECHANDO);
  semaforo(FASE_FECHADO, TEMPO_FASE_FECHADO);
}

void semaforo(int fase, int tempo_total) {
  int pedestreVermelho = HIGH;
  int tempo = 0;
  int tempo_restante = tempo_total;
  do {
    if (fase == FASE_ABERTO) {
      set_leds(LOW, LOW, HIGH, HIGH, LOW);
      tempo = tempo_total;
      tempo_restante = 0;
    } else if (fase == FASE_FECHANDO) {
      set_leds(LOW, HIGH, LOW, pedestreVermelho, LOW);
      if (pedestreVermelho == HIGH) pedestreVermelho = LOW; else pedestreVermelho = HIGH; 
      tempo = TEMPO_PISCA_FECHANDO;
      tempo_restante -= tempo;
    } else if (fase == FASE_FECHADO) {
      set_leds(HIGH, LOW, LOW, LOW, HIGH);
      tempo = tempo_total;
      tempo_restante = 0;
    } else {
      // fase invalida, desliga todos os LEDs
      set_leds(LOW, LOW, LOW, LOW, LOW);
    }
    delay(tempo);
  } while (tempo_restante > 0);
}

void set_leds(int carroVermelho, int carroAmarelo, int carroVerde, int pedestreVermelho, int pedestreVerde) {
    digitalWrite(CARRO_VERMELHO, carroVermelho);
    digitalWrite(CARRO_AMARELO, carroAmarelo);
    digitalWrite(CARRO_VERDE, carroVerde);
    digitalWrite(PEDESTRE_VERMELHO, pedestreVermelho);
    digitalWrite(PEDESTRE_VERDE, pedestreVerde);  
}
