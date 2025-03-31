clear all
close all
clc

% In this code you have to click above the figure
set(gcf,'CurrentCharacter',' ') % empty current character 
resolution_x = 1980
resolution_y = 1080
while true
    pos = get(0, 'PointerLocation');
    x = pos(1);
    y = pos(2);
    fprintf('Mouse Position: x=%d, y=%d\n', x, y);

    figure(1)
    % Adjust the delay as needed
     switch true
            case (x < resolution_x/2 && y < resolution_y/2)
                disp('Quadrant A');
            case (x >= resolution_x/2 && y < resolution_y/2)
                disp('Quadrant B');
            case (x < resolution_x/2 && y >= resolution_y/2)
                disp('Quadrant C');
            otherwise
                disp('Quadrant D');
        end
    tic
    while toc<0.01
        ch = get(gcf,'CurrentCharacter');
    end
    if(ch=='escape')
        break
    end
end