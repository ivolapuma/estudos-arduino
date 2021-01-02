/**
 * Projeto exemplo para detectar obstáculos com um diodo laser e um LDR com alarme sonoro (buzzer). 
 */

const int INTERVALO_LEITURA = 100; // em milissegundos
const int LIMITE_OBSTACULO = 800;  // um valor de 0 a 1023 para determinar quando ha obstaculo entre o laser e o LDR
const int TOM_BUZZER = 100;        // frequencia do buzzer

const int LDR = A0;    // pino do LDR
const int BUZZER = 8;  // pino do BUZZER
const int BOTAO = 7;   // pino do BOTAO

int leituraLDR = 0;          // armazena valor da leitura do LDR
int leituraBotao = 0;        // armazena valor da leitura do botao
int contadorObstaculos = 0;  // contador de obstaculos detectados

void setup() {
  Serial.begin(9600);            // configura porta Serial a 9600 bps
  pinMode(LDR, INPUT);           // pino A0 como entrada
  pinMode(BUZZER, OUTPUT);       // pino 8 como saida
  pinMode(BOTAO, INPUT_PULLUP);  // pino 7 como entrada pull up
}

void loop() {
  leituraLDR = analogRead(LDR);       // le valor de tensao no pino LDR
  leituraBotao = digitalRead(BOTAO);  // le estado do botao

  boolean temObstaculo = verificaObstaculo(leituraLDR);

  if (temObstaculo) {
    tone(BUZZER, TOM_BUZZER); // aciona o buzzer
    delay(5 * INTERVALO_LEITURA);
    contadorObstaculos++;
  } else if (leituraBotao == LOW) {
    contadorObstaculos = 0;
  }

  noTone(BUZZER); // desliga o buzzer 

  // imprime valor lido do LDR
  Serial.print("leituraLDR=");
  Serial.print(leituraLDR);
  Serial.print("\t"); // Tab

  // imprime estado do botao
  Serial.print("leituraBotao=");
  Serial.print(leituraBotao);
  Serial.print("\t"); // Tab

  // imprime se tem obstaculo
  Serial.print("obstaculo=");
  Serial.print(temObstaculo);
  Serial.print("\t"); // Tab

  // imprime contador de obstaculos
  Serial.print("contador=");
  Serial.print(contadorObstaculos);
  
  Serial.println();

  delay(INTERVALO_LEITURA);
}

boolean verificaObstaculo(int valor) {
  return (valor <= LIMITE_OBSTACULO);
}
