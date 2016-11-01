/* 1) �������� ���� � ����� ����� ��������� � �����������.��� �� ������� ������ �� ��� ������.
��������� ��� � ���� ����� ������.
���� ������������� ���� ������� ����� >50. 
 ������ ������� � ��������� � - ��� ��������������(��.������� � �������� �������).
+ -- - +
| O |
| O |
| O |
+-- - +*/ 

#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
void printDice(int value);
int diceGame();
int diceValue();
int main()
{  
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	if (diceGame() == -1)
		cout << "\n �� ��������� \n";
	else if (diceGame == 0)
		cout << "�����";
	else cout << "\n �� �������� \n";

	system("pause");

}
void printDice(int value)
{
	switch (value)
	{
	case 1:
	{
		cout << "+---------+\n";
		cout << "|         |\n";
		cout << "|    O    |\n";
		cout << "|         |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 2:
	{
		cout << "+---------+\n";
		cout << "| O       |\n";
		cout << "|         |\n";
		cout << "|       O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 3:
	{
		cout << "+---------+\n";
		cout << "| O       |\n";
		cout << "|    O    |\n";
		cout << "|       O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 4:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "|         |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 5:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "|    O    |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	case 6:
	{
		cout << "+---------+\n";
		cout << "| O     O |\n";
		cout << "| O     O |\n";
		cout << "| O     O |\n";
		cout << "+---------+\n\n";
		break;
	}
	default:
		cout << "������\n";
	}
}
int diceGame()
{
	int playerscore = 0, computerscore = 0,value;
	while (playerscore < 50 && computerscore < 50)
	{
		cout << "��� ���\n";
		system("pause");
		value = diceValue();
			printDice(value);
		playerscore += value;
		value = diceValue();
			printDice(value);
		playerscore += value;
		cout << "\n ��� ������� ���� = " << playerscore;
		cout << "\n ��� ���������\n";
		system("pause");
			value = diceValue();
			printDice(value);
		computerscore += value;
		value = diceValue();
			printDice(value);
		computerscore += value;
		cout  << "\n ���� ���������� = " << computerscore << "\n";
	}
	if (computerscore > 50)
	{
		return -1;
	}
	else if (playerscore > 50)
	{
		return 1;
	}
    else return 0;
}
int diceValue() {
	int value = 0;

	value = rand() % 6 + 1;
	return value;
}
