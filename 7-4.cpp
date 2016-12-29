#include <iostream>

#include <iomanip>

#include<ctime>

using namespace std; 

const int N=8,  M=2;// such Matrix (M*N) using for comfortable testing 

void inputMatr(int matr[][M], int N, int M);

void initRandMatr(int matr[][M], int N, int M);

void printArray(int matr[][M], int N, int M);

bool isSequenceLine(int matr[][M], int N, int M, int j); //about increasing sequence 

void isSequence(int matr[][M], int N, int M);

int main()
{
	int matr[N][M];

	srand(time(NULL));

	initRandMatr(matr, N, M);

	//inputMatr(matr, N, M);

	printArray(matr, N, M);

	cout << "\n";

	isSequence(matr, N, M);

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
bool isSequenceLine(int matr[][M], int N, int M, int i)
{
	for (int j = 0; j < M-1; j++)
	{
		if (matr[i][j] > matr[i][j + 1])
			return false;
	}
	return true;
}
void isSequence(int matr[][M], int N, int M)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{		
		if (isSequenceLine(matr, N, M, i)) { cout << "in the " << (i+1) << "-line Matrix create increasing sequence \n"; k++; }
		else continue;
	}
	if (!k) cout << "Matrix doesn't create increasing sequence  \n";
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
