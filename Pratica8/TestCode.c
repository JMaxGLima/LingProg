/*

Programa: Linguagem de Programacao - Test.Code.c

Autor: Joao Max Germano Lima

Data: 26/05/2025

Descricao: Programa em C que demonstra diversas operacoes de manipulacao de arquivos, incluindo:
- Leitura caractere por caractere
- Leitura linha por linha
- Manipulacao de dados binarios (estruturas de data)
- Acesso aleatorio em arquivos
- Analise de arquivos CSV
O programa oferece uma interface com menu para o usuario selecionar e testar cada operacao.

Licenca: CC BY

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma data com dia, mes e ano
// Utilizada para demonstrar operacoes com arquivos binarios
struct data {
    int d, m, a;  // Dia, mes, ano
};

// Le um arquivo caractere por caractere e imprime cada um na saida padrao
// Demonstra leitura basica de arquivo no nivel mais baixo (byte por byte)
void read_characters() {
    FILE *file;
    char filename[100] = "C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt";  // Nome padrao do arquivo de entrada
    char character;

    // Abre o arquivo em modo leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nLendo caracteres um por um:\n");
    
    // Le ate chegar ao final do arquivo (EOF)
    while ((character = fgetc(file)) != EOF) {
        printf("%c\n", character); 
    }

    fclose(file);  // Sempre feche o manipulador de arquivo
}

// Le um arquivo linha por linha e imprime cada linha na saida padrao
// Demonstra leitura de arquivo em nivel mais alto usando buffers de linha
void read_lines() {
    FILE *file;
    char filename[100] = "C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt";  // Nome padrao do arquivo de entrada
    char line[100];  // Buffer para armazenar cada linha

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nLendo linhas uma por uma:\n");
    
    // Le ate nao haver mais linhas disponiveis
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);  // Nota: fgets inclui o caractere de nova linha
    }

    fclose(file);
}

// Demonstra operacoes com arquivos binarios escrevendo e lendo estruturas de data
// Mostra como lidar com dados estruturados em arquivos
void handle_binary_data() {
    // Inicializa datas de exemplo
    struct data d1 = {7, 9, 1999};
    struct data d2 = {12, 5, 2024};
    struct data e1, e2;  // Para ler os dados de volta
    FILE *file;
    char filename[30];

    printf("\nDigite o nome do arquivo para dados binarios: ");
    fgets(filename, 30, stdin);
    // Remove a quebra de linha do final do nome do arquivo
    filename[strlen(filename) - 1] = '\0';

    // Escreve dados binarios no arquivo
    if (!(file = fopen(filename, "wb"))) {
        printf("Erro! Nao foi possivel abrir o arquivo para escrita!\n");
        return;
    }
    fwrite(&d1, sizeof(struct data), 1, file);
    fwrite(&d2, sizeof(struct data), 1, file);
    fclose(file);

    // Le os dados binarios de volta do arquivo
    if (!(file = fopen(filename, "rb"))) {
        printf("Erro! Nao foi possivel abrir o arquivo para leitura!\n");
        return;
    }
    fread(&e1, sizeof(struct data), 1, file);
    fread(&e2, sizeof(struct data), 1, file);
    fclose(file);

    // Exibe os dados lidos
    printf("Primeira Data (DD/MM/AAAA): %d/%d/%d\n", e1.d, e1.m, e1.a);
    printf("Segunda Data (DD/MM/AAAA): %d/%d/%d\n", e2.d, e2.m, e2.a);
}

// Demonstra operacoes de acesso aleatorio em arquivos
// Mostra como usar fseek para acesso nao sequencial a arquivos
void random_access() {
    FILE *file;
    char data[100] = {0};  // Inicializa buffer com zeros
    int position = 3;  // Posicao para acesso aleatorio

    // Cria ou trunca o arquivo e abre para leitura e escrita
    file = fopen("data.bin", "wb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Move para a posicao especificada e escreve um caractere
    fseek(file, position * sizeof(data), SEEK_SET);
    fputc('G', file);
    fclose(file);

    // Reabre o arquivo para verificacao
    file = fopen("data.bin", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    // Move para a mesma posicao e le os dados
    fseek(file, position * sizeof(data), SEEK_SET);
    fread(data, sizeof(data), 1, file);
    printf("\nDados lidos da posicao %d: %s\n", position, data);
    fclose(file);
}

// Demonstra analise de arquivos CSV (Valores Separados por Virgula)
// Mostra como tokenizar cada linha usando strtok()
void parse_csv() {
    FILE *filePtr;
    char buffer[100];  // Buffer para cada linha
    char *token;  // Ponteiro para cada token na linha

    filePtr = fopen("C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt", "r");
    if (filePtr == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    printf("\nAnalisando conteudo CSV:\n");
    
    // Le o arquivo linha por linha
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL) {
        // Obtem o primeiro token usando virgula como delimitador
        token = strtok(buffer, ",");
        
        // Processa todos os tokens na linha atual
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");  // Obtem o proximo token
        }
    }

    fclose(filePtr);
}

// Exibe o menu do programa e trata a entrada do usuario
// @return Status de saida (0 para sucesso)
int main() {
    int choice;
    
    do {
        printf("\nMenu de Operacoes com Arquivos:\n");
        printf("1. Ler arquivo caractere por caractere\n");
        printf("2. Ler arquivo linha por linha\n");
        printf("3. Manipular dados binarios (datas)\n");
        printf("4. Acesso aleatorio a arquivo\n");
        printf("5. Analisar arquivo CSV\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // Limpa o buffer de entrada
        
        switch(choice) {
            case 1:
                read_characters();
                break;
            case 2:
                read_lines();
                break;
            case 3:
                handle_binary_data();
                break;
            case 4:
                random_access();
                break;
            case 5:
                parse_csv();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    } while(choice != 0);

    return 0;
}