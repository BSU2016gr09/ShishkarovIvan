#include <iostream>
#include <clocale>
using namespace std;
int IsNatural(int n);
int SumOfDigit(int n, int &sum);
int main()
{
	/*������������ ������ � ���������� ����������� �����, ��������� ������������ �����, 
	��������� � ������� �� ����� ����� ���� ��������� ������������� �����.*/
	setlocale(LC_ALL,"Russian");
	int n, sum=0;
	cout << "������� ����������� ����� \n";
	cin >> n;
	if (IsNatural(n) == 0) { cout << "������������ ����\n"; system("pause"); return 0; }
	SumOfDigit(n,sum);
	cout <<"����� ���� =" <<sum;
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