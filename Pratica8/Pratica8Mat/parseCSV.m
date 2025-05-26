function parseCSV()
    % FUNÇÃO PARSECSV
    % Analisa um arquivo CSV (valores separados por vírgula)
    %
    % Funcionamento:
    % 1. Abre o arquivo 'test_file.txt' no diretório atual
    % 2. Lê o arquivo linha por linha
    % 3. Divide cada linha pelos separadores (vírgulas)
    % 4. Exibe cada token (valor entre vírgulas) separadamente
    %
    % Observações:
    % - Remove espaços em branco no início e fim de cada token
    % - Considera que o arquivo usa vírgula como separador
    
    filename = fullfile(pwd, 'test_file.txt');  % Cria o caminho completo para o arquivo
    
    try
        % Abre o arquivo para leitura
        fid = fopen(filename, 'r');
        if fid == -1
            error('Erro ao abrir arquivo');
        end
        
        fprintf('\nAnalisando conteudo CSV:\n');
        
        % Loop de leitura linha por linha
        while ~feof(fid)
            line = fgetl(fid);  % Lê uma linha do arquivo
            
            if ischar(line)  % Verifica se a linha é válida (não vazia)
                % Divide a linha pelos separadores (vírgulas)
                tokens = strsplit(line, ',');
                
                % Exibe cada token (valor entre vírgulas)
                for i = 1:length(tokens)
                    fprintf('%s\n', strtrim(tokens{i}));  % Remove espaços e exibe
                end
            end
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