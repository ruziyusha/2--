#include <iostream>
#include<math.h>

using namespace std;

int perevod(int x, int n, int y);

int main()
{
	int a;
	int b = 0;
	int i = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число в двоичной системе:" << endl;
	cin >> a;
    cout << "Десятичная форма числа:" << perevod(a, b, i);
	system("pause");
}

int perevod(int a, int b, int i)
{
	if ((a % 10) != 0)

	{
		b = b + int(pow(2, i));

	}
	i++;
	if ((a / 10) > 0)
		b = perevod(a / 10, b, i);

	return(b);
}