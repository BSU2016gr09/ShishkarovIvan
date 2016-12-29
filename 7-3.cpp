#include <iostream>

#include<iomanip>

using namespace std;

const int N = 5,M = 5;

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

void transpose(int matr[][M], int N, int M);

int main()
{
	 int matr[N][M];

	 initRandMatr(matr, N, M);

	 printArray(matr, N, M);

	 transpose(matr, N, M);

	 cout << "\n";

	 printArray(matr, N, M);

	 system("pause");

	 return 0;

}

void initRandMatr(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matr[i][j] = rand() % 90+10 ;
		}
	}
}

void printArray(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matr[i][j] << setw(6);
		}
		cout << "\n";
	}
}

void transpose(int matr[][M], int N, int M)
{
	for (int j=0,i = 0; i < N; i++)
	{
		
		for (j = i; j < M; j++)
		{
			swap(matr[i][j], matr[j][i]);
		}
	
	}
}
