    clc
    close all
    clear all
    % ====== LISTA (array) ======
    disp('=== LISTA (array) ===');
    lista = [50, 40, 30, 20, 10];
    
    disp(['Lista: ', num2str(lista)]);
    
    lista(3) = [];
    disp(['Lista ap�s remover terceiro elemento: ', num2str(lista)]);
    disp(' ');
    
    % ====== PILHA (usando array) ======
    disp('=== PILHA (array) ===');
    pilha = [];
    
    % Empilhar elementos (adicionar no final)
    for elemento = lista
        pilha = [pilha, elemento];
    end
    
    disp(['Pilha): ', num2str(fliplr(pilha))]);
    disp(['Topo da pilha: ', num2str(pilha(end))]);
    
    % Desempilhar (remover do final)
    pilha = pilha(1:end-1);
    disp(['Pilha ap�s pop:: ', num2str(fliplr(pilha))]);
    disp(' ');
    
    % ====== FILA (usando array) ======
    disp('=== FILA (array) ===');
    fila = [];
    
    % Enfileirar elementos (adicionar no final)
    for elemento = lista
        fila = [fila, elemento];
    end
    
    disp(['Fila: ', num2str(fila)]);
    disp(['Frente da fila: ', num2str(fila(1))]);
    
    % Desenfileirar (remover do in�cio)
    fila = fila(2:end);
    disp(['Fila ap�s pop: ', num2str(fila)]);
