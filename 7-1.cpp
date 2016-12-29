#include <iostream>

#include <iomanip>

#include< ctime>;

using std::cout; using std::cin; using std::setw;

const int N = 5 , M = 6 ;

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

void minOfColomns(int matr[][M], int N, int M);

int main()
{
	int Matr[N][M];

	srand(time(NULL));
	initRandMatr(Matr, N, M);
	printArray(Matr, N, M);
	minOfColomns(Matr, N, M);

	system("pause");
}
void initRandMatr(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matr[i][j] = rand() % 100 + 1;
		}
	}
}

void printArray(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matr[i][j] << setw(4);
		}
		cout << "\n";
	}
}
void minOfColomns(int matr[][M], int N, int M)
{	
	for (int i = 0; i < N; i++)
	{
		int j = 0;
		int min = matr[i][j];
			for (j = 0; j < M; j++)

			{
				if (matr[i][j] < min) min = matr[i][j];
			}
		cout << "min element from column (" << i << ") is " << min << "\n";
	}
}



