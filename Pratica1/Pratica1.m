% 
% Program: Linguagem de Programacao - Pratica 1.m
% 
% Author: Joao Max Germano Lima
% 
% Date: 16/03/2025
% 
% Description: Programa em MatLab desenvolvido para realizar calculos geometricos relacionados a circulos e retangulos.
% O usuario pode escolher entre duas opcoes: calcular o comprimento da circunferencia e a area de um circulo
% ou calcular o perimetro e a area de um retangulo. 
% 
% License: CC BY
% Update: 07/04/2025: Codigo alterado para pratica 4 adicionando loop "for" ate que tecla Esc seja pressionada para finalizar programa ao fim de cada loop

clc
clear all

% Definindo a constante PI manualmente
pi = 3.14;
set(gcf,'CurrentCharacter',' ') % empty current character 
for k = 1:Inf;
    disp('Escolha a opcao:');
    disp('1 - Calculos do circulo');
    disp('2 - Calculos do retangulo');

    % Le a opcao do usuario
    opcao = input('Digite sua escolha: ');

    if opcao == 1
        % Calculos relacionados ao circulo
        raio = input('Digite o valor do raio do circulo: ');

         % Calculando o comprimento e a area do circulo
        comprimento = 2 * pi * raio;
        area = pi * raio^2;

        % Exibindo os resultados
        fprintf('Comprimento da circunferencia: %.2f\n', comprimento);
        fprintf('area do circulo: %.2f\n', area);

    elseif opcao == 2
        % Calculos relacionados ao retangulo
        comprimento = input('Digite o comprimento do retangulo: ');
        largura = input('Digite a largura do retangulo: ');

      % Calculando o perimetro e a area do retangulo
        perimetro = 2 * (comprimento + largura);
        area = comprimento * largura;

        % Exibindo os resultados
        fprintf('Perimetro do retangulo: %.2f\n', perimetro);
        fprintf('area do retangulo: %.2f\n', area);

    else
        disp('Opcao invalida.');
    end
    key = waitforbuttonpress;
    if key == 1 % Se um botao foi pressionado
       ch = double(get(gcf,'CurrentCharacter')); % variavel em codigo ASCII
       if ch == 27 % 27 e ASCII para Esc
           fprintf('Programa encerrado\n');
           close all;
           break;
        end
    end
end
