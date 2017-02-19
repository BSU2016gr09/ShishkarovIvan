/*В массиве размера N, заполненного случ.числами от 0 до 10,
подсчитать количество элементов, встречающихся более одного раза.*/
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
using namespace std;
int countSameElements(int A[], int N);
void initRandomArray(int A[], int N);
void printArray(int A[], int N);
int main() {
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	const int N = 11;
	int A[N];
	int count;
	initRandomArray(A, N);
	printArray(A, N);
	count = countSameElements(A, N);
	cout <<"\n Колечиство повторений="<< count<<"\n";
	system("pause");

}
void initRandomArray(int A[], int N) {
	int i = 0;
	while (i < N) {
		A[i] = rand() % 10;
		i++;
	}
}
void printArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i++] << setw(3);
	}
}
int countSameElements(int A[], int N) {
	int i = 0, j = 1, count = 0, flag = 0;
	while (i < N)
	{
		while (flag != 1&&j<N) {
			if (A[i] == A[j])
			{
				count++; flag = 1;
			}
			j++;
		}
		flag = 0;	i++; j = i + 1;
	}
	return count;
}
