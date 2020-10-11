#include "prototaype.h"
using namespace std;
constexpr auto N = 10;
void RandArray(int a[N][N]) //формирование исходного массива
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (j%2==0) a[i][j] = (rand() % 50)+1;
			else a[i][j] = 0;
}
void PrintArray(int a[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%3i", a[i][j]);
		printf("\n");
	}
}
void main()
{
	int p = 0;
	int vec[N * N / 2 ];
	int array[N][N];
	RandArray(array);
	PrintArray(array);
	printf("\n");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if ((j % 2) == 0)
			{
			vec[p] = array[i][j];
				p++;
			}
		}//сжатие массива
	for (int i = 0; i < N * N / 2 ; i++)	 //выдача результата сжатия
		printf("%3i", vec[i]);
	printf("\n\n");
	p = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)	//чтение из сжатого представления
		{
			if ((j % 2) == 0)
			{
				array[i][j] =vec[p++] ;	
			}
			else
				array[i][j] = 0;
			printf("%3i", array[i][j]);
		}
		printf("\n");
	}
	int i, j;
	std::cout << "Enter a value i:";
	cin >> i;
	std::cout << "\nEnter a value j:";
	cin >> j;
	cout << "your array:" << array[i-1][j-1];
}
