#include <iostream>

#include <iomanip>

#include<ctime>

using namespace std;

const int N = 5, M = 5;

void inputMatr(int matr[][M], int N, int M);

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

void initupMatr(int matr[][M], int N, int M, int &i, int &j, int way); // upMatr is higher line + last column 

void initdownMatr(int matr[][M], int N, int M, int &i, int &j, int way);

void spiralInitMart(int matr[][M], int N, int M);

int main()
{
	int matr[N][M];

	srand(time(NULL));

	spiralInitMart(matr, N, M);

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

void initupMatr(int matr[][M], int N, int M, int &i, int &j, int way)
{
	for (j; j < way; j++)
	{
		matr[i][j] = rand() % 90 + 10;
	}
	j--;
	for (i; i < way; i++)
	{
		matr[i][j] = rand() % 90 + 10;
	}
	i--;

}
void initdownMatr(int matr[][M], int N, int M, int &i, int &j, int way)
{
	int tmp1 = j - way;
	for (j; j >= tmp1; j--)
	{
		matr[i][j] = rand() % 90 + 10;
	}
	j++;
	int tmp2 = i - way;
	for (i; i >= tmp2; i--)
	{
		matr[i][j] = rand() % 90 + 10;
	}
	i++;

}
void spiralInitMart(int matr[][M], int N, int M)
{
	int i = 0, j = 0;
	for (int way = N; way >0; way--)
	{
		initupMatr(matr, N, M, i, j, way);
		initdownMatr(matr, N, M, i, j, way - 1);
	}
}