/*Даны точки плоскости своими координатами в виде двух одномерных массивов.
Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/
#include <iostream>

#include <iomanip>

#include <ctime>

using namespace std;

void pointsSort(int *X,int *Y, int size, int a, int b, int c);

void initArray(int *A, int size);

void printArray(int *A, int size);

float lenthToLine(int x, int y,int a,int b,int c);

int main() {
	srand(time(NULL));

	int size;
	int *X;
	int *Y;

	cout << "enter number of points";
	cin >> size;

	X = new int[size];
	Y = new int[size];

	initArray(X, size);
	cout << endl;
	initArray(Y, size);
	cout << endl;
	printArray(X, size);
	cout << endl;
	printArray(Y, size);
	cout << endl;

	int a, b, c;
	cout << "enter coefficients from equatin Ax+By+C in such sequence :  A  B  C";
	cin >> a >> b >> c;
	pointsSort(X, Y, size, a, b, c);

	printArray(X, size);
	cout << endl;
	printArray(Y, size);
	cout << endl;

	delete[] X,Y;

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
void pointsSort(int *X,int *Y, int size, int a, int b, int c) {
	int i = 0;
	int j = 1;
	for (; i < size; i++) {
		for (; j < size; j++) {
			if (lenthToLine(X[i], Y[i],a,b,c) > lenthToLine(X[j], Y[j], a, b, c)) {
				swap(X[i], X[j]);
				swap(Y[i], Y[j]);
			}
		}
		j = i + 1;
	}
}
float lenthToLine(int x, int y, int a, int b, int c) {
	float lenth = (a*x + b*y + c)*1.0 / (sqrt(a*a + b*b)*1.0);
	return lenth;
}
