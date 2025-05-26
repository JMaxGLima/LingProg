function parseCSV()
    % FUN��O PARSECSV
    % Analisa um arquivo CSV (valores separados por v�rgula)
    %
    % Funcionamento:
    % 1. Abre o arquivo 'test_file.txt' no diret�rio atual
    % 2. L� o arquivo linha por linha
    % 3. Divide cada linha pelos separadores (v�rgulas)
    % 4. Exibe cada token (valor entre v�rgulas) separadamente
    %
    % Observa��es:
    % - Remove espa�os em branco no in�cio e fim de cada token
    % - Considera que o arquivo usa v�rgula como separador
    
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
            line = fgetl(fid);  % L� uma linha do arquivo
            
            if ischar(line)  % Verifica se a linha � v�lida (n�o vazia)
                % Divide a linha pelos separadores (v�rgulas)
                tokens = strsplit(line, ',');
                
                % Exibe cada token (valor entre v�rgulas)
                for i = 1:length(tokens)
                    fprintf('%s\n', strtrim(tokens{i}));  % Remove espa�os e exibe
                end
            end
        end
        
        fclose(fid);  % Fecha o arquivo
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo ser� fechado mesmo em caso de erro
        end
    end
end