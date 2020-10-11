#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
#define N 10000
#define kol clock() 

int linearSearch(int[], int, int);//������� ������� ������
int BinSearch(int[], int );//������� �������� ������.
int LinearSearchWithBarrier(int arr[], int key);//������� ������� ������ � ������.

int main(void)
{
setlocale(LC_CTYPE, "rus");	// ��� ������ � ���������
	cout << "�i���i��� �������i� " << N << endl;
	
	int time = 0;
	int a[N], searchKey, element;
	bool el;
	for (int x = 0; x <N; x++)
		a[x] = x;
	std::cout << "������ ���� ������ - ���� �����:  ";
	std::cin >> searchKey;
	time = kol;
	element = linearSearch(a, searchKey, N);//������ �����
	cout << "\n�i�i���� �����\n";
	if (element != -1)
		std::cout << "ʳ������ ��������: "<< element+1<<"\n������� �������� � ������� " << element << std::endl;
	else
		std::cout << "ʳ������ ��������: " << N<< "\n�������� �� ��������" << std::endl;
	cout << "��������� ������ " << kol-time << endl;
	time = kol;
	cout << "\n�����i� �i������� ������\n";
	element = BinSearch(a, searchKey); //������� �������� ������.
		if (element != -1)
		std::cout << "�������� �������� � ������� " << element << std::endl;
	else
			std::cout << "ʳ������ ��������: " << N << "\n�������� �� ��������" << std::endl;
		cout << "��������� ������ " << kol - time << endl;
		time = kol;
		cout << "\n������� ������� ������ � ������\n";
	element = LinearSearchWithBarrier(a, searchKey );//������� ������� ������ � ������.
		if (element != -1)
		std::cout << "ʳ������ ��������: " << element + 1 << "\n�������� �������� � ������� " << element << std::endl;
	else
		std::cout << "ʳ������ ��������: " << N << "\n�������� �� ��������" << std::endl;
		cout << "��������� ������ " << kol - time << endl;
		
	return 0;
}



int linearSearch(int array[], int key, int sizeOfArray)//������ �����
{ 
	
	for (int n = 0; n < sizeOfArray; n++)
		if (array[n] == key)
			return n ;
			
	return -1;
}

int BinSearch(int arr[], int key)
{
	int n = 0;
	int m, b = 0, e = N; 		// �������� �������� ���
	while (b <= e) 		//���� �������� �� ��������� �� 0
	{
		n++;
		m = (b + e) / 2; 		//�������� ���������
		if (arr[m] >= key) e = m - 1;
		else b = m + 1;
	}
	std::cout << "ʳ������ ��������: " << n << endl;
	if (arr[b] == key) return b;
	else return -1;
} 

	int LinearSearchWithBarrier(int arr[], int key)//������� ������� ������ � ������.
	{
		unsigned i = 0;
		arr[N] = key;
		while (arr[i] != key) i++;
		if (i == N) return  -1; else return i;
	}

