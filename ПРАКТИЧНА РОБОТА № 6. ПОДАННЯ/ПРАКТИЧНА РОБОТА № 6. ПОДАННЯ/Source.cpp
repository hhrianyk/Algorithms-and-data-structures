#include <iostream>
#include <cstring>
#include <cstdio>
#include "stdio.h"
#include <Windows.h>

#include <vector>
#include <iostream>
#include "prototaype.h"

using namespace std;

 
struct ryadok {
	char s;
	ryadok* next;
};

void ADD_ryadok(ryadok* p, char* str)//заповнити  список
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
	{
		p->next = (ryadok*)malloc(sizeof(ryadok));
		p = p->next;
		p->s = str[i];
		p->next = 0;
	}
}

void pidryadok(ryadok*p, ryadok*d,  int a)//додати підрядок
{
	ryadok* du = d;
	for (int i = 0; i < a-1; i++)
		p = p->next;
	while (du->next != 0)
		du = du->next;
	du->next = p->next;
		p->next = d->next;

}

void vektor(ryadok* p, std::stringstream& str)
{
	char s1;
	int i = 0;
	string str2;
    ryadok* pr = p->next;
    while (pr != 0)
    {
	str2+= pr->s;
		pr = pr->next;

	}

	
	str << str2.size()<<" "<< str2;
	
		
}


int  main(void)
{
	ryadok* p;
	ryadok* d;
	p = (ryadok*)malloc(sizeof(ryadok));
	d = (ryadok*)malloc(sizeof(ryadok));
	p->next = NULL;
	d->next = NULL;
	setlocale(LC_ALL, "Rus");
	char* str = (char*)malloc(50 * sizeof(char*));
	char* substr = (char*)malloc(50 * sizeof(char));
	int poz=1,позиція;
	cout << " Введіть текст? :  ";
	cin>>str;
	cout << " Введіть подстоку:  ";
	cin>>substr;
	cout << " Введіть позицію :  ";
	cin >> позиція;
	ADD_ryadok(p, str);
	ADD_ryadok(d, substr);
	pidryadok(p,d, позиція);
	std::stringstream  ver;
	vektor(p,ver);
	cout <<"\nВектор з лічильником:"<< ver.str() <<endl;

  


	cout << "\n\nВивод через односвязний список: ";
	p = p->next;
	while (p->next!=NULL){
		cout << p->s;
		p = p->next;
	}
	cout << endl << endl;


}
