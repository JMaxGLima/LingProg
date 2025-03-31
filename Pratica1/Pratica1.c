/*

Program: Linguagem de Programacao - Pratica 1.c

Author: Joao Max Germano Lima

Date: 16/03/2025

Description: Programa em C desenvolvido para realizar calculos geometricos relacionados a circulos e retangulos.
O usuario pode escolher entre duas opcoes: calcular o comprimento da circunferencia e a area de um circulo
ou calcular o perimetro e a area de um retangulo.

License: CC BY


*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define PI 3.14 // Valor de PI definido

typedef struct { // Estrutura de circulo
	float raio; //Raio do circulo
	float comprimento; //Comprimento da circunferencia
	float area; //area do circulo
} circle;

//  funcao para calcular o comprimento da circunferencia e a area de um circulo

void calcular_circulo(circle * c) {
	c->comprimento = 2 * PI * c->raio;
	c->area = PI * c->raio * c->raio;
}

// funcao para calcular o perimetro e a area de um retangulo

void calcular_retangulo(float *comprimento, float *largura) {
	float perimetro = 2 * (*comprimento + *largura);
	float area = *comprimento * *largura;

	printf("perimetro do retangulo: %.2f\n\n", perimetro);
	printf("area do retangulo: %.2f\n\n", area);
}

// Função para verificar se ESC foi pressionado
bool check_esc() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 27) { // 27 = ASCII para ESC
            printf("\nPrograma encerrado.\n");
            return true;
        }
    }
    return false;
}

// Função para ler um número inteiro sem bloquear (e verificar ESC)
bool read_int(int *value) {
    char buffer[20];
    int index = 0;

    while (1) {
        if (check_esc()) return false;

        if (_kbhit()) {
            char key = _getch();
            if (key == '\r') { // Enter pressionado
                buffer[index] = '\0';
                *value = atoi(buffer);
                return true;
            }
            else if (key >= '0' && key <= '9') {
                buffer[index++] = key;
                printf("%c", key);
            }
        }
    }
}

// Função para ler um número float sem bloquear (e verificar ESC)
bool read_float(float *value) {
    char buffer[20];
    int index = 0;

    while (1) {
        if (check_esc()) return false;

        if (_kbhit()) {
            char key = _getch();
            if (key == '\r') { // Enter pressionado
                buffer[index] = '\0';
                *value = atof(buffer);
                return true;
            }
            else if (key >= '0' && key <= '9' || key == '.') {
                buffer[index++] = key;
                printf("%c", key);
            }
        }
    }
}

int main() {
	int caso;
	char key;
	for (;;){

		if (check_esc()) break;
		
		printf("Escolha a opcao:\n");
		printf("1 - calculos do circulo\n");
		printf("2 - calculos do retangulo\n");
		printf ("Esc - Encerrar programa\n");
		printf("Digite sua escolha:\n ");

		if (!read_int(&caso)) break; // Se ESC foi pressionado

		if (caso == 1) {
		circle c1;
		printf("\nDigite o valor do raio do circulo: ");
		scanf("%f", &c1.raio); // Usuario insere valor do raio
		calcular_circulo(&c1);  // Chama a funcao para calcular as propriedades do circulo
		printf("Comprimento da circunferencia: %.2f\n", c1.comprimento);
		printf("area do circulo: %.2f\n\n", c1.area);
		} 
		
		else if (caso == 2) {
		float *comprimento, *largura;
		comprimento = (float *)malloc(sizeof(float));
		largura = (float *)malloc(sizeof(float));

		printf("Digite o comprimento do retangulo: ");
		if (!read_float(&comprimento)) break; //Usuario insere valor do comprimento do retangulo
		printf("Digite a largura do retangulo: ");
		if (!read_float(&largura)) break; //Usuario insere valor da largura do retangulo
		calcular_retangulo(comprimento, largura); // Chama a funcao para calcular as propriedades do retangulo

		//Memoria alocada e liberada ao fim do codigo
		free(comprimento);
		free(largura);
		} 
		else {
			printf("Opcao invalida.\n");
		}
	}
	return 0;
}