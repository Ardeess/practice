
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double K1, K2, K3;
	cin >> K1 >> K2 >> K3;
	if( (K1<=0)|| (K2 <= 0) || (K3 <= 0)){
		cout << "число не может быть равен нулю или меньше нулю";
	}
	else {
		cout << "Мышь " << "Крыса " << "Морская свинка";
		cout << endl;
		cout << K1 << " " << K2 << " " << K3;
		cout << endl;
		cout << "В день: " << K1 + K2 + K3;
		cout << endl;
		cout << "В месяц: " << (K1 + K2 + K3) * 30;
	}
}
