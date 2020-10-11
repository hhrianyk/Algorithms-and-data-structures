#include<iostream>
#include<conio.h>
#include "prototaype.h"
 

#define N 20	//кількість елементів у масиві

void Create(int[]);
void CopyArray(const int[], int[]);
void OutConsole(int[]);
void BubblePriznakSort(int[],int);//Пузырьковая сортировка с признаком
void ShellSort(int[],int); //8.	Сортування  Шелла

void main()
{
	int time=0;
	setlocale(LC_CTYPE, "rus");	// для роботи з кирилицею
	int array[N], copyArray[N];
	Create(array);

	std::cout << "Исходный массив \n";
	OutConsole(array);
	CopyArray(array, copyArray);

	time = kon3;
		std::cout << "\n\nОтсортированный масси: Бульбашкове сортування з ознакоюв \n";
		BubblePriznakSort(array,1);//Пузырьковая сортировка с признаком
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	//std::cout << "Исходный массив \n";
		//OutConsole(array);
	time = kon3;	
	std::cout << "\n\nОтсортированный массив: Сортування  Шелла  \n";
		ShellSort(array,1);//Сортування  Шелла
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

//	cout << "\n\nЗагальна Тривалiсть роботи: " << kon3  << endl << endl;
	std::cout << "\n\nОтсортированный масси: Бульбашкове сортування з ознакоюв навпаки \n";
	BubblePriznakSort(array, -1);//Пузырьковая сортировка с признаком
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);

	time = kon3;
	std::cout << "\n\nОтсортированный массив: Сортування  Шелла навпаки \n";
	ShellSort(array, -1);//Сортування  Шелла
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

	cout << "\n\nЗагальна Тривалiсть роботи: " << kon3 << endl << endl;
}
void Create(int a[])
{
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
}
void CopyArray(const int a[], int copy_a[])
{
	for (int i = 0; i < N; i++)
		copy_a[i] = a[i];
}
void OutConsole(int a[])
{
	for (int i = 0; i < 1; i++)
	std::cout << "  " << a[i];
	std::cout << "\n";
}
void BubblePriznakSort(int a[],int b)//Пузырьковая сортировка с признаком
{ bool pr;			// для проверки отсортирован ли массив
int d = 0, op = 0;
do
	{
	
		pr = false;
		for (int i = 0; i < N - 1; i++)	// проходим слева направо
		{
			op++;
			if (b * a[i] > b* a[i + 1])
			{
				a[i] = a[i] ^ a[i + 1];
				a[i + 1] = a[i] ^ a[i + 1];
				a[i] = a[i] ^ a[i + 1];
				pr = true;
				d++;
			}
		}
	} while (pr);
	cout << "кiлькiсть порiвнянь: " << op << endl;
	cout << "кiлькiсть перестановок: " << d << endl;

}
void ShellSort(int a[],int b)//8.	Сортування  Шелла
{
	int i, j, d,p=0;
	for (int d = N / 2; d >= 1; d /= 2)
		for (int i = d; i < N; i++)
			for (int j = i; j >= d && b*a[j - d] > a[j]*b; j -= d)
			{  p++;
			//if (a[j] > a[j + d])
				
					a[j] = a[j] ^ a[j - d];
					a[j-d] = a[j] ^ a[j - d];
					a[j] = a[j] ^ a[j - d];
			}
			
	cout << "кiлькiсть порiвнянь: " << 0 << endl;
	cout << "кiлькiсть перестановок: " << p << endl;
}