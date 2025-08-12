// --- Definição dos pinos ---
const int pinoLED = 13;      // Pino digital para o LED
const int pinoBotao = 2;   // Pino digital para o botão

// --- Variáveis de estado ---
int estadoLED = LOW;          // Variável para armazenar o estado atual do LED (LOW = desligado)
int estadoBotao;              // Variável para ler o estado atual do botão
int ultimoEstadoBotao = LOW;  // Variável para armazenar o estado anterior do botão

// --- Variáveis para controle de tempo (debounce) ---
long ultimaLeituraDebounce = 0; // Armazena o último momento em que o estado do botão mudou
long atrasoDebounce = 50;       // Intervalo de tempo para ignorar "saltos" do botão (50ms)

// --- Configuração (setup) ---
void setup() {
  // Configura o pino do LED como saída
  pinMode(pinoLED, OUTPUT);
  // Configura o pino do botão como entrada
  pinMode(pinoBotao, INPUT);
}

// --- Loop principal (loop) ---
void loop() {
  // Lê o estado atual do botão
  int leituraBotao = digitalRead(pinoBotao);

  // --- Lógica de Debounce (anti-salto) ---
  // Verifica se o estado do botão mudou em relação à última leitura
  if (leituraBotao != ultimoEstadoBotao) {
    // Se mudou, armazena o tempo atual
    ultimaLeituraDebounce = millis();
  }

  // Se o estado atual do botão for diferente do anterior e o tempo de debounce já passou
  if ((millis() - ultimaLeituraDebounce) > atrasoDebounce) {
    // Se o estado atual e o anterior ainda forem diferentes, é uma mudança "real"
    if (leituraBotao != estadoBotao) {
      estadoBotao = leituraBotao;

      // Se o botão foi pressionado (estado HIGH)
      if (estadoBotao == HIGH) {
        // Inverte o estado do LED
        if (estadoLED == LOW) {
          estadoLED = HIGH;
        } else {
          estadoLED = LOW;
        }
      }
    }
  }

  // Escreve o novo estado no pino do LED
  digitalWrite(pinoLED, estadoLED);

  // Armazena o estado atual do botão para a próxima iteração
  ultimoEstadoBotao = leituraBotao;
}