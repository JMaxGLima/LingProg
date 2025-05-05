/*
Como a remoção em uma fila sempre ocorre no início (O(1)), 
mas a inserção no final em uma lista simplesmente encadeada seria O(n) 
(pois precisamos percorrer toda a lista para chegar ao último nó), 
uma otimização comum é manter um ponteiro adicional (rear) 
que sempre aponta para o último elemento, permitindo inserção em O(1).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

// Estrutura da fila (queue) com ponteiros para o início (front) e fim (rear)
typedef struct queue {
    tNode* front; 
    tNode* rear;  
} tQueue;

// Cria uma fila vazia
tQueue* create_queue() {
    tQueue* q = (tQueue*)malloc(sizeof(tQueue));
    if (q == NULL) {
        printf("Erro: Falha na alocação de memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL; 
    return q;
}

// Insere um elemento no final da fila
void insert_rear(tQueue* q, int x) {
    tNode* new_node = (tNode*)malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Falha na alocação de memória para o nó.\n");
        return;
    }
    new_node->data = x;
    new_node->next = NULL;

    if (q->rear == NULL) {  // Fila vazia
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;  
        q->rear = new_node;       
    }
}

// Remove e retorna o elemento do início da fila 
int remove_front(tQueue* q) {
    if (q->front == NULL) {
        printf("Erro: Fila vazia, não é possível remover.\n");
        exit(EXIT_FAILURE);
    }
    tNode* temp = q->front;     
    int data = temp->data;       
    q->front = q->front->next;  

    // Se a fila ficou vazia após a remoção, rear também deve ser NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);  
    return data;
}

// Verifica se a fila está vazia
int is_empty(tQueue* q) {
    return (q->front == NULL);
}

// Libera a memória da fila
void free_queue(tQueue* q) {
    while (!is_empty(q)) {
        remove_front(q); 
    }
    free(q); 
}

void print_queue(tQueue* q) {
    tNode* current = q->front;
    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    tQueue* fila = create_queue();

    insert_rear(fila, 10);
    insert_rear(fila, 20);
    insert_rear(fila, 30);
    print_queue(fila);  

    printf("Removido: %d\n", remove_front(fila)); 
    print_queue(fila); 

    insert_rear(fila, 40);
    print_queue(fila); 

    free_queue(fila);

    return 0;
}