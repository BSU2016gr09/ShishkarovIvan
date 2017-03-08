#include <iostream>

#include <iomanip>

using namespace std;

void give_memory(int **&Matr, int lines, int strings);

void printArray(int **Matr, int lines, int strings);

void initArray(int **Matr, int lines, int strings);

void free_array(int **Matr, int lines, int strings);

void doing(int **Matr, int lines, int strings);

void Sort(int *A, int * * pA, int size);

int get_min(int *A, int size);

int main() {
	
	int * * Matr;
	int M ;
	int N ;

	cin >> M >> N;

	give_memory(Matr, N, M);
	initArray(Matr, N, M);
	printArray(Matr, N, M);
	cout << "\n";
	doing(Matr, N, M);
	printArray(Matr, N, M);
	free_array(Matr, N, M);	
	
	system("pause");
	return 0;

}
void initArray(int **Matr, int lines, int strings) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < strings; j++) {
			Matr[i][j] = rand()%100; //(0;100);
		}
	}
}
void printArray(int **Matr, int lines, int strings) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < strings; j++) {
			cout << setw(4) << Matr[i][j];
		}
		cout << endl;
	}
}
void give_memory(int **&Matr, int lines, int strings) {
	Matr = new int *[lines];
	for (int i = 0; i < lines; i++) {
		Matr[i] = new int[strings];
	}
}
void free_array(int **Matr, int lines, int strings) {
	for (int i = 0; i < lines; i++) {
		delete[] Matr[i];
	}
	delete[] Matr;
}
void doing(int **Matr, int lines, int strings) {

	int *Min = new int [lines];

	for (int i = 0; i < lines; i++)
	{
		Min[i]= get_min(Matr[i], strings);
	}

	Sort(Min,  Matr, lines);

}
int get_min(int *A, int size) {

	int min = A[0];

	for (int i = 1; i < size; i++)
	{
		if (A[i] < min) min = A[i];
	}
	return min;
}
void Sort(int *A,int * * pA, int size) {
	int i =  0;
	int j = 1;
	for (; i < size; i++) {
		for (; j < size; j++) {
			if (A[i] > A[j]) { 
				swap(A[i], A[j]);
				swap(pA[i], pA[j]);
			}
		}
		j = i + 1;
	}
}