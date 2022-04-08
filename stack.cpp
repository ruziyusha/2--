#include<iostream>  
#include<string>

using namespace std;

struct elem

{
    char value;

	elem* next = nullptr;

	int index;
};



void push(elem*& head, char value,int ind)
{
	auto* newel = new elem;
	newel->value = value;
	newel->index = ind;
	if (head) {
		newel->next = head;
	}
	head = newel;
}

bool pop(elem*& head, char& value)
{
	if (head)
	{
		value = head->value;
		auto* rem = head;
		head = head->next;
		delete rem;
		return true;
	}
	else {
		return false;
	}
}


 const char* peek(const elem* head)
{
	if (head)
	{
		return &head->value;
	}
	return nullptr;
}

void clear(elem*& head)
{
	
	while (head)
	{
		auto* rem = head;
		head = head->next;
		delete rem;
	}
}

void ShowStack(elem *& head)
{
	char value;

	while (pop(head, value)) {

		cout << value << " ";
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	elem* head = nullptr;
	string s;
	
	
	cout << "Введите математическое выражение:" << endl;
	cin >> s;
	

	char *skobki;
	skobki = new char[s.size()];
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ')' || s[i] == '(' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == '<' || s[i] == '>')
		{
			skobki[k]=s[i];
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << skobki[i];
	}
	cout << endl;
	
	for (int i = 0; i < k; i++)
	{
		if (skobki[i] == '{' || skobki[i] == '[' || skobki[i] == '(' || skobki[i] == '<')
			push(head, skobki[i],i);
		else {
			if ((int)skobki[i] == (int)skobki[i - 1] + 1 || (int)skobki[i] == (int)skobki[i - 1] + 2)
			{
				pop(head, skobki[i - 1]);
				
			}
			else { cout << i << "я скобка нарушает последовательность(отсчет с 0)" << endl;
			
			}

		}

	}

	if (!head)
	{
		cout << "Последовательность верная" << endl;
	}
	else {
		while (head)
		{
			cout << head->index << "я скобка нарушает последовательность" << endl;
			pop(head, head->value);
	}

	}
	
	system("pause");
	
}