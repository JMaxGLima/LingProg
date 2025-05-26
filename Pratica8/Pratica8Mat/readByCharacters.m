function readByCharacters()
    % FUNÇÃO READBYCHARACTERS
    % Lê um arquivo de texto caractere por caractere e exibe na tela
    %
    % Funcionamento:
    % 1. Abre o arquivo 'test_file.txt' no diretório atual
    % 2. Lê e exibe cada caractere individualmente
    % 3. Fecha o arquivo ao final ou em caso de erro
    
    filename = fullfile(pwd, 'test_file.txt');  % Cria o caminho completo para o arquivo
    
    try
        % Abre o arquivo em modo leitura
        fid = fopen(filename, 'r');
        if fid == -1
            error('Erro ao abrir o arquivo.');  % Lança erro se não conseguir abrir
        end
        
        fprintf('\nLendo caracteres um por um:\n');
        
        % Loop de leitura caractere por caractere
        while ~feof(fid)               % Enquanto não chegar ao final do arquivo
            ch = fscanf(fid, '%c', 1); % Lê um caractere
            fprintf('%s\n', ch);        % Exibe o caractere lido
        end
        
        fclose(fid);  % Fecha o arquivo
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo será fechado mesmo em caso de erro
        end
    end
end
