

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double  exit, ps, pm, total, price_sysblock1, price_sysblock2, price_monitor1, price_monitor2, price_monitor3, price_mouse, price_keyboard;
    while (true) {
        cout << "Введите цену 1-го системного блока: ";
        cin >> price_sysblock1;
        cout << "Введите цену 2-го системного блока: ";
        cin >> price_sysblock2;
        cout << "Введите цену 1-го монитора: ";
        cin >> price_monitor1;
        cout << "Введите цену 2-го монитора: ";
        cin >> price_monitor2;
        cout << "Введите цену 3-го монитора: ";
        cin >> price_monitor3;
        cout << "Введите цену мышки: ";
        cin >> price_mouse;
        cout << "Введите цену клавиатуры: ";
        cin >> price_keyboard;
        ps = min(price_sysblock1, price_sysblock2);
        pm = min(price_monitor1, price_monitor2);
        pm = min(pm, price_monitor3);
        total = ps + pm + price_mouse + price_keyboard;
        cout << "Цена самого дешевого пк: " << total << endl;
        ps = max(price_sysblock1, price_sysblock2);
        pm = max(price_monitor1, price_monitor2);
        pm = max(pm, price_monitor3);
        total = ps + pm + price_mouse + price_keyboard;
        cout << "Цена самого дорогого пк: " << total << endl;
        cout << "Хотите выйти из программы?" << endl<<"1 - выйти"<<endl<<"0 - сделать еще один запрос";
        cin >> exit;
        if (exit == 1) {
            break;
        }
    }


}


