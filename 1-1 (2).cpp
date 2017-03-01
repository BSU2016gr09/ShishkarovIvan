<<<<<<< HEAD:1-1 (2).cpp
//Ðàñïîëîæèòü â ïîðÿäêå âîçðàñòàíèÿ ýëåìåíòû ìàññèâà À(N), íà÷èíàÿ ñ k-ãî ýëåìåíòà.
=======
//Ð Ð°ÑÐ¿Ð¾Ð»Ð¾Ð¶Ð¸Ñ‚ÑŒ Ð² Ð¿Ð¾Ñ€ÑÐ´ÐºÐµ Ð²Ð¾Ð·Ñ€Ð°ÑÑ‚Ð°Ð½Ð¸Ñ ÑÐ»ÐµÐ¼ÐµÐ½Ñ‚Ñ‹ Ð¼Ð°ÑÑÐ¸Ð²Ð° Ð(N), Ð½Ð°Ñ‡Ð¸Ð½Ð°Ñ Ñ k-Ð³Ð¾ ÑÐ»ÐµÐ¼ÐµÐ½Ñ‚Ð°.
>>>>>>> 2c0fb6eae6ab92041135e3e716968ec60d30fc25:1-1.cpp
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
>>>>>>> 2c0fb6eae6ab92041135e3e716968ec60d30fc25:1-1.cpp
