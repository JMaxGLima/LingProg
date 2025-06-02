#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica10\\example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    // Your code here
    fclose(file);
    return EXIT_SUCCESS;
}
