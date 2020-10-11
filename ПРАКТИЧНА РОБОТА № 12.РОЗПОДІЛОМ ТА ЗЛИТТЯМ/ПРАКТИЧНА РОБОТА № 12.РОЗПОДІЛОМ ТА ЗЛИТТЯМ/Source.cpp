//#include<iostream>
#include<conio.h>
#include "prototaype.h"

#define swap(x,y)  {int t=x; x=y; y=t;}

#define N 20	//������� �������� � �����

void Create(int[]);
void CopyArray(const int[], int[]);
void OutConsole(int[]);


void HeapSort(int[],int);//2.	ϳ��������� ����������
void Hoara_Sort(int [], int , int ,int&,int,int& );//5.���������� �����
void RSort(int a[]);//7.	���������� ���������� ���������
void RSort2(int a[]);//7.	���������� ���������� ���������



int main()
{
	int time = 0;
	setlocale(LC_CTYPE, "rus");	// ��� ������ � ���������
	int array[N], copyArray[N];
	Create(array);

	std::cout << "�������� ������ \n";
	OutConsole(array);
	CopyArray(array, copyArray);

	time = kon3;
	std::cout << "\n\n��������������� �����: ϳ��������� ���������� \n";
	HeapSort(array,-1);//2.	ϳ��������� ����������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;


	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\n��������������� ������: ����������  ����� \n";
	int p = 0,iop=0;
	Hoara_Sort(array,0,N-1,p,1,iop); //5.	���������� �����
	cout << "�i���i��� ������������: " << iop << endl;
	cout << "�i���i��� ��������: " << p << endl;
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\n��������������� ������: ���������� ���������� ��������� \n";
	RSort(array); //7.	���������� ���������� ���������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;


	time = kon3;
	std::cout << "\n\n��������������� �����: ϳ��������� ���������� �������\n";
	HeapSort(array,-1);//2.	ϳ��������� ����������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;


	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\n��������������� ������: ����������  ����� ������� \n";
	p = 0,iop=0;
	Hoara_Sort(array, 0, N - 1, p,-1,iop); //5.	���������� �����
	cout << "�i���i��� ������������: " << iop << endl;
	cout << "�i���i��� ��������: " << p << endl;
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;

	CopyArray(copyArray, array);
	time = kon3;
	std::cout << "\n\n��������������� ������: ���������� ���������� ��������� ������� \n";
	RSort2(array); //7.	���������� ���������� ���������
	OutConsole(array);
	cout << "������i��� ������: " << kon3 - time << endl << endl;



	cout << "\n\n�������� ������i��� ������: " << kon3 << endl << endl;

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


// ������������� ����������
void downHeap(int a[], int k, int n,int po) // ��������� ����������� ���������� �������� 
{ // �� ���������: a[k+1]...a[n]  - �������� 
  // �����:  a[k]...a[n]  - �������� 
	int new_elem;
	int child;
	new_elem = a[k];
	while (k <= n / 2)  		// ���� � a[k] ���� ���� 
	{
		child = 2 * k;
		// �������� �������� ���� 
		if (child < n && a[child] <a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		a[k] = a[child]; 	//  ����� ��������� ���� ������ 
		k = child;
	}
	a[k] = new_elem;
}
// ������������� ����������
void HeapSort(int a[],int po)
{
	int p=0;
	int i;
	int op = 0;
	// ������ ��������
	for (i = N / 2 - 1; i >= 0; i--) downHeap(a, i, N - 1,po),op++;
	// ������ a[0]...a[size-1] ��������
	for (i = N - 1; i > 0; i--)
	{ // ������ ������ � ���������
		swap(a[i], a[0]);	
		p++;
		// ��������������� ��������������� a[0]...a[i-1]
		downHeap(a, 0, i - 1,po);
		op++;
	
	}
	cout << "�i���i��� ������������: " << p << endl;
	cout << "�i���i��� ��������: " << op << endl;


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



void RSort(int a[])//7.	���������� ���������� ���������
{
	int i, j, p, stat[256], d = 0, op = 0;;
	for (i = 0; i < 256; i++)	// �������� ������ ����������
		stat[i] = 0;
	for (i = 0; i < N; i++)	// ���������� ������� ��� ����������� ������ �����
		stat[a[i]]++;
	p = 0;
	for (i = 0; i < 256; i++)	// ����� ����� � ������ �� �������
		for (j = 0; j < stat[i]; j++) a[p++] = i, d++;
	cout << "�i���i��� ���i�����: " << op << endl;
	cout << "�i���i��� ������������: " << d << endl;
}
void RSort2(int a[])//7.	���������� ���������� ���������
{
	int i, j, p, stat[256], d = 0;
	for (i = 0; i < 256; i++)	// �������� ������ ����������
		stat[i] = 0;
	for (i = 0; i < N; i++)	// ���������� ������� ��� ����������� ������ �����
		stat[a[i]]++;
	p = N - 1;
	for (i = 0; i < 256; i++)	// ����� ����� � ������ �� �������
		for (j = 0; j < stat[i]; j++) a[p--] = i, d++;
	cout << "�i���i��� ���i�����: " << 0 << endl;
	cout << "�i���i��� ������������: " << d << endl;
}
