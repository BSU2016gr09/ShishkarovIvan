/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
*/
#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void give_memory(int * & A,int size);

void delete_memory(int * & A);

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

	give_memory(A, size); 

	initArray(A, size);

	printArray(A, size);

	cout << endl;

	Sort(A, size, positiveInBegin(A,size)+1);

	printArray(A, size);
	
	cout << endl;

	delete_memory(A); 

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
void give_memory(int * & A, int size) {
	try {
		A = new int[size];
	}
	catch (...) {
		cout << "failed";
	}
}
void delete_memory(int * & A) {
	delete[] A;
}
