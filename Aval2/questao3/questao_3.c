/*Program: Linguagem de Programacao - Avaliação 2 (questao_3.c)

Author: Joao Max Germano Lima

Date: 19/05/2025

Description: Programa em C desenvolvido para criar uma lista,
adicionando 5 valores pelo teclado e exibindo os valores.

License: CC BY
*/

#include <stdio.h>
#include <stdlib.h>

//Estrutura do nó definida
typedef struct node {
    int data; //Dado armazenado
    struct node* next; //Próximo nó
} tNode; 

//Estrutura da lista definida
typedef struct list {
    tNode* first_elem; // Nó identificado como primeiro elemento da lista
} tList; 

//Procedimento para inserir novos dados fornecidos à lista
void insert_list(tList *list, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode)); //Novo nó criado
    if (new_node == NULL) { //Se não há possibilidade de novo nó, é devolvido NULL para variável
        printf("Error: No space left in memory.\n"); 
        return;
    }

    new_node->data = new_data; //Valor adicionado ao nó
    new_node->next = list->first_elem; //Primeiro elemento da lista se torna o próximo valor do novo nó
    list->first_elem = new_node; //Novo nó se torna primeiro elemento
}

//Procedimento para liberar memória alocada da lista
void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp; //Variável auxiliar

    while (current != NULL) {
        temp = current; 
        current = current->next; 
        free(temp); 
    }

    list->first_elem = NULL;  //Libera primeiro elemento
}

//Procedimento para exibir valores da lista
void print_list(tList *list) {
    tNode* current = list->first_elem; //Variável de valor a ser apresentado inicia do primeiro elemento da lista

    printf("Elementos listados: ");
    while (current != NULL) { //Loop para apresentar lista completa
        printf("%d ", current->data);
        current = current->next;//Passa valor a ser apresentado para próximo nó
    }
    printf("\n");
}

//Função para criar lista
tList create_list() {
    tList list; //Lista criada
    list.first_elem = NULL;  //Primeiro elemento inicialmente vazio
    return list; 
}

int main(){
    int num;
    tList list = create_list(); // Criação da lista inicializada
    for (int i=0;i<5;i++){
        scanf("%d", &num); //Leitura de novos valores inseridos pelo teclado
        insert_list(&list, num); //Inserção de valor lido à lista
    }
    print_list(&list); //Apresentação da lista inicializada;

    free_list(&list);//Liberação de memória alocada inicializada;

    return 0;
}