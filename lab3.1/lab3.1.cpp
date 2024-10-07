#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int arrangements(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int main() {

    _setmode(_fileno(stdout), _O_U8TEXT);

    int n = 5;  
    int r = 3;  

    int result = arrangements(n, r);

    wcout << L"Кількість розміщень без повторень для n = " << n << L" і r = " << r << L": " << result << endl;

    return 0;
}
