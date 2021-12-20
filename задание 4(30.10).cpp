#include <iostream>
#include<stdio.h>

using namespace std;

void print_array(int z,int *array);//z-длина массива
void progress(int x, int y, int z, int*array);
void perestanovka(int z, int* array);
void masrandom(int z, int*array);

int main()
{
	setlocale(LC_ALL, "Russian");

	int a0;
	cout << "Введите первый член арифметической прогрессии:";
	cin >> a0;

	int d;
	cout << "Разность арифметической прогрессии:";
	cin >> d;

	int N;
	cout << "Введите кол-во элементов массива(кол-во членов арифм. прогрессии):";
	cin >> N;

	int*mas = new int[N];

	progress(a0, d, N, mas);
	print_array(N, mas);
	perestanovka(N, mas);
	print_array(N, mas);
	masrandom(N, mas);
	print_array(N, mas);
	delete mas;


	system("pause");
}

	void print_array(int z, int*array)
	{
		for (int x = 0; x < z; x++)
			cout << array[x] << "  ";
		cout << endl;
		cout << endl;
	}

void progress(int x, int y, int z, int*array)
{
	int i = 0;
	int s = 0;
	while (i < z)
	{
		array[i] = x + y * s;
		i++;
		s++;
	}
}


void perestanovka(int z, int*array)
{
	int i = 0;
	while (i < z)
	{
		array[i] = i + 1;
		i++;
	}

	int u = 0;
	while (u < z)
	{
		int p = (rand() % z);
		int tmp = array[p];
		array[p] = array[u];
		array[u] = tmp;
		u++;
	}

}

void masrandom(int z, int*array)
{
	int i = 0;
	int g = 0;//понадобится для рассчета чисел со второй с конца четной цифрой
	while (i < z)
	{
		array[i] = (rand() % 1001 + 1000);
		if (((array[i] % 100) / 10) == 0 || ((array[i] % 100) / 10) == 2 || ((array[i] % 100) / 10) == 4 || ((array[i] % 100) / 10) == 6 || ((array[i] % 100) / 10) == 8)
		{
			g++;
		}

		i++;
	}
	cout << "Количество элементов, у которых 2-я с конца цифра четная,в 3-ем массиве:" << g << endl;
}




