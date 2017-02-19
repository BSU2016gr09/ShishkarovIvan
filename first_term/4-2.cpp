/* Напишите игру в пьяницу на стеке между компьютером и компьютером. Колода перетусовывается и раздаётся пополам. Они по очереди достают по карте сверху колоды.
Забирает карты и кладёт себе вниз колоды тот у кого очков больше на вытянутых картах (6-ка берет туза, 7-ка берет короля). 
Игра заканчивается если один не может сделать ход. 
Запоминать кол-во ходов в законченной игре. Провести 5000 партий.
Вывести макс./мин./среднее кол-во ходов в этих партиях.*/
#include <iostream>	
#include <clocale>	
#include <iomanip>
#include<ctime>
using namespace std;
void printArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		if(A[i]>0)
			cout << A[i++] << setw(3);
		else i++;
	}
}
void initRandomArray(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		A[i++] = rand() % 10 + 1;
	}


}
void randomSortingArrayUsingAnotherArray(int A[], int N, int B[])
{
	int i = 0, j = 1;
	initRandomArray(B, N);
	while (i < N)
	{

		while (j < N)
		{
			if (B[i] < B[j]) {
				swap(B[i], B[j]); swap(A[i], A[j]);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
void turnArrayRight(int A[], int N) {
	int i = 0, j = 1, k;
	k = A[0];
	while (i <N - 1)
	{
		A[i] = A[j];
		i++;
		j = i + 1;
	}
	A[i] = k;
}
int topCard(int A[], int N,int &end)
{
	int card = 0;
	turnArrayRight(A, N);
	card = A[0];
	end--;
	return card;
}
void Push(int A[], int N, int element,int &end)
{
	int i = N - 1-end;
	A[i] = element;
	end++;
	swap(A[i], A[i- 1]);
}
void reshuffle(int Pack[], int A[],int B[], int N)
{
	int i = 0,j=0,k=0,end=0;
	while (i < N/2)
	{
		A[k++]=topCard(Pack, N,end);
			i++;
}
	
	while (i < N )
	{
		B[j++] = topCard(Pack, N,end);
		i++;
	}

}
int isEmptyPack(int A[], int N)
{
	if (A[0] ==0)
		return 0;
	else return 1;
}
void initPack(int A[], int N)
{
	int i = 0, k = 6;
	while (i < N)
	{
		while (k < 15)
		{
			A[i++] = k++;
		}
		k = 6;
	}
}
void initArray(int A[], int N, int init)
{
	int i = 0;
	while (i < N)
	{
		A[i] = init;
		i++;

	}
}
int  game(int A[], int B[], int Pack[],int Tmp[], int N)
{
	int cardA = 0,cardB=0, i = 0,j=0,course=1,init=0,end=18;
	initArray(A, N, init);
	initArray(B, N, init);
	initPack(Pack, N);
	initRandomArray(Tmp, N);  

	randomSortingArrayUsingAnotherArray(Pack, N, Tmp);
	
	reshuffle(Pack, A, B, N);
	//printArray(A, N);
	cout << "\n";
	//printArray(B, N);
	cout << "\n";
	while ( isEmptyPack(A,N)==1 &&
		isEmptyPack(B,N)==1 )
	{
//	cout << "Cource number " << course << "\n";
		cardA = topCard(A, N, end);
	//	cout << "Card of Player 1 is = " << cardA<<"\n";
		cardB = topCard(B, N, end);
//	cout << "Card of Player 2 is = " << cardB << "\n";

		if (cardA == 6 && cardB == 14)
		{
			Push(A, N, cardA, end); Push(A, N, cardB, end);
//	cout << "Card goes to Player 1\n";
		}
		else if(cardA == 7 && cardB == 13)
		{
			Push(A, N, cardA, end); Push(A, N, cardB, end);
	//		cout << "Card goes to Player 1\n";
		}
		else if (cardB == 6 && cardA == 14)
		{
			Push(B, N, cardA, end); Push(B, N, cardB, end);
		///	cout << "Card goes to Player 2\n";
		}
		else if (cardB == 7 && cardA == 13)
		{
			Push(B, N, cardA, end); Push(B, N, cardB, end);
			//cout << "Card goes to Player 2\n";
		}
		else if (cardA>cardB)
		{
			Push(A, N, cardA, end); Push(A, N, cardB, end);
			//cout << "Card goes to Player 1\n";
		}
		else if (cardB >cardA )
		{
			Push(B, N, cardA, end); Push(B, N, cardB, end);
			//cout << "Card goes to Player 2\n";
		}
		else 
		{
			//cout << "Cards are simillar\n";
			cardA = topCard(A, N, end);
			cardB = topCard(B, N, end);
	
		}
		course++;
	}
	
	if (isEmptyPack(A, N) == 1)
		cout << "player 1 wins";
	else if(isEmptyPack(B, N) == 1)
		cout << "player 2 wins";
	return course;
}
int main()
{	
	srand(time(NULL));
	const int PACK = 36;
	int A[PACK], B[PACK], Pack[PACK], Tmp[PACK], i = 0, max = 16, min = 16, middle = 0,check;
	
	
	while (i < 50)
	{
		check= game(A, B, Pack, Tmp, PACK);
		if (min > check) min = check;
		else if (max < check) max = check;
		middle += check;
		i++;
	}
	middle /= 50;
	cout << "\nmiddle =" << middle << "\n max =" << max << "\n min =" << min;
	system("pause");

}
