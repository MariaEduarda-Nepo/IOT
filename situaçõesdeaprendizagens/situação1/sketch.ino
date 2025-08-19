// --- Definição do pino ---
// Definimos o pino digital que usaremos para controlar o LED
// O pino 13 é uma ótima escolha, pois a maioria das placas Arduino já possui
// um LED embutido conectado a ele.
const int pinoLED = 13;

// --- Configuração (setup) ---
// Esta função é executada uma única vez quando o Arduino liga ou reseta.
void setup() {
  // Configura o pino 13 como uma saída (OUTPUT).
  // Isso significa que o Arduino irá ENVIAR corrente elétrica por este pino.
  pinMode(pinoLED, OUTPUT);
}

// --- Loop principal (loop) ---
// Esta função é executada repetidamente, para sempre, após o setup.
void loop() {
  // 1. Acende o LED
  // Define o pinoLED (pino 13) para HIGH (nível alto de tensão, 5V).
  // Isso liga o LED.
  digitalWrite(pinoLED, HIGH);

  // 2. Espera um segundo
  // Pausa o programa por 1000 milissegundos (1 segundo).
  delay(1000);

  // 3. Apaga o LED
  // Define o pinoLED (pino 13) para LOW (nível baixo de tensão, 0V).
  // Isso apaga o LED.
  digitalWrite(pinoLED, LOW);

  // 4. Espera mais um segundo
  // Pausa o programa por mais 1000 milissegundos (1 segundo).
  delay(1000);

  // O programa irá voltar para o início do loop e repetir todo o processo.
}