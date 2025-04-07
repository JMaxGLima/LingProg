"""

Program: Linguagem de Programacao - Pratica 1.cpp

Author: Joao Max Germano Lima

Date: 16/03/2025

Description: Programa em Python desenvolvido para realizar calculos geometricos relacionados a circulos e retangulos.
O usuario pode escolher entre duas opcoes: calcular o comprimento da circunferencia e a area de um circulo
ou calcular o perimetro e a area de um retangulo.

License: CC BY

Update: 07/04/2025: Código alterado para prática 4 adicionando loop "for" até que tecla Esc seja pressionada para finalizar programa ao fim de cada loop
"""
import msvcrt

# Valor de PI definido
PI = 3.14

# Funcao para calcular o comprimento da circunferencia e a area de um circulo
def calcular_circulo():
    # Usuario insere valor do raio
    raio = float(input("Digite o valor do raio do circulo: "))

    # Calcula o comprimento da circunferencia
    comprimento_circunferencia = 2 * PI * raio

    # Calcula a area do circulo
    area_circulo = PI * (raio ** 2)

    print(f"O comprimento da circunferencia e: {comprimento_circunferencia:.2f}")
    print(f"A area do circulo e: {area_circulo:.2f}")


# Funcao para calcular o perimetro e a area de um retangulo
def calcular_retangulo():
    # Usuario insere valor do comprimento e da largura do retangulo
    comprimento = float(input("Digite o comprimento do retagulo: "))
    largura = float(input("Digite a largura do retangulo: "))

    # Calcula o perimetro do retangulo
    perimetro_retangulo = 2 * (comprimento + largura)

    # Calcula a area do retangulo
    area_retangulo = comprimento * largura

    print(f"O perimetro do retangulo e: {perimetro_retangulo:.2f}")
    print(f"A area do retangulo e: {area_retangulo:.2f}")


# Funcao principal
def main():
    for _ in iter(int, 1):
        # Menu de opcoes para usuario
        print("Escolha a opcao:")
        print("1 - calculos do circulo")
        print("2 - calculos do retangulo")

        # Escolha do usuario
        opcao = input("Digite sua escolha:  ")

        # Verifica a opcao escolhida e chama a funcao correspondente
        if opcao == "1":
            calcular_circulo()
        elif opcao == "2":
            calcular_retangulo()
        else:
            print("Opcao invalida!")
        print("\nPressione ESC para sair ou qualquer outra tecla para continuar...")

        # Limpa o buffer de entrada
        while msvcrt.kbhit():
            msvcrt.getch()

        # Captura a tecla
        key = ord(msvcrt.getch())

        if key == 27:  # ESC
            exit()
    

# Executa a funcao principal
if __name__ == "__main__":
    main()
