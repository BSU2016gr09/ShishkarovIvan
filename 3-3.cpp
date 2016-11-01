/*� ������� ������� N, ������������ ����.������� �� 0 �� 10,
���������� ������������ ����� ������������������ ������ ���������.*/
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
using namespace std;
void printArray(int A[], int N);
int leightOfSameElements(int A[], int N);
void initRandomArray(int A[], int N);
int main() {
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	const int N = 15;
	int A[N], B[N];
	initRandomArray(A, N);
	printArray(A, N);
	cout << "\n";
	leightOfSameElements(A, N);
	
		cout << "������������ ����� ������������������ ����������� ��������� = " << leightOfSameElements(A,N);
		cout << "\n";
    
	//else cout << "��� ������������������ ������������� ���������";
 	system("pause");
}
void initRandomArray(int A[], int N) {
	int i = 0;
	while (i < N) {
	    A[i] = rand() % 10;
		i++;
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
int leightOfSameElements(int A[], int N) {   
	int i = 0, j = 1,  maxleight = 0;
	while (i<N)
	{
		int leight = 1;
		while (A[i] == A[j]) {	
			leight++;
			if (maxleight<leight)
			{
				maxleight = leight;
			}
			j++;

		}          
		i++; j = i + 1;
	}
	return maxleight;
}
