/*��������
6.	 ���������� �����.����������� ����� � ���������� ������������� ��������� ��������
������� ��������� �� ����������� ��������.���������� ������� �����������, ���������, ��������� ��������, ���������
�����.�������� ��� ������� �� �������� ��� ������������ ������ ��������� �������� �� �������������� ��������.*/


#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <iostream>
#include <array>
using namespace std;
constexpr auto N = 15;

#include <iostream>
using namespace std;


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
int init(int** matrix)//�������� �����
{
	for(int i=0;i<N;i++)//���������� ������
	{
		matrix[i] = (int*)malloc(N * sizeof(int));
		for(int j=0;j<N;j++)
		{
			int a = rand() % 3;
			if (a == 1)  matrix[i][j] = rand() % N;
			else matrix[i][j]=NULL;
		}
	}

	return **matrix;
}

void print(int** matrix,  int& size)//������� �����
{
	int d = 0;
	
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << ++d<<")";
		for (int j = 0; j < N; j++)
		{
				cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void  delete_EL(int**& matrix,int& size)
{
	int a=0;
	cout << "\n\n���� ����� ��������(���� ���� ��������� ������)? :";
	cin >> a;
	a--;
	if (a<0 || a>size) {
		cout << "\n\nHA-HA\n\n";
		return  ;
	}

	for (a;a< size -1;a++)for(int j=0;j<N;j++)matrix[a][j] = matrix[a+1][j], j++;

	*matrix = (int*)realloc(*matrix, sizeof(int)*(--size ));
	free(matrix[14]);
	
}


void add(int**& matrix,int &size)
{
	int kol=0;
	int** temp = NULL;
	cout << "������ �������� ������ ������(x15)?";
	cin >> kol;
	if (kol < 0 || kol>40)
	{
		cout << "\n\nHA-HA\n\n";
		return  ;
	}
	
	temp = (int**)malloc((size + kol) * sizeof(int*));
	for (int i = 0; i < size; i++)
		temp[i] = matrix[i];

	size = size + kol;
	for (int i= size-kol; i <size ; i++)
	{
		temp[i] = (int*)malloc(N * sizeof(int));
		for (int j = 0;j<N;j++)
		{
			auto a = rand() % 3;
			if (a == 1) temp[i][j] = rand() % N;
			else temp[i][j] = NULL;
		}
	
	}
	cout << endl;
	matrix = temp;
	*matrix = (int*)realloc(*temp, sizeof(int) * (size));

}


void vek(vector<int>& v, int** matrix, int& size)
{
	for (int i=0;i< size;i++)
		for(int j = 0; j < N; j++)
         if  (matrix[i][j]!=0)   
				v.push_back(matrix[i][j]);

}

void new_mas(int*& m, int** matrix, int& size,int& d)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < N; j++)
			if (matrix[i][j] != 0)
		{
				m[d++] = matrix[i][j];
			
		}
}


int main() {
	setlocale(LC_ALL, "Russian");
	//��������� ������.
	
	
	
	
	
	
	
	int size = N;
	int** matrix= (int**)malloc(size * sizeof(int**));

	init(matrix);//���������� ���

	//����� ������ �� �����.
	print(matrix, size);
	//�������� ���� �������
	 delete_EL(matrix, size);
	print(matrix, size);
	//������  �-�������
	add(matrix, size);
	int ar = 0;
	int* mas = new int[256];
		new_mas( mas, matrix, size,ar);
	
	int t = clock();
	cout << "\n\n�a���" << endl;
	for (int i = 0; i < ar; i++)
		cout << mas[i] << " ";
    t = clock() - t;
	cout << "��� ������� �� ������: " << t << endl;
	

		vector<int>  vektor;
		vek(vektor, matrix, size);
		 t = clock();
		cout << "\n\nVektor" << endl;
		for (int n : vektor) { cout << n << " "; }
		t = clock() - t;
		cout << "\n��� ������� �� �������: " << t  << endl;
		
		///��������� ������
	for (int i = 0; i < size; i++)
		free(matrix[i]);
		free(matrix);
	
	return 0;
}