/**
 * Projeto de um semáforo de carros e pedestres.
 */

int CARRO_VERMELHO = 13;
int CARRO_AMARELO = 12;
int CARRO_VERDE = 11;
int PEDESTRE_VERMELHO = 10;
int PEDESTRE_VERDE = 9;
int FASE_ABERTO = 1;
int FASE_FECHANDO = 2;
int FASE_FECHADO = 3;

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
  semaforo(FASE_ABERTO, 7500);
  semaforo(FASE_FECHANDO, 2500);
  semaforo(FASE_FECHADO, 10000);
}

void semaforo(int fase, int tempo) {
  if (fase == FASE_ABERTO) {
    digitalWrite(CARRO_VERMELHO, LOW);
    digitalWrite(CARRO_AMARELO, LOW);
    digitalWrite(CARRO_VERDE, HIGH);            
    digitalWrite(PEDESTRE_VERMELHO, HIGH);
    digitalWrite(PEDESTRE_VERDE, LOW);
  } else if (fase == FASE_FECHANDO) {
    digitalWrite(CARRO_VERMELHO, LOW);
    digitalWrite(CARRO_AMARELO, HIGH);
    digitalWrite(CARRO_VERDE, LOW);        
    digitalWrite(PEDESTRE_VERMELHO, HIGH);
    digitalWrite(PEDESTRE_VERDE, LOW);
  } else if (fase == FASE_FECHADO) {
    digitalWrite(CARRO_VERMELHO, HIGH);
    digitalWrite(CARRO_AMARELO, LOW);
    digitalWrite(CARRO_VERDE, LOW);    
    digitalWrite(PEDESTRE_VERMELHO, LOW);
    digitalWrite(PEDESTRE_VERDE, HIGH);
  } else {
    // fase invalida, desliga todos os LEDs
    digitalWrite(CARRO_VERMELHO, LOW);
    digitalWrite(CARRO_AMARELO, LOW);
    digitalWrite(CARRO_VERDE, LOW);
    digitalWrite(PEDESTRE_VERMELHO, LOW);
    digitalWrite(PEDESTRE_VERDE, LOW);
  }
  delay(tempo);
}
