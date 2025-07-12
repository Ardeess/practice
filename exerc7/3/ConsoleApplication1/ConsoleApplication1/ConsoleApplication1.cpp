#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void generateRandomArray(int arr[], int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}


bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void filterPrimes(int* src, int srcSize, int* dest, int& destSize) {
    destSize = 0;
    for (int i = 0; i < srcSize; i++) {
        if (isPrime(src[i])) {
            dest[destSize++] = src[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int primeArr[MAX_SIZE];
    int size, primeSize;

    cout << "Напиши размер массива: ";
    cin >> size;

    generateRandomArray(arr, size, 1, 100);

    cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    filterPrimes(arr, size, primeArr, primeSize);

    cout << "Простые числа: ";
    for (int i = 0; i < primeSize; i++) {
        cout << primeArr[i] << " ";
    }
    cout << endl;

    return 0;
}