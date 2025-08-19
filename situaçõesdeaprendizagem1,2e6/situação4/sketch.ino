// Definindo os pinos onde os LEDs estão conectados
const int pinosLED[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numeroDeLEDs = 8;
const int tempoEspera = 50; // Tempo em milissegundos entre cada passo da luz

void setup() {
  // Configura todos os pinos dos LEDs como SAÍDA
  for (int i = 0; i < numeroDeLEDs; i++) {
    pinMode(pinosLED[i], OUTPUT);
  }
}

void loop() {
  // Efeito de "ida" (da esquerda para a direita)
  for (int i = 0; i < numeroDeLEDs; i++) {
    digitalWrite(pinosLED[i], HIGH);
    delay(tempoEspera);
    digitalWrite(pinosLED[i], LOW);
  }

  // Efeito de "volta" (da direita para a esquerda)
  for (int i = numeroDeLEDs - 2; i >= 1; i--) {
    digitalWrite(pinosLED[i], HIGH);
    delay(tempoEspera);
    digitalWrite(pinosLED[i], LOW);
  }
}