/**
 * Projeto exemplo para sensor de luz (LDR, Light-Dependent Resistor).
 */

const int LDR = A0;  // pino onde o LDR esta conectado
int leitura = 0;     // armazena o valor lido pelo ADC (conversor análogico-digital)
float tensao = 0.0;  // armazena a tensao

void setup() {
  // inicia e configura a Serial
  Serial.begin(9600); // 9600 bps

  // configura o pino com LDR como entrada
  pinMode(LDR, INPUT); // pino A0
}

void loop() {
  // le o valor de tensao no pino do LDR
  leitura = analogRead(LDR);

  // imprime o valor lido pelo Arduino
  Serial.print("leitura=");
  Serial.print(leitura);
  Serial.print("\t"); // TAB

  // converte e imprime o valor em tensao eletrica
  tensao = leitura * 5.0 / 1024.0;

  Serial.print("tensao=");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println(); // nova linha

  delay(1000); // aguarda 1 segundo para uma nova leitura
}
