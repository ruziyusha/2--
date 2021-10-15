#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0;
	int b = 1;
	int x;
	cout << "Введите число:" << endl;
	cin >> x;

	for (int c = 1; c <= (((x + 2 * (x % 2)) / 2) - 1); ++c)
	{
		a = a + b;
		b = a + b;
	}
	if (x % 2 == 0)
	{
		cout << x << "-oе число Фибоначчи: " << b;
	}
	else { cout << x << "-oе число Фибоначчи: " << a; }
	system("pause>nul");
	
	
}





