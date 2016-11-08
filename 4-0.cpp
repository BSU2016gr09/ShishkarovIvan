#include <iostream>
#include <clocale>
#include <iomanip>
#include <Windows.h>
using namespace std;
void graphicSin2XDivX(float x,char el);
int main()
{
	float x=-6;
	char el = '*';
	while (x<=6)
	{

		graphicSin2XDivX(x, el);
		x += 0.1;
		Sleep(100);
	}
system("pause");
}
void  graphicSin2XDivX(float x,char el)
{
	float y;
	if (x == 0) x += 0.1;
	y = (sin(2 * x) / x);

	cout << setw(60 + 30 * y) << el << "\n";

}