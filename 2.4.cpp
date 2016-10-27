/*ћассив целых чисел размера N проинициализировать последовательными числами от 1 до N.
"ѕеретусовать" элементы массива двум€ способами, предложенными на паре:
с использованием доп.массива и просто мен€€ местами случайные элементы.*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <clocale>
using namespace std;
void initArray(int A[], int N);
void initRandomArray(int A[], int N);
void randomSortingArray(int A[], int N);
void printArray(int A[], int N);
void randomSortingArrayUsingAnotherArray(int A[], int N,int B[]);
int main() {
	const int N = 10;
	int A[N], B[N];
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	initArray(A, N);
    initRandomArray(B, N);
	printArray(A, N);
	cout << "  ћассив от 1 до N\n";
	randomSortingArray(A, N);
	printArray(A, N);
	cout << "  ћассив отсортированный с помощью рандомных чисел \n";
	initArray(A, N);
	printArray(A, N);
	cout << "  ћассив от 1 до N\n";
	randomSortingArrayUsingAnotherArray(A, N,B);
	printArray(A, N);
	cout << "  ћасссив отсортированный с помощью доп.массива\n";
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
void randomSortingArray(int A[], int N) {
	int i = 0,j=0;
	while (i < N) {
		j = rand() % N;
		swap(A[i], A[j]);
		i++;
	}

}
void printArray(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i++] << setw(3);
	}
}
void randomSortingArrayUsingAnotherArray(int A[], int N, int B[])
{
	int i = 0, j = 1;
	initRandomArray(B, N);
	while (i < N)
	{

		while (j < N)
		{
			if (B[i] < B[j]) {
				swap(B[i], B[j]); swap(A[i], A[j]);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
void initArray(int A[], int N) {
	int i = 0,j=1;
	while (i < N)
	{
		A[i] = j;
		i++;
		j++;
	}
}
