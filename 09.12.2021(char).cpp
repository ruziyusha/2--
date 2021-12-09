#include<iostream>
#include<cmath>
#include<windows.h>

using namespace std;

int symbols(char *pal, int a);
int letter_symbols(char *pal, int i);
void palindrom(char *pal, int bukvi, int i);
void schet(char*primer, int f);
void inicials(char*fio, char*fio1, int c);

int main()
{   //введём русский язык
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//создадим символьный массив для фразы-палиндрома
	int a = 120;
	char* pal = new char[a];
	cout << "1)Введите фразу:" << endl;
	cin.getline(pal, a);

	//эта функция считает количество введенных символов 
	int i = symbols(pal, a);

	//эта функция считает количество буквенных символов
	int bukvi = letter_symbols(pal, i);

	//эта функция определяет палиндромы
	palindrom(pal, bukvi, i);
	cout << endl;


	//создадим символьный массив для примера
	int b = 25;
	char* primer = new char[b];
	cout << "2)Введите пример,содержащий только знак сложения:" << endl;
	cin.getline(primer, b);

	//эта функция считает количество введенных символов
	int f = symbols(primer, b);

	//эта функция найдет сумму
	schet(primer, f);
	cout << endl;


	//создадим символьный массив для фио
	int o = 50;
	char* fio = new char[o];
	cout << "Введите фио полностью:";
	cin.getline(fio,o);

	//эта функция считает количество введенных символов
	int c = symbols(fio,o);

	//фамилия с инициалами
	int w = 25;
	char* fio1 = new char[w];

	inicials(fio, fio1, c);

	//выводим на экран 
	int l = symbols(fio1, w);
	for (int y = 0; y <= l - 1;y++)
		cout << fio1[y];

	system("pause");
}

int symbols(char *pal, int a)
{
	// "\0"-последний символ в строке(определим его номер)
	while (pal[a] != '\0')
	{
		a--;
	}
	int i = a;
	return i;
}

int letter_symbols(char *pal, int i)
{
	int bukvi = i;
	while ((i - 1) >= 0)
	{
		if (pal[i - 1] == ' ' || pal[i - 1] == '?' || pal[i - 1] == '!' || pal[i - 1] == ',' || pal[i - 1] == '-' || pal[i - 1] == '.' || pal[i - 1] == ';' || pal[i - 1] == ':' || pal[i - 1] == '"')
		{
			bukvi--;
		}
		i--;
	}
	return bukvi;
}


void palindrom(char *pal, int bukvi, int i)
{
	int идентификатор_палиндрома = 0;
	int k = 0;
	for (int l = 1; l <= ((bukvi) / 2); l++)
	{
		while (pal[i - 1] == ' ' || pal[i - 1] == '?' || pal[i - 1] == '!' || pal[i - 1] == ',' || pal[i - 1] == '-' || pal[i - 1] == '.' || pal[i - 1] == ';' || pal[i - 1] == ':' || pal[i - 1] == '"')
			i--;

		while (pal[k] == ' ' || pal[k] == '?' || pal[k] == '!' || pal[k] == ',' || pal[k] == '-' || pal[k] == '.' || pal[k] == ';' || pal[k] == ':' || pal[k] == '"')
			k++;

		if (pal[i - 1] == pal[k])
		{
			идентификатор_палиндрома++;
		}
		i--;
		k++;

	}
	if (идентификатор_палиндрома == (bukvi) / 2)
		cout << "ПАЛИНДРОМ";
	else cout << " НЕ ПАЛИНДРОМ";
}

void schet(char*primer, int f)
{
	int s = 0;
	int h = 0;
	for (int y = f - 1; y >= 0; y--)
	{
		if (primer[y] != '+')
		{
			s += (int(primer[y])-48)*int(pow(10, h));
			h++;
		}
		else h = 0;
	}
	cout << "Сумма:" << s;
}


void inicials(char*fio, char*fio1, int c)

{

	for (int i = 0; i <= c; i++)
	{
		int h = 0;
		int o = 0;

		if (fio[i] == ' '&&o == 1)
		{
			o++;
			fio1[i] = '.';
			h++;
		}

		if (fio[i] == ' '&&o == 0)
		{
			o++;
			fio1[i] = fio[1];
		}

		if (fio[i] != ' '&&o==0)
		{
			h++;
			fio1[i] = fio[i];
		}
		
		if (fio[i] != ' '&&o == 1&& fio[i-1] == ' ')
			{
				fio1[i] = fio[i];
				h++;
			}


			/*else {
				if (fio[i] == ' ')
				{
					fio1[h + 3] = '.';
					fio1[h + 4] = fio[i + 1];
				}
			}*/
		}
	}
	
	


