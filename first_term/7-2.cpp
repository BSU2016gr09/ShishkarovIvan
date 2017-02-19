/*Найти в случайной матрице седловую точку если она там есть.*/
#include <iostream>

#include <iomanip>

#include< ctime>;

using std::cout; using std::cin; using std::setw;

const int N = 5, M = 6;

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

int findSaddlePoint(int matr[][M], int N, int M);

int main()
{
	int Matr[N][M];
	srand(time(NULL));
	
	initRandMatr(Matr, N, M);
	printArray(Matr, N, M);


	if(findSaddlePoint(Matr, N, M))
		cout<<"first saddle point is "<<findSaddlePoint(Matr, N, M)<<"\n";
	else cout << "there aren'n any saddle points";
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
int findSaddlePoint(int matr[][M], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		int j = 0,tmp=0;
		int minI = matr[i][j],maxJ;
		for (j = 0; j < M; j++)
		{
			if (matr[i][j] < minI) {minI = matr[i][j]; tmp = j;}
		}
		maxJ = minI;
		for (int k=0;k<N;k++ )
		{
			if (matr[k][tmp] > maxJ) maxJ = matr[k][tmp];
		}
		if (minI == maxJ) return minI;
	}
	return 0;
}





