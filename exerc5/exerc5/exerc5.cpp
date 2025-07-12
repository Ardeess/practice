#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double K, M, S;

    cout << "Введите цену карамели за кг (руб.): ";
    cin >> K;
    cout << "Введите цену мармелада за кг (руб.): ";
    cin >> M;
    cout << "Введите цену шоколада за кг (руб.): ";
    cin >> S;

    cout << "\nВес (г) | Карамель (руб.) | Мармелад (руб.) | Шоколад (руб.)\n";
    cout << "--------+-----------------+-----------------+----------------\n";

    for (int weight = 100; weight <= 1000; weight += 100) {
        double weight_kg = weight / 1000.0; 

        cout << setw(7) << weight << " | "
            << fixed << setprecision(2) << setw(15) << K * weight_kg << " | "
            << setw(15) << M * weight_kg << " | "
            << setw(15) << S * weight_kg << endl;
    }

    return 0;
}