function handleBinaryData()
    % FUN��O HANDLEBINARYDATA
    % Manipula dados bin�rios (datas) gravando e lendo de/para arquivo
    %
    % Funcionamento:
    % 1. Solicita ao usu�rio o nome do arquivo para opera��es bin�rias
    % 2. Grava duas datas no arquivo em formato bin�rio
    % 3. L� as datas de volta do arquivo
    % 4. Exibe as datas lidas no formato DD/MM/AAAA
    %
    % Observa��es:
    % - As datas s�o armazenadas como vetores [dia, m�s, ano]
    % - Usa inteiros de 32 bits para cada componente da data
    
    % Define as datas de exemplo (vetores [dia, m�s, ano])
    d1 = [7, 9, 1999];  % Primeira data: 07/09/1999
    d2 = [12, 5, 2024]; % Segunda data: 12/05/2024
    
    % Solicita o nome do arquivo ao usu�rio
    filename = input('\nDigite o nome do arquivo para dados binarios: ', 's');
    
    try
        % OPERA��O DE ESCRITA
        % Abre o arquivo para escrita bin�ria
        fid = fopen(filename, 'wb');
        if fid == -1
            error('Erro! N�o foi poss�vel abrir o arquivo para escrita!');
        end
        
        % Escreve as datas no arquivo (cada componente como int32)
        fwrite(fid, d1, 'int32');  % Escreve a primeira data
        fwrite(fid, d2, 'int32');  % Escreve a segunda data
        fclose(fid);               % Fecha o arquivo
        
        % OPERA��O DE LEITURA
        % Reabre o arquivo para leitura bin�ria
        fid = fopen(filename, 'rb');
        if fid == -1
            error('Erro! N�o foi poss�vel abrir o arquivo para leitura!');
        end
        
        % L� as datas do arquivo
        e1 = fread(fid, 3, 'int32')';  % L� a primeira data (transposta para vetor linha)
        e2 = fread(fid, 3, 'int32')';  % L� a segunda data (transposta para vetor linha)
        fclose(fid);                   % Fecha o arquivo
        
        % Exibe os resultados formatados
        fprintf('Primeira Data (DD/MM/AAAA): %02d/%02d/%d\n', e1(1), e1(2), e1(3));
        fprintf('Segunda Data (DD/MM/AAAA): %02d/%02d/%d\n', e2(1), e2(2), e2(3));
        
    catch ME
        % Tratamento de erros
        fprintf('Erro: %s\n', ME.message);
        if exist('fid', 'var') && fid ~= -1
            fclose(fid);  % Garante que o arquivo ser� fechado mesmo em caso de erro
        end
    end
end
