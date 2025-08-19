// --- Definição dos pinos ---
// Mapeamos os pinos digitais do Arduino para os LEDs do semáforo
// Isso facilita a leitura e a manutenção do código
const int ledVermelho = 13;
const int ledAmarelo = 12;
const int ledVerde = 11;

// --- Configuração (setup) ---
// Esta função é executada uma única vez quando o Arduino liga ou reseta.
void setup() {
  // Configura os pinos como saídas (OUTPUT)
  // Isso diz ao Arduino que ele irá ENVIAR energia para esses pinos
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

// --- Loop principal (loop) ---
// Esta função é executada repetidamente, para sempre, após o setup.
void loop() {
  // 1. Acende o LED VERDE (período de avanço)
  digitalWrite(ledVerde, HIGH); // Acende o LED verde
  delay(5000);                   // Espera 5 segundos (5000 milissegundos)

  // 2. Apaga o LED VERDE e acende o AMARELO (período de atenção)
  digitalWrite(ledVerde, LOW);   // Apaga o LED verde
  digitalWrite(ledAmarelo, HIGH); // Acende o LED amarelo
  delay(2000);                   // Espera 2 segundos (2000 milissegundos)

  // 3. Apaga o LED AMARELO e acende o VERMELHO (período de parada)
  digitalWrite(ledAmarelo, LOW);  // Apaga o LED amarelo
  digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
  delay(5000);                    // Espera 5 segundos (5000 milissegundos)

  // 4. Apaga o LED VERMELHO (preparando para recomeçar o ciclo com o verde)
  // Nota: Em um semáforo real, o amarelo acende antes de o verde, mas aqui vamos simular o ciclo mais comum
  digitalWrite(ledVermelho, LOW); // Apaga o LED vermelho
  // O loop vai se repetir, voltando para o estado 1 (LED Verde aceso)
}