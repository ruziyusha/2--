#include <iostream>
#include<ctime>

using namespace std;

void random_array(int**MAT, int n, int m);
void print_array(int**MAT, int n, int m);
void swap_strings(int**MAT, int n, int m);
int x_chet(int**MAT, int n, int m, int x);
void sum_column(int**MAT, int n, int m, int p);
void obnuleniye(int**MAT, int n, int m);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int n, m;

	cout << "Введите количество строк в матрице:";
	cin >> n;
	cout << endl;

	cout << "Введите количество столбцов в матрице:";
	cin >> m;
	cout << endl;

	int **MAT;
	MAT = new int*[n];
	for (int i = 0; i < n; i++)
		MAT[i] = new int[m];


	random_array(MAT, n, m);
	print_array(MAT, n, m);

	swap_strings(MAT, n, m);
	cout << "1) Поменяем любые две строки местами:" << endl;
	print_array(MAT, n, m);

	int x;
	cout << "2) Введите целое число х в диапазоне[-100;100]:";
	cin >> x;
	cout << "Число " << x << " встречается в матрице " << x_chet(MAT, n, m, x) << " раз." << endl;
	cout << endl;

	cout << "3) Сумма элементов в каждом столбце:" << endl;
	int p = 0;
	sum_column(MAT, n, m, p);
	cout << endl;

	obnuleniye(MAT, n, m);
	
	system("pause");
}

int random_number()
{
	return rand();
}

void random_array(int**MAT, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < m; p++)
			MAT[i][p] = random_number() % 201 - 100;
	}
}

void print_array(int**MAT, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < m; p++)
		{
			cout << MAT[i][p] << "  ";
		}
		cout << endl;
	}
	cout << endl;

}

void swap_strings(int**MAT, int n, int m)
{
	int d = random_number() % n;
	int p = random_number() % n;

	while (d == p)
	{
		p = rand() % n;
	}

	for (int i = 0; i < m; i++)
	{
		int tmp = MAT[d][i];
		MAT[d][i] = MAT[p][i];
		MAT[p][i] = tmp;
	}

}

int x_chet(int**MAT, int n, int m, int x)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < m; p++)
		{
			if (MAT[i][p] == x)
				k += 1;
		}

	}
	return k;
}

void sum_column(int**MAT, int n, int m, int p)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		//int sum = 0;
		sum += MAT[i][p];
	}
	cout << "Сумма элементов " << p + 1 << "-го столбца равна " << sum << endl;
	p++;

	if (p < m)
		sum_column(MAT, n, m, p);

}

void obnuleniye(int**MAT, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < m; p++)
			MAT[i][p] = 0;
	}
}