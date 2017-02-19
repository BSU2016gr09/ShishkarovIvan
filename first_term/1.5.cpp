#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void PositiveArray(float A[], int N, float B[], int & k);
void NegativeArray(float A[], int N, float C[], int&j);
void PrintArray(float A[], int N);
int main()
{
/*Îáúÿâèòü ìàññèâ À âåùåñòâåííûõ ÷èñåë ðàçìåðà N (÷èñëî N îáúÿâèòü êàê êîíñòàíòó). 
Ïðîèíèöèàëèçèðîâàòü çíà÷åíèÿ ýëåìåíòîâ ìàññèâà ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -50 äî 50.
"Ðàçäåëèòü" ìàññèâ À íà äâà ìàññèâà: ïîëîæèòåëüíûå çàïèñàòü â ìàññèâ Â, îòðèöàòåëüíûå - â Ñ.*/
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	float A[N], B[N], C[N];
	int k = 0, j = 0;
    InitRandomArray(A, N);
	PrintArray(A, N); 
	cout << endl;
	PositiveArray(A, N,B,k);// а разве за 1 проход по массиву нельзя было и В и С???
	NegativeArray(A, N,C,j);
	cout << "Ïîëîæèòåëüíûå ýëåìåíòû ìàññèâà\n";
	PrintArray(B, k);
	cout << "Îòðèöàòåëüíûå ýëåìåíòû ìàññèâà\n";
	PrintArray(C,j);
	
	system("pause");
 }
float FloatRandom()
{
	float r = 0;
	r += rand() % (99) - 50;
	r += (rand() % 9) / 10.0;
	r += (rand() % 9) / 100.0;

	return (r);
}
void InitRandomArray(float A[], int N)
{
	int i = 0;
	while (i<N)
	{
		A[i] = FloatRandom();
		i++;
	}
}
void PositiveArray(float A[], int N, float B[], int & k)
{
	int i = 0;
	while (i < N)
	{
		if (A[i] >= 0) {
			B[k] = A[i]; k++;
		};
		i++;
	}
}
void NegativeArray(float A[], int N, float C[], int&j)
{
	int i = 0;
	while (i < N)
	{
		if (A[i] < 0) {
			C[j] = A[i]; j++;
		};
		i++;
	}
}
void PrintArray(float A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << "\n";
		i++;
	}
}
