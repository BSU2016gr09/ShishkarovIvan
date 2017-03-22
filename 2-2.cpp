//XORShift

#include<iostream>

#include <iomanip>

#include<ctime>

using namespace std;

static unsigned long int next_el = 1;//знаешь для чего тут написал static??? Или просто так???

void give_memory(int * & A, int size);

void delete_memory(int * & A);

void initRandArray(int *A, int size);

void printArray(int *A, int size);

int XORshift();

void XORsRand(unsigned  int seed);

int main() {

	XORsRand(time(NULL));

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
		A[i] = XORshift() % 100 + 1;
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
void delete_memory(int * & A) {//раз собирался менять * &, то надо было менять!!! A=nullptr;
	delete[] A;
}
void XORsRand(unsigned int seed) // офигенная функция!!! Просто супер ((((
{
	next_el = seed;
}
int XORshift() {

	unsigned long int tmp;
	int a = 15, b = 13, c = 5;

	tmp = next_el ^ (next_el << a);

	tmp = tmp ^ (tmp >> b);

	next_el = tmp ^ (tmp << c);

	return next_el;
}
