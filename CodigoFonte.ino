#include <WiFi.h>
#include <PubSubClient.h>

// Configuração WiFi
const char* ssid = "Wokwi-GUEST";  // Rede padrão Wokwi
const char* password = "";         // Sem senha

// Configuração MQTT
const char* mqtt_server = "23.22.163.175"; // Broker público para teste
const char* topicLuz = "energia/luz";
const char* topicConsumo = "energia/consumo";
const char* topicAlerta = "energia/alerta";

// Pinos
const int ldrPin = 34; // Pino LDR
const int sensorEnergiaPin = 35; // Potenciômetro para simular consumo

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Conectar ao WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");

  // Conectar ao broker MQTT
  client.setServer(mqtt_server, 1883);
  while (!client.connected()) {
    if (client.connect("Luan&Arthur&Jorge")) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      delay(1000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      client.connect("Luan&Arthur&Jorge");
    }
  }

  // Ler intensidade da luz e consumo de energia
  int luzSolar = analogRead(ldrPin); // LDR
  int consumoEnergia = analogRead(sensorEnergiaPin); // Potenciômetro

  // Mapear os valores para o range de 0 a 1000
  int luzSolarMapeada = map(luzSolar, 0, 4095, 0, 1000);
  int consumoEnergiaMapeado = map(consumoEnergia, 0, 4095, 0, 1000);

  // Processar os dados
  String alerta;
  if (luzSolarMapeada < 300 && consumoEnergiaMapeado > 700) {
    alerta = "A luz solar está baixa e o consumo de energia está alto. Por favor, economize energia!";
  } else if (luzSolarMapeada > 700 && consumoEnergiaMapeado < 300) {
    alerta = "A luz solar está alta e o consumo está baixo. Você pode usar mais energia!";
  } else {
    alerta = "Os níveis de luz solar e consumo de energia estão equilibrados.";
  }

  // Enviar dados para tópicos separados via MQTT
  client.publish(topicLuz, String(luzSolarMapeada).c_str());
  client.publish(topicConsumo, String(consumoEnergiaMapeado).c_str());
  client.publish(topicAlerta, alerta.c_str());

  // Log no terminal
  Serial.println("Luz Solar (0-1000): " + String(luzSolarMapeada));
  Serial.println("Consumo de Energia (0-1000): " + String(consumoEnergiaMapeado));
  Serial.println("Alerta: " + alerta);
  Serial.println("-----------------------------");

  delay(2000);
}
