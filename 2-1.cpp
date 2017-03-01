#include<iostream>

#include <iomanip>

#include<ctime>

using namespace std;

static unsigned long int next_el = 1;

void give_memory(int * & A, int size);

void delete_memory(int * & A);

void initRandArray(int *A, int size);

void printArray(int *A, int size);

void mySrand(unsigned int seed);

int myRand();

int main() {

	mySrand(time(NULL));

	int size;
	int *A;
	cout << "enter size";
	cin >> size;

	give_memory(A, size);
	initRandArray(A, size);
	printArray(A, size);
	cout << endl;
	delete_memory(A);

	system("pause");

	return 1;

}
void initRandArray(int *A, int size) {

	for (int i = 0; i < size; i++) {
		A[i] = myRand() % 100 + 1;
	}
}
void printArray(int *A, int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << setw(4);
	}
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
int myRand() {
	next_el = next_el * 2205 + 4862;
	return next_el % 15435;
}
void mySrand(unsigned int seed)
{
	next_el = seed;
}