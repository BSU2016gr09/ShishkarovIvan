#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
float FloatRandom();
void InitRandomArray(float A[], int N);
void Sort(float A[], int N);
void PrintArray(float A[], int N);
int main()
{
/*Îáúÿâèòü ìàññèâ À âåùåñòâåííûõ ÷èñåë ðàçìåðà N (÷èñëî N îáúÿâèòü êàê êîíñòàíòó).
Ïðîèíèöèàëèçèðîâàòü çíà÷åíèÿ ýëåìåíòîâ ìàññèâà ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -50 äî 50.
"Îòñîðòèðîâàòü" ìàññèâ À íà ìåñòå (ò.å. íå èñïîëüçóÿ âñïîìîãàòåëüíûõ ìàññèâîâ Â è Ñ) òàêèì îáðàçîì:
ïîëîæèòåëüíûå çíà÷åíèÿ ìàññèâà À ïåðåìåñòèòü â íà÷àëî, îòðèöàòåëüíûå ïåðåìåñòèòü â êîíåö ìàññèâà À.*/
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	float A[N];
	InitRandomArray(A, N);
	Sort(A, N);
	PrintArray(A, N);
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
void Sort(float A[], int N) // Нам надо не отсортировать, а "отсортировать": вперед - положительные, назад - отрицательные элементы. Прочитай условие!!!!
{
	int i = 0, j = 1;
	while (i<N)
	{

		while (j<N)
		{
			if (A[i] < A[j]) swap(A[i], A[j]);
			j++;
		}
		i++;
		j = i + 1;
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
