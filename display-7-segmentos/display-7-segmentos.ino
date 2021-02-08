/**
 * Projeto exemplo de uso de display de 7 segmentos.
 * 
 * Exibir contagem de 0 a 9 em um display de 7 segmentos.
 */

const int A = 12;
const int B = 11;
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  display0(A, B, C, D, E, F, G);
  delay(1000);
  display1(A, B, C, D, E, F, G);
  delay(1000);
  display2(A, B, C, D, E, F, G);
  delay(1000);
  display3(A, B, C, D, E, F, G);
  delay(1000);
  display4(A, B, C, D, E, F, G);
  delay(1000);
  display5(A, B, C, D, E, F, G);
  delay(1000);
  display6(A, B, C, D, E, F, G);
  delay(1000);
  display7(A, B, C, D, E, F, G);
  delay(1000);
  display8(A, B, C, D, E, F, G);
  delay(1000);
  display9(A, B, C, D, E, F, G);
  delay(1000);
}

/**
 * Exibe digito 0 no display
 */
void display0(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

/**
 * Exibe digito 1 no display
 */
void display1(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

/**
 * Exibe digito 2 no display
 */
void display2(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 3 no display
 */
void display3(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 4 no display
 */
void display4(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 5 no display
 */
void display5(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 6 no display
 */
void display6(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 7 no display
 */
void display7(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

/**
 * Exibe digito 8 no display
 */
void display8(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

/**
 * Exibe digito 9 no display
 */
void display9(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
