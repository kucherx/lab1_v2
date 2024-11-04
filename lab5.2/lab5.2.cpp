#include <iostream>
#include <bitset>
#include <windows.h>
#include <locale>

const int n = 8;  // Припустимо, що універсум має 8 елементів

// Функція для виведення бітового рядка у вигляді множини
void printSet(const std::bitset<n>& set, const std::string& label) {
    std::cout << label << " = { ";
    for (int i = 0; i < n; i++) {
        if (set[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "}\n";
}

// Операции над множествами
std::bitset<n> complement(const std::bitset<n>& set) {
    return ~set;
}

std::bitset<n> intersection(const std::bitset<n>& setA, const std::bitset<n>& setB) {
    return setA & setB;
}

std::bitset<n> unionSet(const std::bitset<n>& setA, const std::bitset<n>& setB) {
    return setA | setB;
}

std::bitset<n> difference(const std::bitset<n>& setA, const std::bitset<n>& setB) {
    return setA & ~setB;
}

std::bitset<n> symmetricDifference(const std::bitset<n>& setA, const std::bitset<n>& setB) {
    return setA ^ setB;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "uk_UA.UTF-8");

    std::bitset<n> A("10101010"); // Множина A: елементи {1, 3, 5, 7}
    std::bitset<n> B("11001100"); // Множина B: елементи {2, 3, 6, 7}

    printSet(A, "A");
    printSet(B, "B");
    printSet(complement(A), "Dopovnenya A");
    printSet(intersection(A, B), "Peretyn A ∩ B");
    printSet(unionSet(A, B), "Ob`ednannya A U B");
    printSet(difference(A, B), "Riznytsya A \\ B");
    printSet(symmetricDifference(A, B), "Symetrychna riznytsya A ⊕ B");

    return 0;
}
