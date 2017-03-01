/*лементы массива А(N),значения которых – простые числа, расположить в порядке возрастания, 
не нарушая порядка следования других элементов.
*/
#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void give_memory(int * & A, int size);

void delete_memory(int * & A);

void Sort(int *A, int size, int begin);

void initArray(int *A, int size);

void printArray(int *A, int size);

void eratosthenes(int *primes, int &size); 

bool isPrime(int *primes,int size, int numb);

void primesSequence(int *A, int size);

int main() {
	srand(time(NULL));

	int size;
	int *A;
	cout << "enter size";
	cin >> size;
	A = new int[size];

	give_memory(A, size);
	initArray(A, size);
	printArray(A, size);
	cout << endl;

	primesSequence(A, size);
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
void eratosthenes(int *primes, int &size) {
	bool *check;
	check = new  bool[size];
	check[0] = check[1] = false;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (check[i])	{
			primes[j++] = i;
			for (int k = i; k < size; k += i)
			{
				check[k] = false;
			}
		}
	}
	size = j;
}
bool isPrime(int *primes, int size, int numb) {
	for (int i = 0; i < size; i++){
		if (primes[i] == numb) return true;
	}
	return false;
}
void primesSequence(int *A, int size) {
	int *primesA;
	int *index;

	give_memory(primesA, size);
	give_memory(index, size);

	int size_primes = 100; // fun eratosthenes creates array,that consists of all primes less than 100
	int *primes;
	give_memory(primes, size_primes);
	eratosthenes(primes, size_primes);

	int j = 0;
	for (int i = 0; i < size; i++){
		if (isPrime(primes, size_primes, A[i])) {
			primesA[j] = A[i];
			index[j++] = i;
		}
	}

	Sort(primesA, j, 1);

	for (int i = 0; i < j   ; i++){
		A[index[i]] = primesA[i];
	}

	delete_memory(index);
	delete_memory(primesA);
	delete_memory(primes);
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
