/**
 * Projeto exemplo para detectar obstáculos com um diodo laser e um LDR. 
 */

const int INTERVALO_LEITURA = 500; // em milissegundos

const int LDR = A0; // pino do LDR
int adc = 0; // armazena valor da leitura do ADC

void setup() {
  Serial.begin(9600); // configura porta Serial a 9600 bps
  pinMode(LDR, INPUT); // pino A0 como entrada
}

void loop() {
  adc = analogRead(LDR); // le valor de tensao no pino LDR

  // imprime valor lido do ADC
  Serial.print("adc=");
  Serial.print(adc);
  Serial.print("\t"); // Tab

  // imprime se tem obstaculo
  Serial.print("obstaculo=");
  if (adc <= 512) Serial.print("sim"); else Serial.print("nao");

  Serial.println();

  delay(INTERVALO_LEITURA); 
}
