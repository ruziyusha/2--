#include <iostream>
using namespace std;
void razdelitel(int x);
int main()
{
	int a;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число:" << endl;
	cin >> a;
	razdelitel(a);
	system("pause");
}
void razdelitel(int a)
{
	int b = a % 10;

	if (a >= 10)
		razdelitel(a / 10);

	cout << b << " ";
}
