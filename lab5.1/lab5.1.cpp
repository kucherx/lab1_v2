#include <iostream>
#include <vector>
#include <tuple>
#include <windows.h>
#include <locale>

// Функція для отримання декартового добутку
std::vector<std::tuple<int, char, char>> getCartesianProduct(
    const std::vector<int>& C,
    const std::vector<char>& B,
    const std::vector<char>& A) {

    std::vector<std::tuple<int, char, char>> product;

    for (int c : C) {
        for (char b : B) {
            for (char a : A) {
                product.push_back(std::make_tuple(c, b, a));
            }
        }
    }
    return product;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "uk_UA.UTF-8");

    std::vector<char> A = { 'a', 'b', 'c' };
    std::vector<char> B = { 'x', 'y', 'z' };
    std::vector<int> C = { 0, 1 };

    auto product = getCartesianProduct(C, B, A);

    std::cout << "Dekartovyi dobutok C x B x A:\n";
    for (const auto& tuple : product) {
        std::cout << "(" << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << ")\n";
    }

    return 0;
}
