#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<std::vector<int>> createMatrix(int rows, int cols) {
    return std::vector<std::vector<int>>(rows, std::vector<int>(cols));
}

int sumColumn(const std::vector<std::vector<int>>& matrix, int col) {
    int sum = 0;
    for (const auto& row : matrix) {
        sum += row[col];
    }
    return sum;
}

int mulColumn(const std::vector<std::vector<int>>& matrix, int col) {
    int product = 1;
    for (const auto& row : matrix) {
        product *= row[col];
    }
    return product;
}

int calcColumns(const std::vector<std::vector<int>>& matrix) {
    int count = 0;
    for (size_t col = 0; col < matrix[0].size(); ++col) {
        if (sumColumn(matrix, col) < mulColumn(matrix, col)) {
            ++count;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));
    const int rowsX = 4, colsX = 5;
    const int rowsY = 3, colsY = 7;

    auto X = createMatrix(rowsX, colsX);
    auto Y = createMatrix(rowsY, colsY);

    for (auto& row : X) {
        for (auto& elem : row) {
            elem = rand() % 10;
        }
    }

    for (auto& row : Y) {
        for (auto& elem : row) {
            elem = rand() % 10;
        }
    }

    for (const auto& row : X) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    for (const auto& row : Y) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << calcColumns(X) << "\n";
    std::cout << calcColumns(Y) << "\n";

    return 0;
}