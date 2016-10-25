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
/*�������� ������ ������������ ����� ������� N (����� N �������� ��� ���������).
������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50.
������� �������� ������� ��������� � ��������� �������������� (1-�, 3-�, 5-�,...) � ����� - � �������.*/
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
	cout << "�������� � ������� ����������\n";
	int i = 0;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
void PrintOddArraysElements(float A[], int N)
{
	cout << "�������� � ��������� ����������\n";
	int i = 1;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
