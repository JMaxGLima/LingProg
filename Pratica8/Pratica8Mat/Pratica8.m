% Programa: Pratica8.m
% Autor: Joao Max Germano Lima
% Data: 26/05/2025
%
% Descri��o: Programa principal que implementa um menu interativo para demonstrar
% diversas opera��es de manipula��o de arquivos em MATLAB, incluindo:
% - Leitura caractere por caractere
% - Leitura linha por linha
% - Manipula��o de dados bin�rios (datas)
% - Acesso aleat�rio em arquivos
% - An�lise de arquivos CSV
%
% Licen�a: CC BY

clc
clear all

% Exibe o menu e processa as op��es do usu�rio em loop at� que seja selecionada a op��o de sa�da
    
choice = -1;  % Inicializa a vari�vel de escolha do menu
    
% Loop principal do programa
while choice ~= 0
    displayMenu();              % Exibe o menu de op��es
    choice = input('');         % L� a escolha do usu�rio
    % Processa a escolha do usu�rio
    switch choice
        case 1
            readByCharacters();    % Op��o 1: Leitura caractere por caractere
        case 2
            readByLines();          % Op��o 2: Leitura linha por linha
        case 3 
            handleBinaryData();     % Op��o 3: Manipula��o de dados bin�rios
        case 4
            randomAccess();         % Op��o 4: Acesso aleat�rio a arquivo
        case 5
            parseCSV();             % Op��o 5: An�lise de arquivo CSV
        case 0
            fprintf('Saindo do programa.\n');  % Op��o 0: Sa�da do programa
        otherwise
            fprintf('Opcao invalida. Por favor, tente novamente.\n'); % Tratamento de op��o inv�lida
    end
end