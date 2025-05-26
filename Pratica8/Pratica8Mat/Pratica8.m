% Programa: Pratica8.m
% Autor: Joao Max Germano Lima
% Data: 26/05/2025
%
% Descrição: Programa principal que implementa um menu interativo para demonstrar
% diversas operações de manipulação de arquivos em MATLAB, incluindo:
% - Leitura caractere por caractere
% - Leitura linha por linha
% - Manipulação de dados binários (datas)
% - Acesso aleatório em arquivos
% - Análise de arquivos CSV
%
% Licença: CC BY

clc
clear all

% Exibe o menu e processa as opções do usuário em loop até que seja selecionada a opção de saída
    
choice = -1;  % Inicializa a variável de escolha do menu
    
% Loop principal do programa
while choice ~= 0
    displayMenu();              % Exibe o menu de opções
    choice = input('');         % Lê a escolha do usuário
    % Processa a escolha do usuário
    switch choice
        case 1
            readByCharacters();    % Opção 1: Leitura caractere por caractere
        case 2
            readByLines();          % Opção 2: Leitura linha por linha
        case 3 
            handleBinaryData();     % Opção 3: Manipulação de dados binários
        case 4
            randomAccess();         % Opção 4: Acesso aleatório a arquivo
        case 5
            parseCSV();             % Opção 5: Análise de arquivo CSV
        case 0
            fprintf('Saindo do programa.\n');  % Opção 0: Saída do programa
        otherwise
            fprintf('Opcao invalida. Por favor, tente novamente.\n'); % Tratamento de opção inválida
    end
end