#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void quickSort(int *A, int size, int begin);

void initArray(int *A, int size);

void printArray(int *A, int size);

int main() {

	int size;

	int *A;

	cout << "enter size";
	cin >> size;

	A = new int[size];

	int begin;

	cout << "enter begin";
	cin >> begin;
	
	if (begin <= 0) return 0;

	srand(time(NULL));

    initArray(A, size);

	printArray(A, size);

	cout << endl;

	quickSort(A, size - (begin - 1) ,begin);

	printArray(A, size);

	delete[] A; 

	system("pause");

	return 1;
}

void initArray(int *A, int size) {

	for (int i = 0; i < size; i++) {
		A[i] = rand() % 10 ;
	}
}
void printArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << setw(2);
	}
}
void quickSort(int *A, int size, int begin) {
	
	int j = size + begin - 2;
	bool dir = true;
	int current = begin - 1;
	int leftLenth = 0;
	int rightLenth = 0;
	
	for (int i = 1; i < size; i++)
	{ 
		if (dir) {
			if (A[current] > A[j]) {
				swap(A[current], A[j]);
				swap(current, j);	
				dir = false;
				j++;
				continue;
			}
			j--;
		}
		else {
			if (A[current] < A[j]) {
				swap(A[current], A[j]);
				swap(current, j);
				dir = true;
				continue;
				j--;
			}
			j++;
		}	
	}

	current++;
	leftLenth = current - begin ;
	rightLenth = size - (current -begin + 1) ;
	
	if (leftLenth > 1) quickSort(A, leftLenth, begin);
	if (rightLenth > 1) quickSort(A, rightLenth,current + 1);	
}