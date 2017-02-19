/*В матрице (n,m) удалить нулевые строки (из одних нулей), "подтянув" все остальные вверх.*/

#include <iostream>

#include <iomanip>

#include<ctime>

using namespace std;

const int N = 5, M = 2;// such Matrix (M*N) using for comfortable testing 

void inputMatr(int matr[][M], int N, int M);

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

bool isZeroLine(int matr[][M], int N, int M,int i); // returns true,if i-line is Zero line

void shiftDown(int matr[][M], int N, int M, int i); // this fun shift i-line to the ground of the Matrix

void createNonZeroMatrix(int matr[][M], int N, int M);

int main()
{
	int matr[N][M];

	srand(time(NULL));

	//initRandMatr(matr, N, M);

	inputMatr(matr, N, M);

	printArray(matr, N, M);

	cout << "\n";

	createNonZeroMatrix(matr, N, M);

	printArray(matr, N, M);

	cout << "\n";

	system("pause");

	return 0;

}
void initRandMatr(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matr[i][j] = rand() % 90 + 10;
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
void inputMatr(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matr[i][j];
		}

	}
}
bool isZeroLine(int matr[][M], int N, int M, int i)
{
	for (int j = 0; j < M ; j++)
	{
		if (matr[i][j]!=0)
			return false;
	}
	return true;

}
void shiftDown(int matr[][M], int N, int M, int i)
{
	for ( i; i < N-1; i++)
	{
		for (int j = 0; j< M; j++)
		{
			swap(matr[i][j], matr[i + 1][j]);
		}
	}
}
void createNonZeroMatrix(int matr[][M], int N, int M)
{
	for (int i = 0; i < N-1; i++)
	{
		if (isZeroLine(matr, N, M, i)) shiftDown(matr, N, M, i);
	}
}
