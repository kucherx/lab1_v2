#include <iostream>
#include <vector>
#include <Windows.h>

// Функція для виведення поточної комбінації
void printCombination(const std::vector<int>& combination) {
    for (int num : combination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Рекурсивна функція для генерації комбінацій
void generateCombinations(int n, int r, int start, std::vector<int>& combination, std::vector<std::vector<int>>& result) {
    if (combination.size() == r) {
        result.push_back(combination); // Зберігаємо комбінацію в результат
        return;
    }

    for (int i = start; i <= n; ++i) {
        combination.push_back(i); // Додаємо елемент до комбінації
        generateCombinations(n, r, i + 1, combination, result); // Генеруємо наступні елементи
        combination.pop_back(); // Після завершення прибираємо останній елемент для наступних ітерацій
    }
}

// Обгортка для запуску генерації комбінацій
std::vector<std::vector<int>> generateAllCombinations(int n, int r) {
    std::vector<int> combination;
    std::vector<std::vector<int>> result;
    generateCombinations(n, r, 1, combination, result);
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, r;

    // Введення n і r
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;
    std::cout << "Введіть ціле число r (r <= n): ";
    std::cin >> r;

    std::vector<int> combination; // Вектор для зберігання поточної комбінації
    std::vector<std::vector<int>> result; // Вектор для зберігання всіх комбінацій

    // Генерація всіх r-сполучень
    generateCombinations(n, r, 1, combination, result);

    // Виведення всіх r-сполучень
    std::cout << "Усі можливі r-сполучення:\n";
    for (const auto& comb : result) {
        printCombination(comb); // Виведення кожної комбінації
    }

    return 0;
}
