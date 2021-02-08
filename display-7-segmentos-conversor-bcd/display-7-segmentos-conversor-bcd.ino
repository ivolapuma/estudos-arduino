/**
 * Projeto exemplo de uso de display de 7 segmentos com conversor BCD.
 */

const int A = 12;
const int B = 9;
const int C = 10;
const int D = 11;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  display0(A, B, C, D);
  delay(1000);
  display1(A, B, C, D);
  delay(1000);
  display2(A, B, C, D);
  delay(1000);
  display3(A, B, C, D);
  delay(1000);
  display4(A, B, C, D);
  delay(1000);
  display5(A, B, C, D);
  delay(1000);
  display6(A, B, C, D);
  delay(1000);
  display7(A, B, C, D);
  delay(1000);
  display8(A, B, C, D);
  delay(1000);
  display9(A, B, C, D);
  delay(1000);
}

/**
 * Exibe no display o numero 0 (0000)
 */
void display0(int a, int b, int c, int d) {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 1 (0001)
 */
void display1(int a, int b, int c, int d) {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 2 (0010)
 */
void display2(int a, int b, int c, int d) {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 3 (0011)
 */
void display3(int a, int b, int c, int d) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 4 (0100)
 */
void display4(int a, int b, int c, int d) {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 5 (0101)
 */
void display5(int a, int b, int c, int d) {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 6 (0110)
 */
void display6(int a, int b, int c, int d) {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 7 (0111)
 */
void display7(int a, int b, int c, int d) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
}

/**
 * Exibe no display o numero 8 (1000)
 */
void display8(int a, int b, int c, int d) {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}

/**
 * Exibe no display o numero 9 (1001)
 */
void display9(int a, int b, int c, int d) {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}
