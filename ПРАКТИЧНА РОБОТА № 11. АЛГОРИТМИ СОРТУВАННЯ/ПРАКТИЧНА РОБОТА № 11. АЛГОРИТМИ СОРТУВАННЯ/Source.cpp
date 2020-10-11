#include<iostream>
#include<conio.h>
#include "prototaype.h"
 

#define N 20	//������� �������� � �����

void Create(int[]);
void CopyArray(const int[], int[]);
void OutConsole(int[]);
void BubblePriznakSort(int[],int);//����������� ���������� � ���������
void ShellSort(int[],int); //8.	����������  �����

void main()
{
	int time=0;
	setlocale(LC_CTYPE, "rus");	// ��� ������ � ���������
	int array[N], copyArray[N];
	Create(array);

	std::cout << "�������� ������ \n";
	OutConsole(array);
	CopyArray(array, copyArray);

	time = kon3;
		std::cout << "\n\n��������������� �����: ����������� ���������� � �������� \n";
		BubblePriznakSort(array,1);//����������� ���������� � ���������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	//std::cout << "�������� ������ \n";
		//OutConsole(array);
	time = kon3;	
	std::cout << "\n\n��������������� ������: ����������  �����  \n";
		ShellSort(array,1);//����������  �����
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

//	cout << "\n\n�������� ������i��� ������: " << kon3  << endl << endl;
	std::cout << "\n\n��������������� �����: ����������� ���������� � �������� ������� \n";
	BubblePriznakSort(array, -1);//����������� ���������� � ���������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);

	time = kon3;
	std::cout << "\n\n��������������� ������: ����������  ����� ������� \n";
	ShellSort(array, -1);//����������  �����
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

	cout << "\n\n�������� ������i��� ������: " << kon3 << endl << endl;
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
void BubblePriznakSort(int a[],int b)//����������� ���������� � ���������
{ bool pr;			// ��� �������� ������������ �� ������
int d = 0, op = 0;
do
	{
	
		pr = false;
		for (int i = 0; i < N - 1; i++)	// �������� ����� �������
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
	cout << "�i���i��� ���i�����: " << op << endl;
	cout << "�i���i��� ������������: " << d << endl;

}
void ShellSort(int a[],int b)//8.	����������  �����
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
			
	cout << "�i���i��� ���i�����: " << 0 << endl;
	cout << "�i���i��� ������������: " << p << endl;
}