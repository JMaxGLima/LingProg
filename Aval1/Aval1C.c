#include <stdio.h>
#include <math.h>

int main() {
    int num, i;
    double square_root, power;
    unsigned long long factorial = 1;
    printf("Operations on a number:\n");
    printf("Type a number: ");
    scanf("%d", &num);
    for (i=1;i<=num;i++) {
        factorial *= i;
    }
    square_root = sqrt(num);
    power = pow(num,2);
    printf("The factorial of the number is: %.2f\n", (double)factorial);
    printf("The square root of the number is: %.2f\n", square_root);
    printf("The number raised to the power of 2 is: %.2f\n", power);
    return 0;
}