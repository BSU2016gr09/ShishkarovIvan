#include <iostream>
#include <iomanip>
#include <clocale>	
using namespace std;
void initArray(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = i;
		i++;
	}
}
void initArray(int A[], int N, int init)
{
	int i = 0;
	while (i < N)
	{
		A[i] = init;
		i++;

	}
}
void inputArray(int A[], int N)
{
	int i = N;
	while (i>0)
	{
		cin >> A[--i];
	}
}
void printNumberArray(int A[], int N) {
	int i = N,j;
	while (A[--i] == 0 && i > 0)
	{
		 j = i;
	}

	while (j > 0)
	{
				cout << A[--j];
	}
}
void sum(int A[], int B[], int Rez[], int N)
{
	int i = 0, tmp = 0;
	while (i<N)
	{
		Rez[i] = A[i] + B[i] + tmp;
		tmp = Rez[i] / 10;
		Rez[i] %= 10;
		i++;
	}

}
void difference(int A[], int B[], int Rez[], int N)
{
	int i = 0, j = 1, tmp = 1,k=N;
	while (j <= k )
	{
		if (A[i] >  B[i] || A[i]==B[i]) Rez[i] = A[i] - B[i];
		else
		{
			Rez[i] = A[i] - B[i] + tmp * 10;
			A[j] -= tmp;
		}
		i++;
		j = i + 1;
	}
}
void createSimillarArray(int A[], int B[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = B[i];
		i++;
	}
}
void Fibonacci(int A[],int B[],int Rez[],int MAXSIZE)
{
	int board=1;
	while (board<=460)
	{
		sum(A, B, Rez, MAXSIZE);
		
		createSimillarArray(A, B, MAXSIZE);
		createSimillarArray(B, Rez, MAXSIZE);
		board++;
	}
		cout << "\n Число Фибоначи номер ("<<board-1<<")= ";
		printNumberArray(Rez, MAXSIZE);
} 
int main()
{
	setlocale(LC_ALL, "russian");
	const int MAXSIZE = 100;
	int A[MAXSIZE], B[MAXSIZE], Rez[MAXSIZE], init = 0;
	initArray(A, MAXSIZE, 0);
	A[0] = 1;
	initArray(B, MAXSIZE, 0);
	B[0] = 1;
	initArray(Rez, MAXSIZE, 0);
	Fibonacci(A, B, Rez, MAXSIZE);
	
	printNumberArray(Rez, MAXSIZE);
	system("pause");
}