/*

Program: Linguagem de Programacao - Pratica 1.c

Author: Joao Max Germano Lima

Date: 16/03/2025

Description: Programa em C desenvolvido para realizar calculos geometricos relacionados a circulos e retangulos.
O usuario pode escolher entre duas opcoes: calcular o comprimento da circunferencia e a area de um circulo
ou calcular o perimetro e a area de um retangulo.

License: CC BY


Update: 31/03/2025: Codigo alterado para pratica 4 adicionando loop "for" ate que tecla Esc seja pressionada para finalizar programa ao fim de cada loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For getch() function

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

    printf("perimetro do retangulo: %.2f\n", perimetro);
    printf("area do retangulo: %.2f\n", area);
}

int main() {
    char key;
    
    for(;;) { // Infinite loop
        int caso;
        printf("\nEscolha a opcao:\n");
        printf("1 - calculos do circulo\n");
        printf("2 - calculos do retangulo\n");
        printf("Digite sua escolha: ");
        scanf("%d", &caso);

        if (caso == 1) {
            circle c1;
            printf("\nDigite o valor do raio do circulo: ");
            scanf("%f", &c1.raio); // Usuario insere valor do raio
            calcular_circulo(&c1);  // Chama a funcao para calcular as propriedades do circulo
            printf("Comprimento da circunferencia: %.2f\n", c1.comprimento);
            printf("area do circulo: %.2f\n", c1.area);

        } else if (caso == 2) {
            float *comprimento, *largura;
            comprimento = (float *)malloc(sizeof(float));
            largura = (float *)malloc(sizeof(float));

            printf("\nDigite o comprimento do retangulo: ");
            scanf("%f", comprimento); //Usuario insere valor do comprimento do retangulo
            printf("Digite a largura do retangulo: ");
            scanf("%f", largura); //Usuario insere valor da largura do retangulo
            calcular_retangulo(comprimento, largura); // Chama a funcao para calcular as propriedades do retangulo

            //Memoria alocada e liberada ao fim do codigo
            free(comprimento);
            free(largura);

        } else {
            printf("Opcao invalida.\n");
        }

        printf("\nPressione ESC para sair ou qualquer outra tecla para continuar...\n");
        while(getchar() != '\n'); // Clear input buffer
        key = getch();
        if(key == 27) // ASCII code for ESC
            break;
    }

    return 0;
}