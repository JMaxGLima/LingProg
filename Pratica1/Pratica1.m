% 
% Program: Linguagem de Programacao - Pratica 1.m
% 
% Author: Joao Max Germano Lima
% 
% Date: 16/03/2025
% 
% Description: Programa em MatLab desenvolvido para realizar cálculos geométricos relacionados a círculos e retângulos.
% O usuário pode escolher entre duas opções: calcular o comprimento da circunferência e a área de um círculo
% ou calcular o perímetro e a área de um retângulo. 
% 
% License: CC BY

clc
clear all
% Definindo a constante PI manualmente
pi = 3.14;

disp('Escolha a opção:');
disp('1 - Cálculos do círculo');
disp('2 - Cálculos do retângulo');

% Lê a opção do usuário
opcao = input('Digite sua escolha: ');

if opcao == 1
    % Cálculos relacionados ao círculo
    raio = input('Digite o valor do raio do círculo: ');
    
     % Calculando o comprimento e a área do círculo
    comprimento = 2 * pi * raio;
    area = pi * raio^2;

    % Exibindo os resultados
    fprintf('Comprimento da circunferência: %.2f\n', comprimento);
    fprintf('Área do círculo: %.2f\n', area);

elseif opcao == 2
    % Cálculos relacionados ao retângulo
    comprimento = input('Digite o comprimento do retângulo: ');
    largura = input('Digite a largura do retângulo: ');
    
  % Calculando o perímetro e a área do retângulo
    perimetro = 2 * (comprimento + largura);
    area = comprimento * largura;

    % Exibindo os resultados
    fprintf('Perímetro do retângulo: %.2f\n', perimetro);
    fprintf('Área do retângulo: %.2f\n', area);

else
    disp('Opção inválida.');
end
