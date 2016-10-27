/* ������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� -N �� N.
���������� �������� �������� ������� ������ �� 1 ������� (��������� ������� ������ ������, 1-� ������ 2-�, 2-� ������ 3-� � �.�.)
����� ���������� �������� �������� ������� ����� �� 1 ������� (������ ������� ������ ���������, 2-� ������ 1-� � �.�)*/
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
	cout << " �������� ������\n";
	turnArrayRight(A, N);
	printArray(A, N);
    cout << " ��������� ������ ������\n";
	turnArrayLeft(A, N); 
	printArray(A, N);
	cout << " �������� ������\n";
	turnArrayLeft(A, N);
	printArray(A, N);
	cout << " ��������� ����� ������\n";
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