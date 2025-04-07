#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int num, i;
    float square_root;
    float power;
    unsigned long long factorial;
    cout << "Operations on a number:" << endl;
    cout << "Type a number: ";
    cin >> num;

    for (i=1;i<=num;i++) {
        factorial *= i;
    }
    
    square_root = sqrt(num);
    power = pow(num, 2);
    
    cout << fixed << setprecision(2);
    cout << "The factorial of the number is: " << (double)factorial << endl;
    cout << "The square root of the number is: " << square_root << endl;
    cout << "The number raised to the power of 2 is: " << power << endl;

    return 0;
}