#include <stdio.h>
#include <windows.h>
#include <conio.h>



int main() {
    //Para resolução de 1920 x 1080
    int resolution_x = 1980;
    int resolution_y = 1080;
    int quadrant;

    POINT cursor_pos;
    while (1) {
        char ch;
        if (GetCursorPos(&cursor_pos)) {
            printf("Mouse Position: x=%d, y=%d\n", cursor_pos.x, cursor_pos.y);
        }
        quadrant = (cursor_pos.y < (resolution_y/2)) ? 
                        ((cursor_pos.x < (resolution_x/2)) ? 1 : 2) : 
                        ((cursor_pos.x < (resolution_x/2)) ? 3 : 4);
                  
        Sleep(100); // adjust the delay as needed
            switch (quadrant) {
            case 1:
                printf("Quadrant A\n");
                break;
            case 2:
                printf("Quadrant B\n");
                break;
            case 3:
                printf("Quadrant C\n");
                break;
            case 4:
                printf("Quadrant D\n");
                break;
        } 
        if (kbhit()) {
            ch = getch();
            if (ch == 27)
                break;
        }
    }
return 0;
}