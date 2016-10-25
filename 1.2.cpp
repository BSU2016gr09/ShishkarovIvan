#include <iostream>
#include <clocale>
using namespace std;
int Check(int n);
void ArrayOfDigits(int A[], int N, int n);
void Sort(int A[], int N);
void PrintResult(int A[], int N, int n);
int main()
{/*Пользователь вводит с клавиатуры пятизначное натуральное число, которое сохраняется в переменную n,
 проверить корректность ввода, составить и вывести на экран число из цифр введённого числа n, так,
 чтобы выведенное число оказалось максимальным из возможных. 
 Например, если пользователь ввёл число 22195, то программа должна вывести число 95221.
*/
	setlocale(LC_ALL, "Russian");
	const int N = 5;
	int A[N];
	int n;
	cout << "Введите пятизначное число\n";
	cin >> n;
	if (Check(n) == 0) { system("pause"); return 0; }
	ArrayOfDigits(A, N, n);
	Sort(A, N);
	PrintResult(A, N, n);
	system("pause"); 
}
int Check(int n)
{
	int check = 0, digit = 0;
	while (n> 0)
	{
		digit = n % 10;
		n = n / 10;
		check++;
	}
	if (check != 5) {
		cout << "Не корректный ввод\n"; return 0;
	}
	else return 1;
}
void ArrayOfDigits(int A[], int N, int n)
{
	int  digit = 0;
	int i = 0;
	while (n > 0)
	{
		digit = n % 10;
		n = n / 10;
		A[i] = digit;
		i++;
	}
}
void Sort(int A[], int N)
{
	int i = 0, j = 1;
	while (i<N)
	{

		while (j<N)
		{
			if (A[i] < A[j]) swap(A[i], A[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
}
void PrintResult(int A[], int N, int n)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i];
		i++;
	}
}

