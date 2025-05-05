#include <iostream>

// Estrutura do nó da lista encadeada
struct Node {
    int data;
    Node* next;
};

// Lista encadeada
struct List {
    Node* head;
    Node* tail; // Necessário para a fila
};

// Inicializa uma lista vazia
void initList(List* list) {
    list->head = nullptr;
    list->tail = nullptr;
}

// Insere no início
void insertFront(List* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    
    if (list->tail == nullptr) {
        list->tail = newNode;
    }
}

// Insere no final 
void insertRear(List* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (list->tail == nullptr) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Remove do início
void removeFront(List* list) {
    if (list->head == nullptr) return;
    
    Node* temp = list->head;
    list->head = list->head->next;
    
    if (list->head == nullptr) {
        list->tail = nullptr;
    }
    
    delete temp;
}

// Funções para pilha (LIFO)
void push(List* stack, int value) {
    insertFront(stack, value);
}

void pop(List* stack) {
    removeFront(stack);
}

int top(List* stack) {
    if (stack->head == nullptr) return -1;
    return stack->head->data;
}

// Funções para fila (FIFO)
void enqueue(List* queue, int value) {
    insertRear(queue, value);
}

void dequeue(List* queue) {
    removeFront(queue);
}

int front(List* queue) {
    if (queue->head == nullptr) return -1;
    return queue->head->data;
}

// Imprime a lista
void printList(const List* list, const char* label) {
    std::cout << label << ": ";
    Node* current = list->head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Lista encadeada original
    List lista;
    initList(&lista);
    
    // Inserindo elementos na lista
    insertFront(&lista, 10);
    insertFront(&lista, 20);
    insertFront(&lista, 30);
    insertFront(&lista, 40);
    insertFront(&lista, 50);
    printList(&lista, "Lista original");
    
    // Utilizando como pilha
    List pilha;
    initList(&pilha);
    
    push(&pilha, 100);
    push(&pilha, 200);
    push(&pilha, 300);
    printList(&pilha, "Pilha (topo->base)");
    
    std::cout << "Topo da pilha: " << top(&pilha) << std::endl;
    pop(&pilha);
    printList(&pilha, "Pilha apos pop");
    
    // Utilizando como fila
    List fila;
    initList(&fila);
    
    enqueue(&fila, 1000);
    enqueue(&fila, 2000);
    enqueue(&fila, 3000);
    printList(&fila, "Fila (frente->tras)");
    
    std::cout << "Frente da fila: " << front(&fila) << std::endl;
    dequeue(&fila);
    printList(&fila, "Fila apos dequeue");
    
    return 0;
}