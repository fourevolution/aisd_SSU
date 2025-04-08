#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m; 
    std::vector<std::vector<int>> A(n, std::vector<int>(m));

    // Построчный ввод матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] > 0) {
                A[i][j] *= 2;
            } else {
                A[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}