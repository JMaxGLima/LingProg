Sistema de Monitoramento de Temperatura e Umidade
https://img.shields.io/badge/Python-3.8%252B-blue
https://img.shields.io/badge/PlatformIO-Compatible-green
https://img.shields.io/badge/license-MIT-green

Projeto desenvolvido para a disciplina de Linguagem de Programação no Instituto Federal do Espírito Santo, criando um sistema completo de monitoramento ambiental com Arduino e Python.

📌 Visão Geral
Sistema que monitora temperatura e umidade em tempo real usando:

Arduino + DHT11 para coleta de dados

Python para registro em logs e controle remoto

Alertas visuais (LED) e sonoros (buzzer) quando os valores ultrapassam limites seguros

Aplicações:
🏠 Automação residencial | 🏢 Monitoramento de servidores | 🌱 Estufas inteligentes

📋 Sumário
Estrutura do Projeto

Como Usar

Materiais Necessários

Circuitos

Custo do Projeto

Referências

📂 Estrutura do Projeto
text
LingProg_ProjFinal/
│
├── src/
│   ├── main.py                 # Script principal (Python)
│   ├── log/
│   │   ├── __init__.py         # Pacote Python
│   │   ├── dht_logger.py       # Módulo de registros
│   │   └── dht_logs/           # Pasta de logs (gerados automaticamente)
│   │
│   └── MonitDHT/               # Código do Arduino (PlatformIO)
│       ├── platformio.ini      # Configuração
│       └── src/
│           └── monitDHT.cpp    # Firmware
│
└── README.md
⚡ Como Usar
1. Configuração do Arduino
Conecte:

DHT11 → Pino D8

LED → Pino D10

Buzzer → Pino D7

Carregue monitDHT.cpp via PlatformIO.

2. Execução do Python
bash
python src/main.py
Comandos disponíveis:

start → Inicia medições

stop → Pausa o sistema

Exemplo de log:

text
2024-01-20 14:30:00 - TEMP:26.5°C | UMID:58%  
2024-01-20 14:31:00 - TEMP:26.7°C | UMID:57% (ALERTA!)
🔧 Materiais Necessários
Componente	Quantidade	Custo (R$)
Arduino Uno	1	43,90
Sensor DHT11	1	11,90
LED Vermelho	1	0,19
Buzzer Ativo	1	2,18
Jumpers	5+	-
Total		58,17
🔌 Circuito
https://via.placeholder.com/400x200?text=Diagrama+do+Circuito (Substituir por imagem real)

Componente	Pino Arduino
DHT11 (VCC)	5V
DHT11 (S)	D8
DHT11 (GND)	GND
LED (+)	D10
Buzzer (+)	D7
📚 Referências
Sensor DHT11 - MakerHero

PlatformIO Documentation

PySerial Guide

🎓 Autores
João Max Germano Lima
📧 joaomaxql@gmail.com

Orientador: Prof. Douglas Almonfrey

<p align="center"> 🚀 **Projeto acadêmico desenvolvido no IFES - 2024** </p>
