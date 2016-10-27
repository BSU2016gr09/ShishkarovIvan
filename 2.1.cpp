/*ћассив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N.
"ѕеревернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й помен€етс€ с предпоследним и т.д.)
¬нимательно проверьте случай нечетного N*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void printArray(int A[], int N);
void createMirrorArray(int A[], int N); 
void initRandomArray(int A[], int N);
int main()
	{
		srand(time(NULL));
		const int N=13;
		int A[N];
	initRandomArray(A, N);
	printArray(A, N);
	cout << "\n";
	createMirrorArray(A, N);
	printArray(A, N);
	cout << "\n";
	system("pause");
}
void initRandomArray(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = rand() % N + 1;
		i++;
	}
}
void createMirrorArray(int A[], int N)
{
	int i = -1, j = N, board = N / 2 - 1;
	while (j > board)
	{
		swap(A[j--], A[i++]);

	}
}
void printArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i++] << setw(3);
	}
}