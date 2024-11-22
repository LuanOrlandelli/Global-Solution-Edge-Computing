# Global Solution Edge Computing
Projeto Global Solution Edge Computing 2° Semestre

### **Sistema de Auxílio para Energia Renovável com ESP32 e Node-RED**

## **Integrantes do Grupo**
- **Luan Orlandelli Ramos** - RM: 554747  
- **Arthur Bobadilla Franchi** - RM: 555056  
- **Jorge Luiz Silva Santos** - RM: 554418  

---

## **Descrição do Problema**

Com o aumento do uso de fontes de energia renovável, como placas solares, surge a necessidade de sistemas que auxiliem os consumidores a compreender e otimizar o consumo energético. Sem informações claras, é difícil saber se a energia solar está sendo aproveitada adequadamente e se os hábitos de consumo precisam ser ajustados.

O objetivo deste projeto é criar um sistema que monitore a intensidade de luz solar captada pelas placas solares, correlacionando com o consumo de energia de uma residência, e forneça feedback em tempo real para ajudar o usuário a tomar decisões sobre o uso de energia.

---

## **Detalhes do Projeto**

O sistema utiliza um ESP32 para monitorar dois sensores:
1. **LDR (Light Dependent Resistor)** - Mede a quantidade de luz solar captada pelas placas solares.  
2. **Potenciômetro** - Simula o consumo de energia de uma residência.  

Os dados são captados, processados e enviados via **MQTT** para o Node-RED, onde são exibidos em dashboards interativos com gráficos e indicadores. O sistema analisa os dados recebidos e fornece alertas para orientar o usuário:

- **Consumo elevado e baixa luz solar**: Alertar para economizar energia.  
- **Consumo baixo e alta luz solar**: Indicar que é possível usar mais energia.  
- **Consumo e luz solar equilibrados**: Informar que os níveis estão satisfatórios.  

---

## **Arquitetura do Sistema**

1. **ESP32**: Sensor de leitura de dados e envio via MQTT.  
2. **Node-RED**: Processamento de dados, exibição de gráficos e envio de mensagens de alerta.  
3. **Dashboard**: Interface amigável para o usuário visualizar informações em tempo real.  

---

## **Instruções de Uso**

### **1. Simulação no Wokwi**
- Acesse o link da simulação no Wokwi no final do README.
- Confirme que os sensores estão corretamente conectados aos pinos:
  - LDR no **pino 34**
  - Potenciômetro no **pino 35**

### **2. Configuração no Node-RED**
1. Importe o arquivo JSON fornecido no Node-RED para configurar os fluxos e dashboards.
2. Configure o broker MQTT com o IP desejado, e a porta `1883`. (Para realizar a mudança de IP acesse a linha `"broker": "23.22.163.175"` e mude apenas os números)
3. Certifique-se de que o ESP32 está enviando dados para os seguintes tópicos MQTT:
   - `energia/luz`  
   - `energia/consumo`  
   - `energia/alerta`  

### **3. Visualização no Dashboard**
- Acesse o Dashboard via Node-RED e visualize:
  - **Gráficos de luz solar e consumo de energia**.
  - **Medidores em tempo real**.
  - **Mensagens de alerta**.

### **4. Interpretação dos Dados**
- Use os alertas para ajustar os hábitos de consumo com base na luz solar disponível.

---

## **Requisitos**

### **Hardware**
- **ESP32**
- **LDR**
- **Potenciômetro**

### **Software**
- **Simulador Wokwi** (ou ambiente físico com ESP32)
- **Node-RED** 
- **Broker MQTT** (IP: `Seu IP, neste caso 23.22.163.175`, porta `1883`)

---

## **Dependências**

### **Hardware**
- ESP32.
- LDR.
- Potenciômetro.

### **Bibliotecas ESP32**
- `WiFi.h`
- `PubSubClient.h`

### **Node-RED**
- Node-RED Dashboard instalado para exibição dos gráficos e medidores.
- Conexão ao broker MQTT.

---

## **Fluxo de Funcionamento**

1. **Coleta de Dados**
   - O ESP32 lê os valores do LDR e do potenciômetro.
2. **Processamento de Dados**
   - Os dados são processados e interpretados, gerando o alerta.
3. **Envio de Dados**
   -  Os valores e o alerta são enviados para os tópicos MQTT.
4. **Visualização**
   - O Node-RED recebe os dados e os exibe em gráficos e medidores no Dashboard.

---

## **Simulação Wokwi**

**Link da simulação no Wokwi:**  
*https://wokwi.com/projects/414824500628623361*

---

## **Link para o vídeo**
*https://drive.google.com/file/d/1ad4r6_If1b94YWsYXKqnMFRuqXji7UZQ/view?usp=sharing*

---

## **Contribuições Futuras**

- Integração com sistemas de automação para ajuste automático de cargas elétricas.  
- Monitoramento em longo prazo com armazenamento de dados.  

---

## **Licença**

Este projeto foi desenvolvido exclusivamente para fins educacionais. Todos os direitos reservados aos integrantes do grupo.  

