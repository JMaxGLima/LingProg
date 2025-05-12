/*
Programa: Implementação de Árvore Binária de Busca
Autor: João Max Germano Lima
Data: 12 de Maio de 2025
Descrição: Implementação de uma árvore binária de busca com operações básicas
Licença: CC BY
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na BST
typedef struct node {
    int key;                // Chave armazenada no nó
    struct node *left;      // Ponteiro para o filho esquerdo
    struct node *right;     // Ponteiro para o filho direito
} tNode;

// Função para criar um novo nó
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode));
    if (new_node == NULL) {
        fprintf(stderr, "Erro: Impossível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Função para inserir um nó na BST
tNode *insert_node(tNode *root, int key) {
    // Se a árvore está vazia, cria novo nó
    if (root == NULL) {
        return create_node(key);
    }

    // Insere na subárvore esquerda se a chave for menor
    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } 
    // Insere na subárvore direita se for maior ou igual (permite duplicatas)
    else {  
        root->right = insert_node(root->right, key);
    }

    return root;
}

// Função para encontrar o nó com menor valor em uma subárvore
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    // Percorre até o nó mais à esquerda
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para remover um nó da BST
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Erro: A chave não está na árvore.\n");
        return root;
    }

    // Busca pelo nó a ser removido
    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } 
    else if (key > root->key) {
        root->right = remove_node(root->right, key);
    } 
    // Quando o nó é encontrado
    else {
        // Nó com apenas um filho ou sem filhos
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        // Nó com dois filhos: obtém o sucessor in-order
        tNode *temp = min_value_node(root->right);
        // Copia o valor do sucessor
        root->key = temp->key;
        // Remove o sucessor in-order
        root->right = remove_node(root->right, temp->key);
    }

    return root;
}

// Função para liberar a memória da árvore
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Função para percorrer a árvore em ordem (in-order traversal)
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

// Função para buscar um nó na BST
tNode* search_node(tNode* root, int k) {
    // Caso base: raiz nula ou chave encontrada
    if (root == NULL || root->key == k) {
        return root;
    }
    
    // Busca na subárvore esquerda se a chave for menor
    if (k < root->key) {
        return search_node(root->left, k);
    }
    // Busca na subárvore direita se for maior
    else {
        return search_node(root->right, k);
    }
}

int main() {
    tNode *root = NULL;
    tNode *result = NULL;
    
    printf("Construindo a árvore binária de busca...\n");
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    insert_node(root, 50); // Inserindo chave duplicada

    printf("\nÁrvore em ordem (in-order traversal): ");
    inorder_traversal(root);
    printf("\n");

    printf("\nRemovendo o valor 20 da árvore...\n");
    root = remove_node(root, 20);
    printf("Árvore após remoção: ");
    inorder_traversal(root);
    printf("\n");

    // Testando a busca com 3 chaves distintas
    int test_keys[] = {30, 55, 70};
    
    printf("\nTestando a função de busca:\n");
    for (int i = 0; i < 3; i++) {
        printf("Buscando chave %d: ", test_keys[i]);
        result = search_node(root, test_keys[i]);
        
        if (result != NULL) {
            printf("ENCONTRADA\n");
        } else {
            printf("NÃO ENCONTRADA\n");
        }
    }

    printf("\nLiberando memória da árvore...\n");
    delete_tree(root);
    printf("Memória liberada com sucesso!\n");

    return 0;
}