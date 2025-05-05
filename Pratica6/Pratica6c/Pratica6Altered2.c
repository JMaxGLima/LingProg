/*Para implementar uma pilha (stack) usando a lista encadeada,
precisamos definir um tipo tStack que terá um ponteiro para o topo da pilha. 
Como estamos trabalhando com uma pilha (LIFO - Last In First Out), 
todas as operações (push e pop) devem ser feitas no mesmo extremo da lista para eficiência.
Neste caso, o topo da pilha será o primeiro elemento da lista (first_elem), pois isso permite inserção e remoção em tempo constante O(1).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct list {
    tNode* first_elem;
} tList;

typedef struct stack {
    tList* list; 
} tStack;

tStack* create_stack() {
    tStack* stack = (tStack*)malloc(sizeof(tStack));
    if (stack == NULL) {
        printf("Erro: Falha na alocação de memória para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    stack->list = (tList*)malloc(sizeof(tList));
    if (stack->list == NULL) {
        printf("Erro: Falha na alocação de memória para a lista.\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    stack->list->first_elem = NULL;  
    return stack;
}

void push(tStack* stack, int x) {
    tNode* new_node = (tNode*)malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Falha na alocação de memória para o nó.\n");
        return;
    }
    new_node->data = x;
    new_node->next = stack->list->first_elem;  
    stack->list->first_elem = new_node;        
}

int pop(tStack* stack) {
    if (stack->list->first_elem == NULL) {
        printf("Erro: Pilha vazia, não é possível fazer pop.\n");
        exit(EXIT_FAILURE);
    }
    tNode* top_node = stack->list->first_elem;  
    int data = top_node->data;                 
    stack->list->first_elem = top_node->next;    
    free(top_node);                            
    return data;
}

void free_stack(tStack* stack) {
    tNode* current = stack->list->first_elem;
    while (current != NULL) {
        tNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack->list);
    free(stack);
}

void print_stack(tStack* stack) {
    tNode* current = stack->list->first_elem;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    tStack* pilha = create_stack();

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);
    print_stack(pilha); 

    printf("Removido: %d\n", pop(pilha));  
    print_stack(pilha); 

    push(pilha, 40);
    print_stack(pilha); 

    free_stack(pilha);

    return 0;
}