#include <iostream>

using namespace std;


void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введи число для " << i + 1 <<" элемента" << ": ";
        cin >> arr[i];
    }
}


void outputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


bool isEven(int num) {
    return num % 2 == 0;
}

void removeEvenNumbers(int arr[], int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isEven(arr[i])) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    cout << "Введи размер массива : ";
    cin >> size;

    inputArray(arr, size);

    cout << "Введенный массив: ";
    outputArray(arr, size);

    removeEvenNumbers(arr, size);

    cout << "Массив после удаления четных чисел: ";
    outputArray(arr, size);

    return 0;
}