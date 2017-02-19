#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void PrintEvenArraysElements(float A[], int N);
void PrintOddArraysElements(float A[], int N);
int main()
{
/*Îáúÿâèòü ìàññèâ âåùåñòâåííûõ ÷èñåë ðàçìåðà N (÷èñëî N îáúÿâèòü êàê êîíñòàíòó).
Ïðîèíèöèàëèçèðîâàòü çíà÷åíèÿ ýëåìåíòîâ ìàññèâà ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -50 äî 50.
Âûâåñòè çíà÷åíèÿ ñíà÷àëà ýëåìåíòîâ ñ íå÷åòíûìè êîýôôèöèåíòàìè (1-é, 3-é, 5-é,...) à çàòåì - ñ ÷åòíûìè.*/
srand(time(NULL));
setlocale(LC_ALL, "Russian");
const int N=10;
float A[N];
FloatRandom();
InitRandomArray(A, N);
PrintEvenArraysElements(A, N);
PrintOddArraysElements(A, N);
system("pause");
}
float FloatRandom()//что это за монстроидальный код???? Проще нельзя было?
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
void PrintEvenArraysElements(float A[], int N) {
	cout << "Ýëåìåíòû ñ ÷¸òíûìè ýëåìåíòàìè\n";
	int i = 0;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
void PrintOddArraysElements(float A[], int N)
{
	cout << "Ýëåìåíòû ñ íå÷¸òíûìè ýëåìåíòàìè\n";
	int i = 1;
	while (i < N)
	{
		cout << A[i] << "\n";
		i += 2;
	}
}
