#include <iostream>

#include "Money.h"

using namespace std;

int main() {

	Money my_money;
	Money my_salary;

	my_money.rubles = 10;
	my_money.coins = 50;
	my_salary.rubles = 1;
	my_salary.coins = 40;


	 //my_money=my_money.sum(my_salary);
	// my_money.printMoney();


	// my_salary = my_salary.diff(my_money);
	// my_salary.printMoney();
	 
	int n = 11;
	 (my_salary.multByNumb(n)).printMoney();

	 system("pause");
	 return 0;
}