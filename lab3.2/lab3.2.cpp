#include <iostream>
#include <vector>
#include <io.h>
#include <fcntl.h>

using namespace std;

int stirling(int n, int k) {
    if (n == k || k == 1) {
        return 1;
    }
    if (k == 0 || n == 0) {
        return 0;
    }
    return k * stirling(n - 1, k) + stirling(n - 1, k - 1);
}

int bell(int n) {
    vector<int> bellNumbers(n + 1);
    bellNumbers[0] = 1;

    for (int i = 1; i <= n; i++) {
        bellNumbers[i] = 0;
        for (int j = 0; j < i; j++) {
            bellNumbers[i] += stirling(i, j + 1);
        }
    }
    return bellNumbers[n];
}

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);

    int n = 7; 

    wcout << L"Таблиця чисел Стірлінга другого роду для n = " << n << L":\n";
    wcout << L"n\\k\t";
    for (int k = 1; k <= n; k++) {
        wcout << k << L"\t";
    }
    wcout << endl;

    for (int i = 1; i <= n; i++) {
        wcout << i << L"\t";
        for (int k = 1; k <= i; k++) {
            wcout << stirling(i, k) << L"\t";
        }
        wcout << endl;
    }

    wcout << L"\nЧисло Белла для n = " << n << L": " << bell(n) << endl;

    return 0;
}
