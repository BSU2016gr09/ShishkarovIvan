// This programm calculate integral of 3 funcs. 
#include <iostream>

using namespace std;

float mySin(float x) {
	return sin(x);
}

float x2(float x) {
	return x * 2;
}

float inv(float x) {
	return 1 / x;
}

typedef float (*pf)(float);

float caclIntegral(float a, float b,pf, float e);// Лучше так: float caclIntegral(float, float,pf, float);

int main() {

	pf funcs[] = { mySin,x2,inv };
	int choise;
	cout << "please,choose your functoin : \n type 1 for sin \n type 2 for x^2 \n type 3 for inverse\n";
	cin >> choise;
	
	if (choise > 3 && choise < 0) return 0;
	
	float dLim;
	float upLim;
	float e;

	cout << "type down limit\n";
	cin >> dLim;
	cout << "type down limit\n";
	cin >> upLim;
	cout << "type accuracy\n";
	cin >> e;

	cout<<"your integral is equal to "<<caclIntegral(dLim, upLim, funcs[choise-1], e)<<"\n";
	system("pause");
	return 0;
}
float caclIntegral(float a, float b,pf fun, float e) {
	float etalon ;
	float sum = 0;
	int n = 1;
	do{
		etalon = sum;
		float x = a;
		n += n; // такая запись использована так как Вы говорили о том,что, где можно заменить умножение сложением,стоит заменять.
		float l = (b - a) / n;
		float rez = 0;
		while (x<b)
		{
			rez = fun(x);
			x += l;
			sum += rez*l;
		}
	
	} while (etalon - sum > e);
	return sum;
}
