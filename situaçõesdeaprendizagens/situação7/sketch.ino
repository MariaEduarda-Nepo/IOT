// Definindo os pinos onde os LEDs estão conectados
const int pinosLEDs[] = {2, 3, 4, 5, 6};
const int numeroDeLEDs = 5;
const int tempoEspera = 200; // Tempo em milissegundos entre o acionamento de cada LED

void setup() {
  // Configura cada pino como SAÍDA
  for (int i = 0; i < numeroDeLEDs; i++) {
    pinMode(pinosLEDs[i], OUTPUT);
  }
}

void loop() {
  // Loop para acender os LEDs sequencialmente
  for (int i = 0; i < numeroDeLEDs; i++) {
    digitalWrite(pinosLEDs[i], HIGH); // Acende o LED atual
    delay(tempoEspera);               // Espera
    digitalWrite(pinosLEDs[i], LOW);  // Apaga o LED atual
  }
}