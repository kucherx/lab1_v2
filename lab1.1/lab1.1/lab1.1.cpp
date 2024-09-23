#include <iostream>
#include <Windows.h>
using namespace std;

// Функції для логічних операцій
bool getconjunction(bool p, bool q) {
    return p && q;  // Кон'юнкція
}

bool getdisjunction(bool p, bool q) {
    return p || q;  // Диз'юнкція
}

bool exclusive_or(bool p, bool q) {
    return p != q;  // Альтернативне "або"
}

bool implication(bool p, bool q) {
    return !p || q;  // Імплікація
}

bool equivalence(bool p, bool q) {
    return p == q;  // Еквівалентність
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool p, q;

    // Введення значень p та q
    cout << "Введіть значення для p (0 або 1): ";
    cin >> p;
    cout << "Введіть значення для q (0 або 1): ";
    cin >> q;

    // Виведення результатів
    cout << "Кон'юнкція (p && q): " << getconjunction(p, q) << endl;
    cout << "Диз'юнкція (p || q): " << getdisjunction(p, q) << endl;
    cout << "Альтернативне 'або' (p != q): " << exclusive_or(p, q) << endl;
    cout << "Імплікація (!p || q): " << implication(p, q) << endl;
    cout << "Еквівалентність (p == q): " << equivalence(p, q) << endl;

    return 0;
}
