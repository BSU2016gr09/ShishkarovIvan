/* 1) Напишите игру в кости между человеком и компьютером.Они по очереди кидают по два кубика.
Побеждает тот у кого сумма больше.
Игра заканчивается если набрана сумма >50. 
 Кубики рисуйте в отдельной ф - ции псевдографикой(см.рисунок в качестве примера).
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
		cout << "\n Вы проиграли \n";
	else if (diceGame == 0)
		cout << "Ничья";
	else cout << "\n Вы выиграли \n";

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
		cout << "Ошибка\n";
	}
}
int diceGame()
{
	int playerscore = 0, computerscore = 0,value;
	while (playerscore < 50 && computerscore < 50)
	{
		cout << "Ваш ход\n";
		system("pause");
		value = diceValue();
			printDice(value);
		playerscore += value;
		value = diceValue();
			printDice(value);
		playerscore += value;
		cout << "\n Ваш текущий счёт = " << playerscore;
		cout << "\n Ход соперника\n";
		system("pause");
			value = diceValue();
			printDice(value);
		computerscore += value;
		value = diceValue();
			printDice(value);
		computerscore += value;
		cout  << "\n Счёт противника = " << computerscore << "\n";
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
