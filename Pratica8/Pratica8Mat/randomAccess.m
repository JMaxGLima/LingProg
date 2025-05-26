function randomAccess()
    % FUN��O RANDOMACCESS
    % Demonstra acesso aleat�rio a arquivo bin�rio
    %
    % Funcionamento:
    % 1. Cria/abre um arquivo bin�rio chamado 'data.bin'
    % 2. Escreve um caractere em uma posi��o espec�fica (posi��o 3)
    % 3. L� o caractere da mesma posi��o para verifica��o
    % 4. Exibe o caractere lido
    %
    % Observa��es:
    % - Preenche as posi��es anteriores com zeros (ASCII 0)
    % - Mostra como posicionar o ponteiro do arquivo em posi��es espec�ficas
    
    filename = 'data.bin';  % Nome do arquivo para opera��es
    
    try
        % Abre o arquivo para escrita e leitura bin�ria (cria se n�o existir)
        fid = fopen(filename, 'wb+');
        if fid == -1
            error('Erro ao abrir o arquivo.');
        end
        
        position = 3;  % Posi��o onde ser� escrito o caractere
        ch = 'G';      % Caractere a ser escrito
        
        % Preenche o arquivo com zeros at� a posi��o desejada
        for i = 0:position-1
            fwrite(fid, char(0), 'char');  % Escreve caractere nulo (ASCII 0)
        end
        
        % Escreve o caractere na posi��o especificada
        fwrite(fid, ch, 'char');
        
        % Reposiciona o ponteiro para ler o caractere escrito
        fseek(fid, position, 'bof');        % Move para a posi��o
        ch_read = fread(fid, 1, 'char');    % L� o caractere
        
        % Exibe o resultado
        fprintf('\nDados lidos da posicao %d: %s\n', position, ch_read);
        
        fclose(fid);  % Fecha o arquivo
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo ser� fechado mesmo em caso de erro
        end
    end
end
