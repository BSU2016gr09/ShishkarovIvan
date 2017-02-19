/* Массив целых чисел размера N проинициализировать случайными числами из промежутка от -N до N.
Циклически сдвинуть элементы массива вправо на 1 элемент (последний элемент станет первым, 1-й станет 2-м, 2-й станет 3-м и т.д.)
потом циклически сдвинуть элементы массива влево на 1 элемент (первый элемент станет последним, 2-й станет 1-м и т.д)*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <clocale>
using namespace std;
void initRandomArray(int A[], int N);
void turnArrayRight(int A[], int N);
void turnArrayLeft(int A[], int N);
void printArray(int A[], int N);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int N = 13;
	int A[N];
	initRandomArray(A , N);
	printArray(A, N);
	cout << " Исходный массив\n";
	turnArrayRight(A, N);
	printArray(A, N);
    cout << " Сдвинутый вправо массив\n";
	turnArrayLeft(A, N); 
	printArray(A, N);
	cout << " Исходный массив\n";
	turnArrayLeft(A, N);
	printArray(A, N);
	cout << " Сдвинутый влево массив\n";
	system("pause");
}
void initRandomArray(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = rand() %(2*N+1) -N;
		i++;
	}
}
void turnArrayRight(int A[], int N) {
	int i = 0,j=N-1;
	while (i <N-1)
	{
		swap(A[j - i], A[j-1 - i]);
		i++;
	}

}
void turnArrayLeft(int A[], int N) {
	int i = 0;
	while (i < N-1)
	{
		swap(A[i],A[i+1]);
		i++;
	}
}
	void printArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i++] << setw(4);
	}
}
