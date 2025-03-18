/*

Program: Linguagem de Programacao - Pratica 1.cpp

Author: Joao Max Germano Lima

Date: 16/03/2025

Description: Programa em C++ desenvolvido para realizar calculos geometricos relacionados a circulos e retangulos.
O usuario pode escolher entre duas opcoes: calcular o comprimento da circunferencia e a area de um circulo
ou calcular o perimetro e a area de um retangulo.

License: CC BY

*/

#include <iostream>
#include <memory>

// Valor de PI definido
#define PI 3.14

// Classe Circle para armazenar raio, comprimento e area do circulo
class Circle {
public:
	float raio;
	float comprimento;
	float area;

	// Construtor recebe parametro do raio e inicializa comprimento e area em 0.
	Circle(float r) : raio(r), comprimento(0), area(0) {}

	// FunC'C#o para calcular o comprimento e a area do circulo
	void calcular() {
		comprimento = 2 * PI * raio;
		area = PI * raio * raio;

		// Exibe os resultados do circulo
		std::cout << "Comprimento da circunferencia: " << comprimento << std::endl;
		std::cout << "Area do circulo: " << area << std::endl;
	}
};

// Funcao para calcular o perimetro e a area do retangulo
void calcular_retangulo(float comprimento, float largura) {
	float perimetro = 2 * (comprimento + largura);  // calculo do perimetro
	float area = comprimento * largura;             // calculo da area

	// Exibe os resultados
	std::cout << "Perimetro do retangulo: " << perimetro << std::endl;
	std::cout << "Area do retangulo: " << area << std::endl;
}

int main() {
	int opcao;

	// Exibe o menu de opcoes
	std::cout << "Escolha a opcao:" << std::endl;
	std::cout << "1 - calculos do circulo" << std::endl;
	std::cout << "2 - calculos do retangulo" << std::endl;
	std::cout << "Digite sua escolha: ";
	std::cin >> opcao;

	if (opcao == 1) {
		// calculos relacionados ao circulo
		float raio;
		std::cout << "Digite o valor do raio do circulo: ";
		std::cin >> raio;

		// Criando um objeto Circle e chamando o metodo para calculo
		Circle c(raio);
		c.calcular();

		// Exibe os resultados do circulo
		std::cout << "Comprimento da circunferencia: " << c.comprimento << std::endl;
		std::cout << "area do circulo: " << c.area << std::endl;

	} else if (opcao == 2) {
		// Calculos relacionados ao retangulo
		// Usando alocacao dinamica de memoria com smart pointers
		std::unique_ptr<float> comprimento = std::make_unique<float>();
		std::unique_ptr<float> largura = std::make_unique<float>();

		std::cout << "Digite o comprimento do retangulo: ";
		std::cin >> *comprimento;
		std::cout << "Digite a largura do retangulo: ";
		std::cin >> *largura;

		// Chama a funcao para calcular o perimetro e a area
		calcular_retangulo(*comprimento, *largura);

	} else {
		std::cout << "opcao invalida." << std::endl;
	}

	return 0;
}