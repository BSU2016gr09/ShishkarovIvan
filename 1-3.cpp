#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

int give_memory(int *A,int size);

void Sort(int *A, int size, int begin);

void initArray(int *A, int size);

void printArray(int *A, int size);

int positiveInBegin(int *A, int size);// return position of the last positive element. Al elements after pstn are less or equal to 0

int main() {
	srand(time(NULL));

	int size;
	int *A;

	cout << "enter size";
	cin >> size;

	A = new int[size];

	//give_memory(A, size); с её использованием срубается 

	initArray(A, size);

	printArray(A, size);

	cout << endl;

	Sort(A, size, positiveInBegin(A,size)+1);

	printArray(A, size);

	delete[] A;

	system("pause");

	return 1;
}

void initArray(int *A, int size) {

	for (int i = 0; i < size; i++) {
		A[i] = rand() % 20 - 10;
	}
}
void printArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << setw(4);
	}
}
void Sort(int *A, int size, int begin) {
	int i = begin - 1;
	int j = begin;
	for (; i < size; i++) {
		for (; j < size; j++) {
			if (A[i] < A[j]) swap(A[i], A[j]);
		}
		j = i + 1;
	}
}
int positiveInBegin(int *A, int size){
	int i = 0, j = 0;
	for (; i < size; i++){
		if (A[i] > 0) swap(A[i], A[j++]);
	}
	return j;
}
int give_memory(int *A, int size) {
	try {
		A = new int[size];
	}
	catch (...) {
		return 0;
	}
	return 1;
}