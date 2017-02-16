#include <iostream>
#include <clocale>
using namespace std;
int IsNatural(int n);//имена функций лучше с маленькой буквы
int SumOfDigit(int n, int &sum);//имена функций лучше с маленькой буквы
int main()
{
	/*Ïîëüçîâàòåëü ââîäèò ñ êëàâèàòóðû íàòóðàëüíîå ÷èñëî, ïðîâåðèòü êîððåêòíîñòü ââîäà, 
	âû÷èñëèòü è âûâåñòè íà ýêðàí ñóììó öèôð ââåä¸ííîãî ïîëüçîâàòåëåì ÷èñëà.*/
	setlocale(LC_ALL,"Russian");
	int n, sum=0;
	cout << "Ââåäèòå íàòóðàëüíîå ÷èñëî \n";
	cin >> n;
	if (IsNatural(n) == 0) { cout << "Íåêîððåêòíûé ââîä\n"; system("pause"); return 0; } //проверка == лишняя!!!
	SumOfDigit(n,sum);
	cout <<"Ñóììà öèôð =" <<sum;
	system("pause");
}
int IsNatural(int n)
{
	if (n < 0) return 0;
}
int SumOfDigit(int n, int &sum)
{
	int  digit = 0;
    while (n> 0)
	{
		digit = n % 10;
		n = n / 10;
		sum = sum + digit;

	}
	return sum;
}
