"""
Programa: Manipulaçao de Arquivos em Python
Autor: Joao Max Germano Lima
Data: 26/05/2025

Descriçao: Programa em Python que demonstra diversas operaçoes de manipulaçao de arquivos, incluindo:
- Leitura caractere por caractere
- Leitura linha por linha
- Manipulaçao de dados binarios (estruturas de data)
- Acesso aleatorio em arquivos
- Analise de arquivos CSV
O programa oferece uma interface com menu para o usuario selecionar e testar cada operaçao.

Licença: CC BY
"""

import os
import struct
from datetime import datetime

class Date:
    """Classe que representa uma data com dia, mes e ano"""
    def __init__(self, day=0, month=0, year=0):
        """Inicializa os atributos da data"""
        self.day = day    # Dia do mes (1-31)
        self.month = month  # Mes do ano (1-12)
        self.year = year   # Ano com 4 digitos

def read_by_characters():
    """
    Le um arquivo caractere por caractere e imprime cada um na tela.
    Demonstra leitura basica de arquivos em modo texto.
    """
    filename = "test_file.txt"  # Nome do arquivo a ser lido
    
    try:
        # Abre o arquivo em modo leitura ('r')
        with open(filename, 'r') as file:
            print("\nLendo caracteres um por um:\n")
            
            # Le um caractere por vez ate o final do arquivo
            while True:
                char = file.read(1)  # Le um unico caractere
                if not char:  # Verifica se chegou ao final do arquivo
                    break
                print(char)  # Imprime o caractere lido
                
    except IOError:
        print("Erro ao abrir o arquivo. Verifique se o arquivo existe e as permissoes.")

def read_by_lines():
    """
    Le um arquivo linha por linha e imprime cada linha na tela.
    Demonstra leitura eficiente de arquivos linha a linha.
    """
    filename = "test_file.txt"  # Nome do arquivo a ser lido
    
    try:
        # Abre o arquivo em modo leitura ('r')
        with open(filename, 'r') as file:
            print("\nLendo linhas uma por uma:\n")
            
            # Itera sobre cada linha do arquivo
            for line in file:
                print(line, end='')  # Imprime a linha (end='' evita dupla quebra de linha)
                
    except IOError:
        print("Erro ao abrir o arquivo. Verifique se o arquivo existe e as permissoes.")

def handle_binary_data():
    """
    Manipula dados binarios, escrevendo e lendo estruturas de data de/para arquivo.
    Demonstra operaçoes com arquivos binarios usando o modulo struct.
    """
    # Cria duas datas de exemplo
    d1 = Date(7, 9, 1999)
    d2 = Date(12, 5, 2024)
    
    # Variaveis para armazenar as datas lidas
    e1 = Date()
    e2 = Date()

    # Solicita ao usuario o nome do arquivo
    filename = input("\nDigite o nome do arquivo para dados binarios: ")

    # Escreve dados binarios no arquivo
    try:
        # Abre o arquivo em modo escrita binaria ('wb')
        with open(filename, 'wb') as file:
            # Empacota os dados como bytes (formato 'iii' = 3 inteiros de 4 bytes cada)
            # struct.pack converte os dados para bytes seguindo o formato especificado
            file.write(struct.pack('iii', d1.day, d1.month, d1.year))
            file.write(struct.pack('iii', d2.day, d2.month, d2.year))
            
    except IOError:
        print("Erro! Nao foi possivel abrir o arquivo para escrita!")
        return

    # Le os dados binarios do arquivo
    try:
        # Abre o arquivo em modo leitura binaria ('rb')
        with open(filename, 'rb') as file:
            # Le e desempacota os dados (struct.calcsize calcula o tamanho do formato)
            data = file.read(struct.calcsize('iii'))
            e1.day, e1.month, e1.year = struct.unpack('iii', data)
            
            data = file.read(struct.calcsize('iii'))
            e2.day, e2.month, e2.year = struct.unpack('iii', data)
            
    except IOError:
        print("Erro! Nao foi possivel abrir o arquivo para leitura!")
        return

    # Exibe os dados lidos formatados
    print("Primeira Data (DD/MM/AAAA): {:02d}/{:02d}/{}".format(
        e1.day, e1.month, e1.year))
    print("Segunda Data (DD/MM/AAAA): {:02d}/{:02d}/{}".format(
        e2.day, e2.month, e2.year))

def random_access():
    """
    Demonstra acesso aleatorio em arquivos binarios, escrevendo e lendo em posiçoes especificas.
    Mostra como usar seek() para navegar no arquivo.
    """
    filename = "data.bin"  # Nome do arquivo para acesso aleatorio
    
    try:
        # Abre o arquivo em modo escrita/leitura binaria ('wb+')
        # 'wb+' cria o arquivo se nao existir ou sobrescreve se existir
        with open(filename, 'wb+') as file:
            position = 3  # Posiçao onde sera escrito o caractere
            ch = b'G'     # Caractere a ser escrito (em formato bytes)
            
            # Move o ponteiro para a posiçao especificada
            file.seek(position)
            
            # Escreve o caractere na posiçao atual
            file.write(ch)
            
            # Move o ponteiro de volta para a posiçao para leitura
            file.seek(position)
            
            # Le um caractere da posiçao atual
            read_ch = file.read(1)
            
            # Exibe o caractere lido (decodificado de bytes para string)
            print("\nDados lidos da posiçao {}: {}".format(position, read_ch.decode()))
            
    except IOError:
        print("Erro ao manipular o arquivo. Verifique as permissoes.")

def parse_csv():
    """
    Analisa um arquivo CSV (valores separados por virgula) e imprime cada campo.
    Demonstra processamento basico de arquivos CSV.
    """
    filename = "test_file.txt"  # Nome do arquivo CSV (pode ser .csv ou .txt)
    
    try:
        # Abre o arquivo em modo leitura ('r')
        with open(filename, 'r') as file:
            print("\nAnalisando conteudo CSV:\n")
            
            # Processa cada linha do arquivo
            for line in file:
                # Remove espaços em branco no inicio/fim e divide pelos separadores
                tokens = line.strip().split(',')
                
                # Imprime cada token (campo) separadamente
                for token in tokens:
                    print(token)
                    
    except IOError:
        print("Erro ao abrir arquivo. Verifique se o arquivo existe.")

def display_menu():
    """
    Exibe o menu de opçoes e captura a escolha do usuario.
    Retorna a opçao selecionada como string.
    """
    print("\nMenu de Operaçoes com Arquivos:")
    print("1. Ler arquivo caractere por caractere")
    print("2. Ler arquivo linha por linha")
    print("3. Manipular dados binarios (datas)")
    print("4. Acesso aleatorio a arquivo")
    print("5. Analisar arquivo CSV")
    print("0. Sair")
    return input("Digite sua opçao: ")

def main():
    """
    Funçao principal que controla o fluxo do programa.
    Exibe o menu e executa a funçao correspondente a opçao selecionada.
    """
    while True:
        choice = display_menu()  # Exibe menu e obtem escolha
        
        if choice == '1':
            read_by_characters()
        elif choice == '2':
            read_by_lines()
        elif choice == '3':
            handle_binary_data()
        elif choice == '4':
            random_access()
        elif choice == '5':
            parse_csv()
        elif choice == '0':
            print("Saindo do programa.")
            break
        else:
            print("Opçao invalida. Por favor, tente novamente.")

# Ponto de entrada do programa
if __name__ == "__main__":
    main()