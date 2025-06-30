/*
 * Programa: Sistema de Monitoramento Ambiental com Alerta

 * Autor: Joao Max Germano Lima
 
 * Descricao:
 * Este programa monitora temperatura e umidade usando o sensor DHT11
 * e aciona alertas visuais (LED) e sonoros (buzzer) quando os valores
 * ultrapassam os limites pré-definidos.
 * 
 * Funcionalidades:
 * - Leitura periódica de temperatura e umidade
 * - Alertas para temperatura alta e umidade baixa
 * - Controle via interface serial (START/STOP)
 * - Sistema de alarme com intervalo configurável
 * 
 * Licenca: CC BY
 */

#include <DHT.h>  // Biblioteca para o sensor DHT

// Definição dos pinos
#define DHTPIN 8       // Pino de dados do sensor DHT
#define LED_PIN 10     // Pino do LED de alerta
#define BUZZER_PIN 7   // Pino do buzzer
#define DHTTYPE DHT11  // Tipo do sensor DHT (DHT11)

// Inicialização do objeto DHT
DHT dht(DHTPIN, DHTTYPE);

// Variáveis de controle para os alarmes
unsigned long lastTempAlertTime = 0;  // Último tempo de alerta de temperatura
unsigned long lastHumidAlertTime = 0; // Último tempo de alerta de umidade
const long AlertInterval = 1500;      // Intervalo entre alarmes (ms)

// Estados do sistema
bool medicaoAtiva = true;      // Flag para controle das medições
bool tempAlertaAtivo = false;   // Flag para alerta de temperatura
bool umidAlertaAtivo = false;   // Flag para alerta de umidade

// Protótipos das funções
void verificarComandosSerial(); // Verifica comandos da interface serial
void lerSensor();               // Realiza a leitura do sensor
void verificarAlertas();        // Verifica condições de alerta
void ativarAlarme(int duracao, const char* mensagem); // Ativa alarme sonoro e visual
void desativarAlertas();        // Desativa todos os alertas

/**
 * Configuração inicial do sistema
 */
void setup() {
  Serial.begin(9600);           // Inicializa comunicação serial
  pinMode(LED_PIN, OUTPUT);     // Configura pino do LED como saída
  pinMode(BUZZER_PIN, OUTPUT);  // Configura pino do buzzer como saída
  dht.begin();                  // Inicializa sensor DHT
  
  // Mensagem inicial
  Serial.println("Sistema de monitoramento - Comandos: START/STOP");
  Serial.println("--------------------------------------------");
}

/**
 * Loop principal do programa
 */
void loop() {
  verificarComandosSerial();    // Verifica se há comandos via serial
  
  if (medicaoAtiva) {          // Se medições estão ativas
    lerSensor();               // Faz leitura do sensor
    verificarAlertas();        // Verifica condições de alerta
  }
  
  delay(1000);                 // Intervalo entre medições (1s)
}

/**
 * Verifica comandos recebidos pela interface serial
 * Comandos disponíveis:
 * - START: inicia as medições
 * - STOP: para as medições e desativa alertas
 */
void verificarComandosSerial() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();  // Remove espaços e caracteres especiais
    
    if (comando.equalsIgnoreCase("START")) {
      medicaoAtiva = true;
      Serial.println("Medições iniciadas");
    } 
    else if (comando.equalsIgnoreCase("STOP")) {
      medicaoAtiva = false;
      desativarAlertas();
      Serial.println("Medições paradas");
    }
  }
}

/**
 * Realiza a leitura do sensor DHT e atualiza os estados de alerta
 * Exibe os valores lidos e estados de alerta no monitor serial
 */
void lerSensor() {
  // Lê valores do sensor
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  // Verifica se a leitura foi bem sucedida
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do sensor!");
    return;
  }
  
  // Atualiza estados de alerta
  tempAlertaAtivo = temperatura >= 25.0;  // Alerta para temp > 25°C
  umidAlertaAtivo = umidade <= 60.0;      // Alerta para umid < 60%
  
  // Exibe dados no monitor serial
  Serial.print("|Condicoes de Temperatura:");
  Serial.print(temperatura);
  Serial.println(tempAlertaAtivo ? "|TEMP_ALERTA| " : "|NORMAL|");
  
  Serial.print("Condicoes de Umidade:");
  Serial.print(umidade);
  Serial.println(umidAlertaAtivo ? "|UMID_ALERTA|" : "|NORMAL|");
}

/**
 * Verifica as condições de alerta e ativa os alarmes conforme necessário
 * Controla o LED indicador e o buzzer
 */
void verificarAlertas() {
  unsigned long currentMillis = millis();  // Tempo atual
  bool algumAlertaAtivo = false;          // Flag para verificar se há algum alerta

  // Verifica alerta de temperatura
  if (tempAlertaAtivo) {
    algumAlertaAtivo = true;
    if (currentMillis - lastTempAlertTime >= AlertInterval) {
      lastTempAlertTime = currentMillis;
      ativarAlarme(200, "ALERTA: Temperatura acima de 25°C!");
    }
  }

  // Verifica alerta de umidade
  if (umidAlertaAtivo) {
    algumAlertaAtivo = true;
    if (currentMillis - lastHumidAlertTime >= AlertInterval) {
      lastHumidAlertTime = currentMillis;
      ativarAlarme(200, "ALERTA: Umidade abaixo de 60%!");
    }
  }

  // Controla LED (ligado se houver qualquer alerta)
  digitalWrite(LED_PIN, algumAlertaAtivo ? HIGH : LOW);
  
  // Desliga buzzer se não houver alertas
  if (!algumAlertaAtivo) {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

/**
 * Ativa o alarme sonoro e exibe mensagem de alerta
 * @param duracao Tempo que o buzzer ficará ativo (ms)
 * @param mensagem Mensagem de alerta a ser exibida no serial
 */
void ativarAlarme(int duracao, const char* mensagem) {
  digitalWrite(BUZZER_PIN, HIGH);  // Liga buzzer
  delay(duracao);                  // Mantém ligado pelo tempo especificado
  digitalWrite(BUZZER_PIN, LOW);   // Desliga buzzer
  Serial.println(mensagem);        // Exibe mensagem de alerta
}

/**
 * Desativa todos os alertas e indicadores
 */
void desativarAlertas() {
  digitalWrite(LED_PIN, LOW);    // Desliga LED
  digitalWrite(BUZZER_PIN, LOW); // Desliga buzzer
  tempAlertaAtivo = false;       // Reseta flag de temperatura
  umidAlertaAtivo = false;       // Reseta flag de umidade
}