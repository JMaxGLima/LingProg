function handleBinaryData()
    % FUNÇÃO HANDLEBINARYDATA
    % Manipula dados binários (datas) gravando e lendo de/para arquivo
    %
    % Funcionamento:
    % 1. Solicita ao usuário o nome do arquivo para operações binárias
    % 2. Grava duas datas no arquivo em formato binário
    % 3. Lê as datas de volta do arquivo
    % 4. Exibe as datas lidas no formato DD/MM/AAAA
    %
    % Observações:
    % - As datas são armazenadas como vetores [dia, mês, ano]
    % - Usa inteiros de 32 bits para cada componente da data
    
    % Define as datas de exemplo (vetores [dia, mês, ano])
    d1 = [7, 9, 1999];  % Primeira data: 07/09/1999
    d2 = [12, 5, 2024]; % Segunda data: 12/05/2024
    
    % Solicita o nome do arquivo ao usuário
    filename = input('\nDigite o nome do arquivo para dados binarios: ', 's');
    
    try
        % OPERAÇÃO DE ESCRITA
        % Abre o arquivo para escrita binária
        fid = fopen(filename, 'wb');
        if fid == -1
            error('Erro! Não foi possível abrir o arquivo para escrita!');
        end
        
        % Escreve as datas no arquivo (cada componente como int32)
        fwrite(fid, d1, 'int32');  % Escreve a primeira data
        fwrite(fid, d2, 'int32');  % Escreve a segunda data
        fclose(fid);               % Fecha o arquivo
        
        % OPERAÇÃO DE LEITURA
        % Reabre o arquivo para leitura binária
        fid = fopen(filename, 'rb');
        if fid == -1
            error('Erro! Não foi possível abrir o arquivo para leitura!');
        end
        
        % Lê as datas do arquivo
        e1 = fread(fid, 3, 'int32')';  % Lê a primeira data (transposta para vetor linha)
        e2 = fread(fid, 3, 'int32')';  % Lê a segunda data (transposta para vetor linha)
        fclose(fid);                   % Fecha o arquivo
        
        % Exibe os resultados formatados
        fprintf('Primeira Data (DD/MM/AAAA): %02d/%02d/%d\n', e1(1), e1(2), e1(3));
        fprintf('Segunda Data (DD/MM/AAAA): %02d/%02d/%d\n', e2(1), e2(2), e2(3));
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo será fechado mesmo em caso de erro
        end
    end
end
