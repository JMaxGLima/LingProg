/*Program: Linguagem de Programacao - Avaliação 2 (questao_1.c)

Author: Joao Max Germano Lima

Date: 19/05/2025

Description: Programa em C desenvolvido para criar um vetor com alocação dinâmica de memória,
adicionando 5 valores a partir do teclado e exibir os valores.

License: CC BY
*/

#include <stdio.h>

#include <stdlib.h> // Required for malloc



int main() {

    // Memória alocada para vetor de 5 elementos
    int size = 5;
    int *ptr = (int *)malloc(size * sizeof(int)); //Criação de vetor com ponteiros
    int *ptr_aux = ptr; //Vetor auxiliar
    // Iniciando elementos do vetor
    for (int i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }
    // Mostrando valores registrados
    for (int i = 0; i < size; i++) {
        printf("%d ", *ptr_aux);
        ptr_aux++;
    }

    //Liberando memória alocada
    free(ptr);

    return 0;

}

