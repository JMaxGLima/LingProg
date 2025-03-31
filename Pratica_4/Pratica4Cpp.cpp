#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {
    int resolution_x = 1980;
    int resolution_y = 1080;
    POINT cursor_pos;
    while (1) {
        char ch;
        if (GetCursorPos(&cursor_pos)) {
            printf("Mouse Position: x=%d, y=%d\n", cursor_pos.x, cursor_pos.y);
        }
        Sleep(100); // adjust the delay as needed
        if (cursor_pos.x < (resolution_x/2) && cursor_pos.y < (resolution_y/2)) {
            printf("Quadrant A\n");
        }
        else if (cursor_pos.x > (resolution_x/2) && cursor_pos.y < (resolution_y/2)){
            printf("Quadrant B\n");
        }
        else if (cursor_pos.x < (resolution_x/2) && cursor_pos.y > (resolution_y/2)){
            printf("Quadrant C\n");
        }
        else {
            printf("Quadrant D\n");
        }
        if (kbhit()) {
            ch = getch();
            if (ch == 27)
                break;
        }
    }
return 0;
}