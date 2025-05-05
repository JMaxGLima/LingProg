#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

// Estrutura da fila (queue) com ponteiros para o início (front) e fim (rear)
typedef struct queue {
    tNode* front;  // Primeiro elemento (para remoção)
    tNode* rear;   // Último elemento (para inserção)
} tQueue;

// Cria uma fila vazia
tQueue* create_queue() {
    tQueue* q = (tQueue*)malloc(sizeof(tQueue));
    if (q == NULL) {
        printf("Erro: Falha na alocação de memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;  // Fila vazia
    return q;
}

// Insere um elemento no final da fila (O(1) devido ao ponteiro rear)
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
        q->rear->next = new_node;  // Liga o último nó ao novo nó
        q->rear = new_node;        // Atualiza o ponteiro rear
    }
}

// Remove e retorna o elemento do início da fila (O(1))
int remove_front(tQueue* q) {
    if (q->front == NULL) {
        printf("Erro: Fila vazia, não é possível remover.\n");
        exit(EXIT_FAILURE);
    }
    tNode* temp = q->front;      // Nó a ser removido
    int data = temp->data;       // Salva o dado antes de liberar memória
    q->front = q->front->next;   // Atualiza o ponteiro front

    // Se a fila ficou vazia após a remoção, rear também deve ser NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);  // Libera o nó removido
    return data;
}

// Verifica se a fila está vazia
int is_empty(tQueue* q) {
    return (q->front == NULL);
}

// Libera a memória da fila
void free_queue(tQueue* q) {
    while (!is_empty(q)) {
        remove_front(q);  // Remove todos os elementos
    }
    free(q);  // Libera a estrutura da fila
}

// Imprime a fila (para debug)
void print_queue(tQueue* q) {
    tNode* current = q->front;
    printf("Fila (frente -> fim): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    tQueue* fila = create_queue();

    // Testando insert_rear e remove_front
    insert_rear(fila, 10);
    insert_rear(fila, 20);
    insert_rear(fila, 30);
    print_queue(fila);  // Saída: 10 20 30

    printf("Removido: %d\n", remove_front(fila));  // Remove 10
    print_queue(fila);  // Saída: 20 30

    insert_rear(fila, 40);
    print_queue(fila);  // Saída: 20 30 40

    // Libera memória
    free_queue(fila);

    return 0;
}