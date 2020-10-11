//#include<iostream>
#include<conio.h>
#include "prototaype.h"

#define swap(x,y)  {int t=x; x=y; y=t;}

#define N 20	//кількість елементів у масиві

void Create(int[]);
void CopyArray(const int[], int[]);
void OutConsole(int[]);


void HeapSort(int[],int);//2.	Пірамідальне сортування
void Hoara_Sort(int [], int , int ,int&,int,int& );//5.Сортування Хоара
void RSort(int a[]);//7.	Сортування виродженим розподілом
void RSort2(int a[]);//7.	Сортування виродженим розподілом



int main()
{
	int time = 0;
	setlocale(LC_CTYPE, "rus");	// для роботи з кирилицею
	int array[N], copyArray[N];
	Create(array);

	std::cout << "Исходный массив \n";
	OutConsole(array);
	CopyArray(array, copyArray);

	time = kon3;
	std::cout << "\n\nОтсортированный масси: Пірамідальне сортування \n";
	HeapSort(array,-1);//2.	Пірамідальне сортування
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;


	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\nОтсортированный массив: Сортування  Хоара \n";
	int p = 0,iop=0;
	Hoara_Sort(array,0,N-1,p,1,iop); //5.	Сортування Хоара
	cout << "кiлькiсть перестановок: " << iop << endl;
	cout << "кiлькiсть порівнянь: " << p << endl;
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\nОтсортированный массив: Сортування виродженим розподілом \n";
	RSort(array); //7.	Сортування виродженим розподілом
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;


	time = kon3;
	std::cout << "\n\nОтсортированный масси: Пірамідальне сортування навпаки\n";
	HeapSort(array,-1);//2.	Пірамідальне сортування
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;


	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\nОтсортированный массив: Сортування  Хоара навпаки \n";
	p = 0,iop=0;
	Hoara_Sort(array, 0, N - 1, p,-1,iop); //5.	Сортування Хоара
	cout << "кiлькiсть перестановок: " << iop << endl;
	cout << "кiлькiсть порівнянь: " << p << endl;
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\nОтсортированный массив: Сортування виродженим розподілом навпаки \n";
	RSort2(array); //7.	Сортування виродженим розподілом
	OutConsole(array);
	cout << "Тривалiсть роботи: " << kon3 - time << endl << endl;



	cout << "\n\nЗагальна Тривалiсть роботи: " << kon3 << endl << endl;

	return 0;
}
void Create(int a[])
{
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
	int go = 2 + 3;
}
void CopyArray(const int a[], int copy_a[])
{
	for (int i = 0; i < N; i++)
		copy_a[i] = a[i];
}
void OutConsole(int a[])
{
	for (int i = 0; i < N; i++)
		std::cout << "  " << a[i];
	
}


// Пирамидальная сортировка
void downHeap(int a[], int k, int n,int po) // Процедура просеивания следующего элемента 
{ // До процедуры: a[k+1]...a[n]  - пирамида 
  // После:  a[k]...a[n]  - пирамида 
	int new_elem;
	int child;
	new_elem = a[k];
	while (k <= n / 2)  		// пока у a[k] есть дети 
	{
		child = 2 * k;
		// выбираем большего сына 
		if (child < n && a[child] <a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		a[k] = a[child]; 	//  иначе переносим сына наверх 
		k = child;
	}
	a[k] = new_elem;
}
// Пирамидальная сортировка
void HeapSort(int a[],int po)
{
	int p=0;
	int i;
	int op = 0;
	// строим пирамиду
	for (i = N / 2 - 1; i >= 0; i--) downHeap(a, i, N - 1,po),op++;
	// теперь a[0]...a[size-1] пирамида
	for (i = N - 1; i > 0; i--)
	{ // меняем первый с последним
		swap(a[i], a[0]);	
		p++;
		// восстанавливаем пирамидальность a[0]...a[i-1]
		downHeap(a, 0, i - 1,po);
		op++;
	
	}
	cout << "кiлькiсть перестановок: " << p << endl;
	cout << "кiлькiсть порівнянь: " << op << endl;


}



void Hoara_Sort(int a[], int b, int e,int &p,int t,int &pr)
{
	
	int i = b;
	int j = e;
	
	int tmp = 0;
	int x = t*a[(i + j) / 2];
	do {
		while (t*a[i] < x) i++;
		while (t*a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
			pr++;
		}
		p++;
	} while (i <= j);
	if (i < e)  Hoara_Sort(a, i, e,p,t,pr);
	if (b < j)  Hoara_Sort(a, b, j,p,t,pr);

	

}



void RSort(int a[])//7.	Сортування виродженим розподілом
{
	int i, j, p, stat[256], d = 0, op = 0;;
	for (i = 0; i < 256; i++)	// Обнуляем массив статистики
		stat[i] = 0;
	for (i = 0; i < N; i++)	// Записываем сколько раз встретилось каждое число
		stat[a[i]]++;
	p = 0;
	for (i = 0; i < 256; i++)	// Пишем числа в массив по порядку
		for (j = 0; j < stat[i]; j++) a[p++] = i, d++;
	cout << "кiлькiсть порiвнянь: " << op << endl;
	cout << "кiлькiсть перестановок: " << d << endl;
}
void RSort2(int a[])//7.	Сортування виродженим розподілом
{
	int i, j, p, stat[256], d = 0;
	for (i = 0; i < 256; i++)	// Обнуляем массив статистики
		stat[i] = 0;
	for (i = 0; i < N; i++)	// Записываем сколько раз встретилось каждое число
		stat[a[i]]++;
	p = N - 1;
	for (i = 0; i < 256; i++)	// Пишем числа в массив по порядку
		for (j = 0; j < stat[i]; j++) a[p--] = i, d++;
	cout << "кiлькiсть порiвнянь: " << 0 << endl;
	cout << "кiлькiсть перестановок: " << d << endl;
}
