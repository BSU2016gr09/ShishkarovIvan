#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void PositiveArray(float A[], int N, float B[], int & k);
void NegativeArray(float A[], int N, float C[], int&j);
void PrintArray(float A[], int N);
int main()
{
/*Объявить массив А вещественных чисел размера N (число N объявить как константу). 
Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50.
"Разделить" массив А на два массива: положительные записать в массив В, отрицательные - в С.*/
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	float A[N], B[N], C[N];
	int k = 0, j = 0;
    InitRandomArray(A, N);
	PrintArray(A, N); 
	cout << endl;
	PositiveArray(A, N,B,k);
	NegativeArray(A, N,C,j);
	cout << "Положительные элементы массива\n";
	PrintArray(B, k);
	cout << "Отрицательные элементы массива\n";
	PrintArray(C,j);
	
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
void PositiveArray(float A[], int N, float B[], int & k)
{
	int i = 0;
	while (i < N)
	{
		if (A[i] >= 0) {
			B[k] = A[i]; k++;
		};
		i++;
	}
}
void NegativeArray(float A[], int N, float C[], int&j)
{
	int i = 0;
	while (i < N)
	{
		if (A[i] < 0) {
			C[j] = A[i]; j++;
		};
		i++;
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