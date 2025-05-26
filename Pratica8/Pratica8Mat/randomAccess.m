function randomAccess()
    % FUNÇÃO RANDOMACCESS
    % Demonstra acesso aleatório a arquivo binário
    %
    % Funcionamento:
    % 1. Cria/abre um arquivo binário chamado 'data.bin'
    % 2. Escreve um caractere em uma posição específica (posição 3)
    % 3. Lê o caractere da mesma posição para verificação
    % 4. Exibe o caractere lido
    %
    % Observações:
    % - Preenche as posições anteriores com zeros (ASCII 0)
    % - Mostra como posicionar o ponteiro do arquivo em posições específicas
    
    filename = 'data.bin';  % Nome do arquivo para operações
    
    try
        % Abre o arquivo para escrita e leitura binária (cria se não existir)
        fid = fopen(filename, 'wb+');
        if fid == -1
            error('Erro ao abrir o arquivo.');
        end
        
        position = 3;  % Posição onde será escrito o caractere
        ch = 'G';      % Caractere a ser escrito
        
        % Preenche o arquivo com zeros até a posição desejada
        for i = 0:position-1
            fwrite(fid, char(0), 'char');  % Escreve caractere nulo (ASCII 0)
        end
        
        % Escreve o caractere na posição especificada
        fwrite(fid, ch, 'char');
        
        % Reposiciona o ponteiro para ler o caractere escrito
        fseek(fid, position, 'bof');        % Move para a posição
        ch_read = fread(fid, 1, 'char');    % Lê o caractere
        
        % Exibe o resultado
        fprintf('\nDados lidos da posicao %d: %s\n', position, ch_read);
        
        fclose(fid);  % Fecha o arquivo
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo será fechado mesmo em caso de erro
        end
    end
end
