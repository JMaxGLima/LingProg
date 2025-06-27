"""
Programa: Módulo de Registro de Dados de Sensores DHT

Autor: Joao Max Germano Lima

Este módulo fornece funcionalidades para armazenar em arquivo os dados recebidos
de sensores DHT (temperatura e umidade), organizando-os por data em um diretório
específico com registro de timestamp.

Características principais:
- Criação automática do diretório de logs se não existir
- Organização de logs por data (um arquivo por dia)
- Registro com timestamp preciso de quando a leitura foi feita
- Mensagem de confirmação no console após cada registro

Licenca: CC BY
"""

import os
from datetime import datetime

def log_dht_data(data):
    """
    Registra os dados do sensor DHT em um arquivo de log com data/horário.
    
    Esta função:
    1. Verifica/Cria o diretório de logs conforme necessário
    2. Gera nome do arquivo baseado na data atual
    3. Adiciona a entrada de log com timestamp
    4. Confirma o registro no console
    
    Estrutura do arquivo de log:
    YYYY-MM-DD HH:MM:SS - dados_do_sensor
    
    Args:
        data (str): Dados recebidos do sensor para serem registrados no log

    
    Observações:
        - O caminho do diretório de logs é fixo e pré-definido
        - Cada dia gera um novo arquivo de log
        - As entradas são sempre anexadas ao final do arquivo
    """

    # Configuração do diretório de logs - caminho fixo
    log_directory = "/home/joaomax/Documentos/LingProg_ProjFinal/src/log/dht_logs/"
    
    # Criação do diretório se não existir (com tratamento de permissões implícito)
    if not os.path.exists(log_directory):
        os.makedirs(log_directory)  # Cria todos os diretórios intermediários necessários
    
    # Geração do nome do arquivo baseado na data atual
    current_date = datetime.now().strftime("%Y-%m-%d")  # Formato: ANO-MÊS-DIA
    log_filename = f"dht_logger_{current_date}.txt"     # Padrão: dht_logger_YYYY-MM-DD.txt
    full_path = os.path.join(log_directory, log_filename) # Caminho completo
    
    # Obtenção do timestamp para registro
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")  # Formato: ANO-MÊS-DIA HORA:MINUTO:SEGUNDO
    
    # Escrita dos dados no arquivo de log
    with open(full_path, 'a') as log_file:  # Modo 'a' para append (não sobrescreve)
        log_entry = f"{timestamp} - {data}\n"  # Formato da entrada
        log_file.write(log_entry)              # Escrita no arquivo
    
    # Feedback no console
    print(f"Dados registrados em {full_path}: {data}")
