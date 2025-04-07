clear all
close all
clc

set(gcf,'CurrentCharacter',' ') % empty current character 
resolution_x = 1600;
resolution_y = 900;
while true
    pos = get(0, 'PointerLocation');
    x = pos(1);
    y = pos(2);
    fprintf('Mouse Position: x=%d, y=%d\n', x, y);
    figure(1)
    switch true
         case (x < resolution_x/2 && y > resolution_y/2)
             disp('Quadrant A');
         case (x >= resolution_x/2 && y > resolution_y/2)
             disp('Quadrant B');
         case (x < resolution_x/2 && y <= resolution_y/2)
             disp('Quadrant C');
         otherwise
             disp('Quadrant D');
    end
    tic
    while toc<0.01
        ch = double(get(gcf,'CurrentCharacter')); % get ASCII code
    end
    if ~isempty(ch) && ch == 27 % 27 is ASCII for ESC key
        break
    end
end
close all