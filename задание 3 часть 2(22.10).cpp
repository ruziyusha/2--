#include <iostream>
using namespace std;
void mnogit(int x,int n);
int main()
{
	int a;
	int b = 2;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число:" << endl;
	cin >> a;
	cout <<"Простые множители";
    mnogit(a,b);
	system("pause");
}
void mnogit(int a,int b)
{
	
	while (a%b == 0)
	{
		a = a / b;
			cout << b<<"*";
	}
	if (a>=b)
	mnogit(a, b + 1);


}
