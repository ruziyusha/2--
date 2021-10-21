#include <iostream>
using namespace std;
void perevod(int x);
int main()
{
	int a;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число:" << endl;
	cin >> a;
	cout << "Двочная форма числа:";
	perevod(a);
	system("pause");
}
void perevod(int a)
{
	int b = a % 2;

	if (a >= 2)
		perevod(a / 2);
	cout << b;


}