#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void PrintEvenArraysElements(float A[], int N);
void PrintOddArraysElements(float A[], int N);
int main()
{
/*ќбъ€вить массив вещественных чисел размера N (число N объ€вить как константу).
ѕроинициализировать значени€ элементов массива случайными числами из промежутка от -50 до 50.
¬ывести значени€ сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными.*/
srand(time(NULL));
setlocale(LC_ALL, "Russian");
const int N=10;
float A[N];
FloatRandom();
InitRandomArray(A, N);
PrintEvenArraysElements(A, N);
PrintOddArraysElements(A, N);
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
void PrintEvenArraysElements(float A[], int N) {
	cout << "Ёлементы с чЄтными элементами\n";
	int i = 0;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
void PrintOddArraysElements(float A[], int N)
{
	cout << "Ёлементы с нечЄтными элементами\n";
	int i = 1;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
