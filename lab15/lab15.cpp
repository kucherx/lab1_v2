#include <iostream>
#include <vector>
#include <cmath>
#include<Windows.h>

using namespace std;

int N;
vector<vector<int>> board;
vector<vector<vector<int>>> solutions;

void printChessBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] == 1 ? (cout << "Q ") : (cout << ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void printAllSolutions() {
    if (solutions.empty()) {
        cout << "Рішення не знайдено!" << endl;
    }
    else {
        cout << "Знайдено " << solutions.size() << " рішень:" << endl;
        for (size_t i = 0; i < solutions.size(); i++) {
            cout << "Рішення номер " << i + 1 << ":" << endl;
            printChessBoard(solutions[i]);
        }
    }
}

bool canPlaceQueen(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1 && (abs(row - i) == abs(col - j))) {
                return false;
            }
        }
    }

    return true;
}

bool solveUtility(int row, int columnMask, int diag1Mask, int diag2Mask) {
    if (row == N) {
        solutions.push_back(board);
        return false;
    }

    int availablePositions = ~(columnMask | diag1Mask | diag2Mask) & ((1 << N) - 1);

    while (availablePositions) {
        int col = availablePositions & -availablePositions;
        unsigned long index;
        _BitScanForward(&index, col);

        board[row][index] = 1;
        solveUtility(row + 1, columnMask | col, (diag1Mask | col) << 1, (diag2Mask | col) >> 1);
        board[row][index] = 0;

        availablePositions &= availablePositions - 1;
    }

    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть розмір шахівниці: ";
    cin >> N;

    if (cin.fail()) {
        cerr << "Розмір шахівниці неправильно введено." << endl;
        return 1;
    }

    board = vector<vector<int>>(N, vector<int>(N, 0));

    solveUtility(0, 0, 0, 0);
    printAllSolutions();

    return 0;
}
