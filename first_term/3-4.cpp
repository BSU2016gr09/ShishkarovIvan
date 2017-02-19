/*Окончательно реализовать функции для работы стека на массиве.
Сделать парные ф-ции push/pop для массива double и для массива char. Создать стек чисел и стек символов.
Продемонстрировать их работоспособность вызывая их из main.
В частности, показать, что стек не переполняется. */
#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
int charPush(char Charstek[], int &top, int N, char element) {
	{
		Charstek[top] = element;
		top++;
		return top;
	}
}
int charPop(char Charstek[], int top, int N)
{

	return Charstek[top];
	top--;
	

}

int doublePush(double Doublestek[], int &top, int N,int element)
{
	Doublestek[top] = element;
	top++;
	return top;
}
int doublePop(double Doublestek[], int top, int N)
{
	
	return Doublestek[top];
	top--;
	

}
int isEmpty(int top)
{
	if (top == -1)
	{
		cout << "Стек пуст "; return 0;
	}
	else return 1;

}
int isFull(int &top,int N)
{
	if (top<N)
	{
		return 1;
	}
	else {
		top--; cout << "Переполнен стек\n"; return 0;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	const int N = 3;
	double Doublestek[N];
	char Charstek[N];
	char numeral;
	int top = 0,i=0,element,flag=0;

	while (flag != 1) {
		cin >> element;
		if (isFull(top, N) == 0) flag = 1;
		else
		{
			doublePush(Doublestek, top, N, element);
			cout << top << " " << Doublestek[top - 1] << "\n";
		}
	} 
	flag = 0;
	
	cout << doublePop(Doublestek, top, N) << "\n";



		top = 0;
		flag = 0;
		while (flag != 1) {
			cin >> numeral;
			if (isFull(top, N) == 0) flag = 1;
			else
			{
				charPush(Charstek, top, N, numeral);
				cout << top << " " << Charstek[top - 1] << "\n";
			}
		}
		flag = 0;

		cout << charPop(Charstek, top, N) << "\n";

	system("pause");
}
