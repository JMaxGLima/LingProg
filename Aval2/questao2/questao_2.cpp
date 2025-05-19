/*Program: Linguagem de Programacao - Avaliação 2 (questao_2.cpp)

Author: Joao Max Germano Lima

Date: 19/05/2025

Description: Programa em C++ desenvolvido para criar uma matriz 2x4,
preencher com 8 valores a partir do teclado e exibir a matriz.

License: CC BY
*/
#include <iostream>

#include <vector>
    
int main() {

    int cols = 4; //Número de colunas definidas

    int rows = 2; //Número de linhas definidas

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols)); //Criação de matriz

    for (size_t i = 0; i < matrix.size(); i++) { //Loop para inserção de valores à matriz
        for (size_t j = 0; j < matrix[i].size(); j++) {
            std::cin >> matrix[i][j]; //Leitura de valores para matriz
        }
    }
    std::cout << std::endl;

    for (size_t i = 0; i < matrix.size(); i++) {//Loop para exibição de valores da matriz
        for (size_t j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " "; //Apresentação de valor da matriz na coordenada ixj  
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;

}