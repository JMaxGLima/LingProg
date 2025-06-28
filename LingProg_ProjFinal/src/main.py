"""
Programa: Monitor Serial para Dados de Sensores DHT

Autor: Joao Max Germano Lima

Descricao:
Este programa monitora uma porta serial para receber dados de sensores DHT (temperatura e umidade),
permite enviar comandos 'start' e 'stop' via terminal para controlar o dispositivo remoto,
e registra os dados recebidos em um arquivo de log usando o módulo dht_logger.

Funcionalidades:
- Conexão serial com dispositivo (Arduino) que coleta dados DHT
- Interface de comandos via terminal (start/stop)
- Registro temporal dos dados recebidos
- Thread separada para entrada de comandos do usuário
- Tratamento de erros robusto

Licenca: CC BY
"""

import serial
import threading
from datetime import datetime
from log.dht_logger import log_dht_data

def read_from_terminal(ser, running):
    """
    Função executada em thread separada para monitorar entrada do usuário.
    
    Lê continuamente a entrada do terminal e envia comandos via serial:
    - 'start': Envia comando para iniciar medições
    - 'stop': Envia comando para parar medições
    
    Args:
        ser: Objeto de conexão serial
        running: Flag para controle da execução da thread
    """
    while running:
        user_input = input().strip().lower()
        if user_input == 'start':
            ser.write(b'start\n')
            print("Comando 'start' enviado via serial")
        elif user_input == 'stop':
            ser.write(b'stop\n')
            print("Comando 'stop' enviado via serial")
        else:
            print("Comando desconhecido. Use 'start' ou 'stop'")

def monitor_serial(port='/dev/ttyACM0', baudrate=9600):
    """
    Monitora a porta serial para receber dados de sensores DHT e enviar comandos.
    
    Esta função principal:
    1. Inicializa a conexão serial
    2. Cria uma thread para monitorar comandos do terminal
    3. Monitora continuamente a porta serial por dados
    4. Processa e registra os dados recebidos
    5. Gerencia o fechamento adequado dos recursos
    
    Args:
        port (str): Porta serial a ser monitorada (padrão: '/dev/ttyACM0')
        baudrate (int): Taxa de transmissão em bauds (padrão: 9600)
    
    Exceções:
        serial.SerialException: Erros de comunicação serial
        KeyboardInterrupt: Interrupção pelo usuário (Ctrl+C)
    """
    try:
        # Inicialização da conexão serial
        ser = serial.Serial(port, baudrate, timeout=1)
        print(f"Monitorando porta {port}... Digite 'start' ou 'stop' para enviar comandos. Pressione Ctrl+C para sair.")
        
        # Flag para controle da execução das threads
        running = True
        
        # Configuração e inicialização da thread para entrada de comandos
        terminal_thread = threading.Thread(target=read_from_terminal, args=(ser, running))
        terminal_thread.daemon = True  # Thread morre quando o programa principal termina
        terminal_thread.start()
        
        # Loop principal de monitoramento serial
        while running:
            if ser.in_waiting > 0:
                # Leitura e decodificação dos dados da porta serial
                data = ser.readline().decode('utf-8').strip()
                
                # Ignora linhas vazias ou incompletas
                if not data:
                    continue
                
                # Obtém timestamp atual para registro
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                
                # Registra os dados usando o módulo de logging
                log_dht_data(data)
    
    except serial.SerialException as e:
        # Tratamento de erros de comunicação serial
        print(f"Erro na comunicação serial: {e}")
        running = False
    except KeyboardInterrupt:
        # Tratamento para interrupção pelo usuário (Ctrl+C)
        print("\nMonitoramento encerrado pelo usuário.")
        running = False
    finally:
        # Garante o fechamento adequado da porta serial
        if 'ser' in locals() and ser.is_open:
            ser.close()
            print("Porta serial fechada.")

if __name__ == "__main__":
    """
    Ponto de entrada principal do programa.
    
    Quando executado como script, inicia automaticamente o monitoramento
    na porta serial padrão (/dev/ttyACM0) com baudrate 9600.
    """
    monitor_serial()