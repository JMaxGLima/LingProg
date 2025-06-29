
# Sistema de Monitoramento de Temperatura e Umidade Ambiente

---

## 📌 Objetivo
Desenvolver um sistema de baixo custo para monitorar temperatura e umidade ambiente utilizando o sensor DHT11, com alertas visuais (LED) e sonoros (buzzer) para condições críticas, além de registrar os dados em logs para análise.

---

## 🛠️ Materiais Necessários
- Sensor DHT11     
- LED Vermelho       
- Buzzer Ativo      
- Arduino Uno      

---

## 🔌 Circuito
### Conexões:
| Componente   | Pino Arduino |
|--------------|-------------|
| DHT11 - VCC  | 5V          |
| DHT11 - S    | D8          |
| DHT11 - GND  | GND         |
| LED          | D10         |
| Buzzer       | D7          |

---

## 💻 Estrutura do Projeto

<pre>
LingProg_ProjFinal/
├── src/
│   ├── main.py
│   ├── log/
│   │   ├── __init__.py
│   │   ├── dht_logger.py
│   │   └── dht_logs/
│   └── MonitDHT/
│       ├── platformio.ini
│       └── src/
│           └── monitDHT.cpp
└── README.md
</pre>
---

## 🚀 Funcionalidades
- **Monitoramento em Tempo Real**: Leitura contínua de temperatura e umidade.
- **Alertas**:  
  - LED vermelho e buzzer para temperaturas altas ou umidade baixa.
- **Registro de Dados**:  
  - Logs diários em arquivos `.txt` com timestamp.
- **Controle via Serial**:  
  - Comandos `START` (iniciar medições) e `STOP` (parar).

---

## 📋 Como Usar
1. **Hardware**:
   - Monte o circuito.
   - Conecte o Arduino ao computador.

2. **Software**:
   - **Arduino**: Carregue `monitDHT.cpp` via Arduino IDE ou PlatformIO.
   - **Python**: Execute `main.py` para monitorar a serial e gerar logs:
     ```bash
     python3 src/main.py
     ```
   - Comandos disponíveis no terminal:  
     ```bash
     start  # Inicia medições
     stop   # Para medições
     ```

---

## 🛠️ Ferramentas e Bibliotecas
- **Arduino IDE** / **PlatformIO**  
- **VS Code**  
- **Bibliotecas**:
  - Arduino: `DHT.h` (Adafruit)  
  - Python: `pyserial`, `threading`, `datetime`, `os`  

---

## 📊 Exemplo de Log

2023-11-20 14:30:45 - Temp: 25.5°C | Umidade: 60%
2023-11-20 14:31:45 - Temp: 26.0°C | Umidade: 58% [ALERTA: Temperatura alta]

