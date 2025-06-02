try
    fileID = fopen('example.txt', 'r');
    if fileID == -1
        error('File opening failed');
    end

    % Your code here

    fclose(fileID);
catch ME
    disp(ME.message);
end

