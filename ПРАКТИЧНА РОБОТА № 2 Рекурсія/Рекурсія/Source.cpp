#include<iostream>
#include<string>
#include "../../LABA1/prototaype.h"
using namespace std;

#define kon3  clock()
float B_R(int,float,int );
float B_I(int, float, int);


int main()
{
	setlocale(LC_ALL, "rus");	// для роботи з кирилицею
	int N = 21,b=0;
 	float a = 0,t=0;
	 cout << "Введіть число(ТІЛЬКИ ДОДАТНІ!!!): " ;
	cin >>  N ;
	cout << "\n В яку систему перевести ваше число(ввод тільки 2-10)? ";
	cin >> b;
	float k = kon3;
	a=B_R(N, a,b)/10;
	t = kon3 - k;
	cout << "\nВаше число в новiй системi :"<<endl;
	cout << "Рекурсивный метод  " << a << " тривалість роботи : " << t << " ms"<< endl;
	k = kon3;

	a = B_I(N, a, b) / 10;
	t =  kon3-k ;
	cout << "Итерационный метод " << a << " тривалість роботи : " << t << " ms"<< endl;
}
float B_R(int N,float a,int b)
{	if (N != 0)
	{
		a=B_R(N / b, a / 10 + (N % b), b);
		a = a * 10;
		return a;
	}
	else  return  a;}

float B_I(int N, float a, int b)
{
	int k=0;
	a = 0;
	do
	{	a = a / 10 + (N % b);
		N = N / b;
		k++;
	} while (N != 0);
	for (int i = 0; i < k; i++) a = a * 10;
	 return  a;
}

