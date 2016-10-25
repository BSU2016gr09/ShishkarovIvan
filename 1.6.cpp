#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void Sort(float A[], int N);
void PrintArray(float A[], int N);
int main()
{
/*Объявить массив А вещественных чисел размера N (число N объявить как константу).
Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50.
"Отсортировать" массив А на месте (т.е. не используя вспомогательных массивов В и С) таким образом:
положительные значения массива А переместить в начало, отрицательные переместить в конец массива А.*/
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	float A[N];
	InitRandomArray(A, N);
	Sort(A, N);
	PrintArray(A, N);
	system("pause");
}
float FloatRandom()
{
	float r = 0;
	r += rand() % (99) - 50;
	r += (rand() % 9) / 10.0;
	r += (rand() % 9) / 100.0;
	return (r);
}
void InitRandomArray(float A[], int N)
{
	int i = 0;
	while (i<N)
	{
		A[i] = FloatRandom();
		i++;
	}
}
void Sort(float A[], int N)
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
void PrintArray(float A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << "\n";
		i++;
	}
}