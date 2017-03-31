#pragma once
#include <iostream>

using namespace std;

class Money {
	public:
		int rubles;
		unsigned short int coins;

		void printMoney() {
			cout << "rubles : " << rubles << "\ncoins :" << coins << "\n";
		}
		
		Money diff(Money other) {
			Money rez;
			unsigned short int tmp = 0;
			if (this->coins < other.coins) {
				tmp = 100;
			}
			rez.coins = this->coins + tmp - other.coins ;
			rez.rubles = this->rubles - other.rubles - (tmp / 100);
			return rez;
		}
		Money multByNumb(int numb) {
			Money rez;
			unsigned short int tmp = 0;
			rez.coins = numb * this->coins;
			if (rez.coins>100) {
				 tmp= rez.coins / 100;
				rez.coins %= 100;
			}
			rez.rubles = this->rubles * numb + tmp;
			return rez;
		}

		Money sum(Money other) {
			Money rez;
			unsigned short int tmp = 0;
			rez.coins = this->coins + other.coins;
			if (rez.coins > 100) { 
				tmp = rez.coins / 100; 
				rez.coins %= 100;
			}
			rez.rubles = this->rubles + tmp + other.rubles;
			return rez;
		}

	private:

};
