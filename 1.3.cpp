#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
void CountAndPrintPositiveEvenNumbs(int A[], int N);
int IsNatural(int n);
void InitArray(int A[], int N, int n);
void CountAndPrintPositiveEvenNumbs(int A[], int N);
void PrintArray(int A[], int N);
int main()
{
	/*������������ ������ � ���������� ����������� ����� �� ������� 100, ������� ����������� � ���������� n,
	��������� ������������ �����, ������� ������ �� 10 ��������� ����� ����� �� ������� [-2n;n],
	������� ������ �� ����� � ������, ���������� � � ������� �� ����� ���������� ������������� ������ ����� � �������.*/
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	int n;
	int A[N];
	cout << "������� �����,�� ������� 100\n";
	cin >> n;
	if (IsNatural(n) == 0) { cout << "�� ���������� ����\n"; system("pause"); return 0; };
	InitArray(A, N, n);
	PrintArray(A, N);
	CountAndPrintPositiveEvenNumbs(A, N);
	system("pause");
}
int IsNatural(int n) {
	if (n <= 100) return 1;
	else return 0;
}
void InitArray(int A[], int N, int n)
{
	int min = (-2 * n), max = n;
	int i = 0;
	while (i<N)
	{
		A[i] = rand() % (max - min + 1) + min;
		i++;
	}
}
void PrintArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << setw(4);
		i++;
	}
}
void CountAndPrintPositiveEvenNumbs(int A[], int N)
{
	int count = 0;
	int i = 0;
	while (i < N)
	{
		if (A[i] > 0 && A[i] % 2 == 0) count++;
		i++;

	}
	cout << "\n ����������� ������ ����������� ��������� =" << count << "\n";
}
