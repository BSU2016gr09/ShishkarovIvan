/*В матрице (n,m) удалить строки у которых максимальный элемент стоит первым, "подтянув" все остальные строки.*/

#include <iostream>

#include <iomanip>

#include<ctime>

using namespace std;

const int N = 5, M = 2;// such Matrix (M*N) using for comfortable testing 

void inputMatr(int matr[][M], int N, int M);

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

int lineMaxEl(int matr[][M], int N, int M,int i); //returns max element of the line

void shiftDown(int matr[][M], int N, int M, int i); // this fun shift i-line to the ground of the Matrix

void shiftMatr(int matr[][M], int N, int M); // if max elemet of string equals to first element,this string will be shifted down 

int main()
{
	int matr[N][M];

	srand(time(NULL));

	initRandMatr(matr, N, M);

//	inputMatr(matr, N, M);

	printArray(matr, N, M);

	cout << "\n";

	shiftMatr(matr, N, M);

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
void shiftDown(int matr[][M], int N, int M, int i)
{
	for (i; i < N - 1; i++)
	{
		for (int j = 0; j< M; j++)
		{
			swap(matr[i][j], matr[i + 1][j]);
		}
	}
}
int lineMaxEl(int matr[][M], int N, int M, int i)
{
	int max = matr[i][0];
	for (int j = 1; j < M; j++)
	{
		if (matr[i][j] > max) max = matr[i][j];
	}
	return max;
}
void shiftMatr(int matr[][M], int N, int M)
{
	for (int i = 0; i < M; i++)
	{
		if (lineMaxEl(matr, N, M, i) == matr[i][0]) shiftDown(matr, N, M, i);

	}
}
