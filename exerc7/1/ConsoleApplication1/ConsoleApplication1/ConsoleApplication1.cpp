#include <iostream>
#include <climits>

using namespace std;

int findMin(int arr[], int size) {
    int minVal = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(int arr[], int size) {
    int maxVal = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void swapMinMax(int arr[], int size) {
    int minVal = findMin(arr, size);
    int maxVal = findMax(arr, size);

    for (int i = 0; i < size; i++) {
        if (arr[i] == minVal) {
            swap(arr[0], arr[i]);
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == maxVal) {
            swap(arr[size - 1], arr[i]);
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 5, 2, 8, 1, 9, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    swapMinMax(arr, size);

    cout << "измененный массив : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}