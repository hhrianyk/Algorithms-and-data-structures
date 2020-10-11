#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
#define N 10000
#define kol clock() 

int linearSearch(int[], int, int);//Функція лінійного пошуку
int BinSearch(int[], int );//Функція бінарного пошуку.
int LinearSearchWithBarrier(int arr[], int key);//Функція лінійного пошуку з бар’єром.

int main(void)
{
setlocale(LC_CTYPE, "rus");	// для роботи з кирилицею
	cout << "кiлькiсть елементiв " << N << endl;
	
	int time = 0;
	int a[N], searchKey, element;
	bool el;
	for (int x = 0; x <N; x++)
		a[x] = x;
	std::cout << "Введіть ключ пошуку - ціле число:  ";
	std::cin >> searchKey;
	time = kol;
	element = linearSearch(a, searchKey, N);//лінійний пошук
	cout << "\nлiнiйний пошук\n";
	if (element != -1)
		std::cout << "Кількість порівнянь: "<< element+1<<"\nнайдено значення в елементі " << element << std::endl;
	else
		std::cout << "Кількість порівнянь: " << N<< "\nЗначення не знайдено" << std::endl;
	cout << "Тривалість роботи " << kol-time << endl;
	time = kol;
	cout << "\nФункцiя бiнарного пошуку\n";
	element = BinSearch(a, searchKey); //Функція бінарного пошуку.
		if (element != -1)
		std::cout << "Знайдено значення в елементі " << element << std::endl;
	else
			std::cout << "Кількість порівнянь: " << N << "\nЗначення не знайдено" << std::endl;
		cout << "Тривалість роботи " << kol - time << endl;
		time = kol;
		cout << "\nФункція лінійного пошуку з бар’єром\n";
	element = LinearSearchWithBarrier(a, searchKey );//Функція лінійного пошуку з бар’єром.
		if (element != -1)
		std::cout << "Кількість порівнянь: " << element + 1 << "\nЗнайдено значення в елементі " << element << std::endl;
	else
		std::cout << "Кількість порівнянь: " << N << "\nЗначення не знайдено" << std::endl;
		cout << "Тривалість роботи " << kol - time << endl;
		
	return 0;
}



int linearSearch(int array[], int key, int sizeOfArray)//лінійний пошук
{ 
	
	for (int n = 0; n < sizeOfArray; n++)
		if (array[n] == key)
			return n ;
			
	return -1;
}

int BinSearch(int arr[], int key)
{
	int n = 0;
	int m, b = 0, e = N; 		// початкові значення меж
	while (b <= e) 		//поки інтервал не звузиться до 0
	{
		n++;
		m = (b + e) / 2; 		//середина інтервалу
		if (arr[m] >= key) e = m - 1;
		else b = m + 1;
	}
	std::cout << "Кількість порівнянь: " << n << endl;
	if (arr[b] == key) return b;
	else return -1;
} 

	int LinearSearchWithBarrier(int arr[], int key)//Функція лінійного пошуку з бар’єром.
	{
		unsigned i = 0;
		arr[N] = key;
		while (arr[i] != key) i++;
		if (i == N) return  -1; else return i;
	}

