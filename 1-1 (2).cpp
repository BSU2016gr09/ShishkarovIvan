//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void give_memory(int * & A, int size);

void delete_memory(int * & A);

void Sort(int *A, int size, int begin);

void initArray(int *A, int size);

void printArray(int *A, int size);

int main() {
	srand(time(NULL));

	int size;
	int *A;

	cout << "enter size";
	cin >> size;
	give_memory(A, size);

	int begin;
	cout << "enter begin";
	cin >> begin;
	if (begin <= 0) return 0;

	initArray(A, size);

	printArray(A, size);

	cout << endl;

	Sort(A, size, begin);

	printArray(A, size);

	delete_memory(A);

	system("pause");

	return 1;
}

void initArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 10;
	}
}
void printArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << setw(2);
	}
}
void Sort(int *A, int size, int begin) {
	int i = begin - 1;
	int j = begin;
	for (; i < size; i++) {
		for (; j < size; j++) {
			if (A[i] > A[j]) swap(A[i], A[j]);
		}
		j = i + 1;
	}
}
void give_memory(int * & A, int size) {
	try {
		A = new int[size];
	}
	catch (...) {
		cout << "failed";
	}
<<<<<<< HEAD:1-1 (2).cpp
}
void delete_memory(int * & A) {
	delete[] A;
}
=======
	return 1;
}
