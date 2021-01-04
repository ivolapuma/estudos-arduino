/**
 * Exemplo de uso de graficos.
 * Envia na porta Serial o valor de tensão na saida do potenciometro.
 */

const int POTENCIOMETRO = A0; // pino do potenciometro

int leitura = 0; // armazena leitura do ADC
float tensao = 0.0; // armazena a tensao

void setup() {
  Serial.begin(9600); // inicia a porta Serial a 9600 bps
  pinMode(POTENCIOMETRO, INPUT); // pino A0 (potenciometro) como entrada
}

void loop() {
  leitura = analogRead(POTENCIOMETRO); // le o valor de tensao do potenciometro
  tensao = leitura * 5.0 / 1024.0; // converte o valor em tensao eletrica (V)
  Serial.print(leitura*10/1024); // imprime valor da leitura na Serial (convertido de 0 a 10)
  Serial.print(" "); // separador de valores
  Serial.print(tensao); // imprime valor da tensao na Serial
  Serial.println(); // final de linha
  delay(100); // aguarda .1 segundo para proxima leitura
}
