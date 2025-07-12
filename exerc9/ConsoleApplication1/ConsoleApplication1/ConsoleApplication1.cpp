#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

// Функция сортировки одномерного массива по убыванию
void sortArrayDescending(int arr[], int size) {
    // Используем алгоритм сортировки выбором
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

// Функция для сортировки столбцов матрицы по убыванию
void sortMatrixColumnsDescending(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    // Создаем временный массив для столбца
    int* column = new int[rows];

    for (int j = 0; j < cols; j++) {
        // Копируем столбец во временный массив
        for (int i = 0; i < rows; i++) {
            column[i] = matrix[i][j];
        }

        // Сортируем временный массив
        sortArrayDescending(column, rows);

        // Копируем отсортированный массив обратно в столбец матрицы
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = column[i];
        }
    }

    delete[] column;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, m;
    cout << "Введите количество строк матрицы (n): ";
    cin >> n;
    cout << "Введите количество столбцов матрицы (m): ";
    cin >> m;

    // Создаем матрицу
    vector<vector<int>> matrix(n, vector<int>(m));

    // Заполняем матрицу
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    printMatrix(matrix);

    // Сортируем столбцы матрицы
    sortMatrixColumnsDescending(matrix);

    cout << "\nМатрица после сортировки столбцов по убыванию:" << endl;
    printMatrix(matrix);

    return 0;
}