/*Элементы массива А(N), значения которых – простые числа,
расположить в порядке возрастания, не нарушая порядка следования других элементов.*/
#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

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

	initArray(A, size);
	printArray(A, size);
	cout << endl;

	primesSequence(A, size);

	printArray(A, size);

	delete[] A;

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
		if (check[i])
		{
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
	int *primesA = new int[size];
	int *index = new int[size];
	int size_primes = size;
	int *primes;
	primes = new int[size_primes];
	eratosthenes(primes, size_primes);

	int j = 0;
	for (int i = 0; i < size; i++){
		if (isPrime(primes, size_primes, A[i])) {
			primesA[j] = A[i];
			index[j++] = i;
		}
	}
	j++;
	Sort(primesA, j, 1);

	for (int i = 0; i < j - 1  ; i++){
		A[index[i]] = primes[i];
	}
	delete[] primes,index,primesA;
}
