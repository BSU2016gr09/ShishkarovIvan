#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
void CountAndPrintPositiveEvenNumbs(int A[], int N);
int IsNatural(int n);
void InitArray(int A[], int N, int n);
void CountAndPrintPositiveEvenNumbs(int A[], int N);
void PrintArray(int A[], int N);
int main()
{
	/*Ïîëüçîâàòåëü ââîäèò ñ êëàâèàòóðû íàòóðàëüíîå ÷èñëî íå áîëüøåå 100, êîòîðîå ñîõðàíÿåòñÿ â ïåðåìåííóþ n,
	ïðîâåðèòü êîððåêòíîñòü ââîäà, ñîçäàòü ìàññèâ èç 10 ñëó÷àéíûõ öåëûõ ÷èñåë èç îòðåçêà [-2n;n],
	âûâåñòè ìàññèâ íà ýêðàí â ñòðîêó, ïîäñ÷èòàòü è è âûâåñòè íà ýêðàí êîëè÷åñòâî ïîëîæèòåëüíûõ ÷¸òíûõ ÷èñåë â ìàññèâå.*/
	setlocale(LC_ALL, "Russian");
	const int N = 10;
	int n;
	int A[N];
	cout << "Ââåäèòå ÷èñëî,íå áîëüøåå 100\n";
	cin >> n;
	if (IsNatural(n) == 0) { cout << "Íå êîððåêòíûé ââîä\n"; system("pause"); return 0; };
	InitArray(A, N, n);
	PrintArray(A, N);
	CountAndPrintPositiveEvenNumbs(A, N);
	system("pause");
}
int IsNatural(int n) { // а если n<0? И название неудачное. Это же не пример 1-2.cpp скорее checkNumber() или просто check()
	if (n <= 100) return 1;
	else return 0;
}
void InitArray(int A[], int N, int n)
{
	int min = (-2 * n), max = n;
	int i = 0;
	while (i<N)
	{
		A[i] = rand() % (max - min + 1) + min;
		i++;
	}
}
void PrintArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << setw(4);//можно одной строкой обойтись... Не раздувай код!!! while (i<N) cout << A[i++];
		i++;
	}
}
void CountAndPrintPositiveEvenNumbs(int A[], int N)
{
	int count = 0;
	int i = 0;
	while (i < N)
	{
		if (A[i] > 0 && A[i] % 2 == 0) count++;
		i++;

	}
	cout << "\n Êîëëè÷åñòâî ÷¸òíûõ íàòóðàëüíûõ ýëåìåíòîâ =" << count << "\n";
}
