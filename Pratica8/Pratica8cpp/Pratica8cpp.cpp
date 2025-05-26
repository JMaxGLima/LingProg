/*
Programa: Linguagem de Programacao - Pratica8.cpp
Autor: Joao Max Germano Lima
Data: 26/05/2025
Descricao: Programa em C++ que demonstra diversas operacoes de manipulacao de arquivos, incluindo:
- Leitura caractere por caractere
- Leitura linha por linha
- Manipulacao de dados binarios (estruturas de data)
- Acesso aleatorio em arquivos
- Analise de arquivos CSV
O programa oferece uma interface com menu para o usuario selecionar e testar cada operacao.

Licenca: CC BY
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Estrutura que representa uma data com dia, mes e ano
struct Date {
    int day, month, year;

    // Construtor padrão
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
};

// Função para ler um arquivo caractere por caractere
void readByCharacters() {
    string filename = "C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    cout << "\nLendo caracteres um por um:\n";
    
    char ch;
    while (file.get(ch)) {
        cout << ch << endl;
    }

    file.close();
}

// Função para ler um arquivo linha por linha
void readByLines() {
    string filename = "C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    cout << "\nLendo linhas uma por uma:\n";
    
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

// Função para manipular dados binários (datas)
void handleBinaryData() {
    Date d1{7, 9, 1999};
    Date d2{12, 5, 2024};
    Date e1, e2;
    string filename;

    cout << "\nDigite o nome do arquivo para dados binarios: ";
    getline(cin, filename);

    // Escreve dados binários no arquivo
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Erro! Não foi possível abrir o arquivo para escrita!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<char*>(&d1), sizeof(Date));
    outFile.write(reinterpret_cast<char*>(&d2), sizeof(Date));
    outFile.close();

    // Lê os dados binários de volta
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Erro! Não foi possível abrir o arquivo para leitura!" << endl;
        return;
    }
    inFile.read(reinterpret_cast<char*>(&e1), sizeof(Date));
    inFile.read(reinterpret_cast<char*>(&e2), sizeof(Date));
    inFile.close();

    // Exibe os dados lidos
    cout << "Primeira Data (DD/MM/AAAA): " 
         << setw(2) << setfill('0') << e1.day << "/"
         << setw(2) << setfill('0') << e1.month << "/"
         << e1.year << endl;
    cout << "Segunda Data (DD/MM/AAAA): "
         << setw(2) << setfill('0') << e2.day << "/"
         << setw(2) << setfill('0') << e2.month << "/"
         << e2.year << endl;
}

// Função para demonstração de acesso aleatório
void randomAccess() {
    fstream file("data.bin", ios::in | ios::out | ios::binary | ios::trunc);
    if (!file) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    int position = 3;
    char ch = 'G';

    // Move para a posição especificada e escreve um caractere
    file.seekp(position * sizeof(ch), ios::beg);
    file.write(&ch, sizeof(ch));
    file.close();

    // Reabre para verificação
    file.open("data.bin", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    // Move para a mesma posição e lê os dados
    file.seekg(position * sizeof(ch), ios::beg);
    file.read(&ch, sizeof(ch));
    cout << "\nDados lidos da posicao " << position << ": " << ch << endl;
    file.close();
}

// Função para análise de arquivos CSV
void parseCSV() {
    string filename = "C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica8\\test_file.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir arquivo" << endl;
        return;
    }

    cout << "\nAnalisando conteudo CSV:\n";
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        
        while (getline(ss, token, ',')) {
            cout << token << endl;
        }
    }

    file.close();
}

// Função para exibir o menu
void displayMenu() {
    cout << "\nMenu de Operacoes com Arquivos:\n";
    cout << "1. Ler arquivo caractere por caractere\n";
    cout << "2. Ler arquivo linha por linha\n";
    cout << "3. Manipular dados binarios (datas)\n";
    cout << "4. Acesso aleatorio a arquivo\n";
    cout << "5. Analisar arquivo CSV\n";
    cout << "0. Sair\n";
    cout << "Digite sua opcao: ";
}

int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Limpa o buffer de entrada
        
        switch(choice) {
            case 1:
                readByCharacters();
                break;
            case 2:
                readByLines();
                break;
            case 3:
                handleBinaryData();
                break;
            case 4:
                randomAccess();
                break;
            case 5:
                parseCSV();
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
    } while(choice != 0);

    return 0;
}