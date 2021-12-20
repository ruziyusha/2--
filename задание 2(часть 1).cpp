#include <iostream>
#include<cstdlib>
#include<ctime>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	
		std::cout << "Первая кость:" << rand() % 6 + 1 << std::endl;
		system("pause");
		std::cout << "Вторая кость:" << rand() % 6 + 1 << std::endl;
		system("pause");
	
	
	return(0);


}
