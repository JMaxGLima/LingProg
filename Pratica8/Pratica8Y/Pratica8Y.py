"""
Programa: Manipulador de Arquivos YAML
Autor: [Seu Nome]
Data: [Data]

Descrição: Este programa demonstra como ler e manipular arquivos YAML em Python,
convertendo os dados estruturados para uso na linguagem de programação.

Dependências:
  - PyYAML (instalável via pip install pyyaml)

Licença: CC BY
"""

import yaml  # Biblioteca para manipulação de YAML
from pprint import pprint  # Para impressão formatada de estruturas de dados

def carregar_yaml(arquivo):
    """
    Carrega um arquivo YAML e retorna os dados como estrutura Python.
    
    Args:
        arquivo (str): Caminho para o arquivo YAML a ser carregado
        
    Returns:
        dict/list: Estrutura de dados contendo o conteúdo do YAML
    """
    try:
        with open(arquivo, 'r', encoding='utf-8') as file:
            dados = yaml.safe_load(file)  # safe_load é mais seguro que load
            print(f"\nArquivo '{arquivo}' carregado com sucesso!")
            return dados
    except FileNotFoundError:
        print(f"Erro: Arquivo '{arquivo}' não encontrado.")
        return None
    except yaml.YAMLError as e:
        print(f"Erro ao analisar YAML: {e}")
        return None

def exibir_dados(dados, nivel=0):
    """
    Exibe os dados YAML de forma hierárquica e formatada.
    
    Args:
        dados: Estrutura de dados a ser exibida
        nivel (int): Nível de indentação para a hierarquia
    """
    if isinstance(dados, dict):
        for chave, valor in dados.items():
            print("  " * nivel + f"- {chave}: ", end="")
            if isinstance(valor, (dict, list)):
                print()
                exibir_dados(valor, nivel + 1)
            else:
                print(valor)
    elif isinstance(dados, list):
        for item in dados:
            exibir_dados(item, nivel)
    else:
        print("  " * nivel + str(dados))

def processar_dados_yaml(arquivo):
    """
    Processa um arquivo YAML completo, carregando e convertendo os dados.
    
    Args:
        arquivo (str): Caminho para o arquivo YAML
        
    Returns:
        dict/list: Dados processados ou None em caso de erro
    """
    dados = carregar_yaml(arquivo)
    if dados is not None:
        print("\nEstrutura do arquivo YAML:")
        exibir_dados(dados)
        
        print("\nDados convertidos para Python:")
        pprint(dados, indent=2)
        
        return dados
    return None

def main():
    """
    Exibe o menu principal e gerencia a interação com o usuário.
    """
    while True:
        print("\n=== Manipulador de Arquivos YAML ===")
        print("1. Carregar e exibir arquivo YAML")
        print("2. Sair")
        opcao = input("\nEscolha uma opção: ")
        
        if opcao == '1':
            arquivo = input("Digite o caminho do arquivo YAML: ")
            dados = processar_dados_yaml(arquivo)
            
            if dados is not None:
                # Exemplo de como usar os dados convertidos
                print("\nExemplo de acesso aos dados convertidos:")
                if isinstance(dados, dict):
                    print("Primeira chave disponível:", list(dados.keys())[0])
                elif isinstance(dados, list):
                    print("Primeiro item da lista:", dados[0] if dados else "lista vazia")
                
        elif opcao == '2':
            print("Encerrando o programa...")
            break
        else:
            print("Opção inválida. Tente novamente.")

if __name__ == "__main__":
    main()