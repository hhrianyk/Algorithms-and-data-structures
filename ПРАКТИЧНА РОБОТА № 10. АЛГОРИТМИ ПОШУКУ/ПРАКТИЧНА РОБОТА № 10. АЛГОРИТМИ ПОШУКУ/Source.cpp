#include <iostream>
#include <cstdlib>
#include <ostream>
#include <cstdio>
#include <iomanip> 
#include <fstream>

using namespace std;

void Init(void);
int Insert(int key, int adr, string, int, int);
int Search(int key);

#define N 15		//������� ������ � �������
#define EMPTY -1

struct ElHashTabl
{
	int key;
	int adr;
	string type_of_aircraft;
	int speed;
	int number_of_passengers;
};



ElHashTabl hashTabl[N];  	//��� - �������


void Riad_FL( )
{
	ifstream fOpen;
	int value1, value2, value3, temp = 0;
	string text, adresa="Text.txt";
	int i = 0;
	fOpen.open(adresa, std::ios_base::in);
	if (!fOpen)
	{
		std::cout << "File is not open\n\n";
		return;

	}
	while (!fOpen.eof()) {
		i++;
		fOpen >> value1;
		fOpen >> text;
		fOpen >> value2;
		fOpen >> value3;
	
		Insert(value1, i, text, value3, value2);
	}

	fOpen.close();
}



int Hash(int x)		//������� ���������
{
	//key = key * key;
	int  mid, sqr;
	
		sqr = x * x;
		mid = (sqr >> 8) & 0xffff;  // ��� ��� ��� � ���� ������
	
		return x%N;
	
}
void Init(void)		//����������� ���-�������
{
	for (int i = 0; i < N; i++)
		hashTabl[i].adr = EMPTY;
}
int Insert(int key, int adr,string s, int n1, int n2)	//��������� ����� � ���-�������
{
	int addr, a1;
	addr = Hash(key);
	if (hashTabl[addr].adr != EMPTY  && hashTabl[addr].number_of_passengers != EMPTY && hashTabl[addr].speed != EMPTY)
	{
		a1 = addr;
		do
		{
			addr = Hash(addr + 1);
		} while (!((addr == a1) || (hashTabl[addr].adr == EMPTY)));
		if (hashTabl[addr].adr != EMPTY&&  hashTabl[addr].number_of_passengers != EMPTY && hashTabl[addr].speed != EMPTY  )
			return 0;
	}
	hashTabl[addr].key = key;
	hashTabl[addr].adr = adr;
	hashTabl[addr].number_of_passengers = n2;
	hashTabl[addr].speed = n1;
	hashTabl[addr].type_of_aircraft= s;

	return 1;
}
int Search(int key)		//������� ������ �����
{
	int addr, a1;
	addr = Hash(key);
	if (hashTabl[addr].adr == EMPTY)
		return EMPTY;	//���� ����� � ����� ���� � �������
	else
		if (hashTabl[addr].key == key)
			return hashTabl[addr].adr;	//���� ��������� �� ����� ����
		else     			//���� ������� ����� ������
		{
			a1 = Hash(addr + 1);
			//�����, ���� �� ��������� ���� �� �� �������� ����� ���������
			while ((hashTabl[a1].key != key) && (a1 != addr))
				a1 = Hash(a1 + 1);
			if (hashTabl[a1].key != key)
				return EMPTY;
			else
				return a1;
		}
}

void main(void)
{
	int i, key, res;
	Init();
	cout << "Number of keys: " << N;
		Riad_FL();
	cout << "\nHashed table \nKod/key  -  adr - pass - speed - aircraft \n ";
	for (i = 0; i < N; i++)
		cout << "  " << setw(5)<<hashTabl[i].key << " - " << setw(3) << hashTabl[i].adr << " - " << setw(3) << hashTabl[i].number_of_passengers << " - "
		<< setw(3) << hashTabl[i].speed << " - " << setw(3) << hashTabl[i].type_of_aircraft <<"\n";
	
	cout << " Input searched keys (key < 0 - exit) -> ";
	cin >> key;
	while (key >= 0)
	{
		res = Search(key);
		if (res == EMPTY)	  cout << " not search \n";
		else	cout << hashTabl[res].adr << " " << hashTabl[res].number_of_passengers << " " << hashTabl[res].speed << " " << hashTabl[res].type_of_aircraft<<endl;

		cout << " Input searched keys (key < 0 - exit) -> ";
		cin >> key;
	}
}