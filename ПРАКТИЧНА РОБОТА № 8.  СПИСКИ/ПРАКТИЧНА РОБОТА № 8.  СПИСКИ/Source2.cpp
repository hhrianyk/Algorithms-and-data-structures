#include <iomanip>
#include <stdio.h>
#include<fstream>
#include <malloc.h>
#include <string>
#include <iostream>
#include <iostream>
struct Tcity;
struct Tbusinesses;
using namespace std;

struct Tbusinesses
{
	string businesses2;
	Tbusinesses* next;

	Tcity* Cnext;
};

struct Tcity
{
	string city;
	Tbusinesses* businesses;
	Tcity* next;
};

void init(Tbusinesses*& h, Tcity*& p)
{
	//h = (struct Tbusinesses*)malloc(sizeof(Tbusinesses) * 1);
	p = (struct Tcity*)malloc(sizeof(Tcity) * 1);
	p->next = NULL;
	//p->businesses = h;
	//h->Cnext = p->next;
}
void AddL(Tbusinesses*& h, Tcity*& p) //добавление элемента в начало
{
	
	Tcity* pr = p;
	std::ifstream fOpen;
	int value=0, temp = 0;
	std::string text;

	fOpen.open("Text.txt", std::ios_base::in);
	if (!fOpen)
	{
		std::cout << "File is not open\n\n";
		return;
	}
	Tbusinesses* heh;
	//h = heh;
	while (!fOpen.eof()) {
		fOpen >> text;
		Tcity* add = new Tcity;
		Tbusinesses* heh = new Tbusinesses;
		add->next = p->next;
		add->businesses = heh;
		p->next = add;
		
		add->city = text;
		for (int i = 0; i < 5; i++)
		{fOpen >> text;
		Tbusinesses* add2 = new Tbusinesses;
		add2->next = heh->next;
		heh->next = add2;
		add2->businesses2=text;
		heh = heh->next;
		}
		heh->next = 0;
		heh->Cnext=add->next;
		add = add->next;
	}

	fOpen.close();
}
int Output(Tbusinesses*& h, Tcity*& p) //вывод последнего элемента
{
	
	Tcity* pr = p->next;

	do
	{
		cout <<"|"<< setw(9)<<pr->city<<"|";
		do
		{
			cout << pr->businesses->businesses2<<"|";
			pr->businesses = pr->businesses->next;
		} while (pr->businesses != 0 );
		cout << endl;
		pr = pr->next;
	} while (pr != 0);
	return 0;
}


void Delete(Tcity*& p)
{
	Tcity* pr;
	Tbusinesses* pt,*pd ;
	do
	{pr = p->next;
	//pd = p->next;
	do
		{
		pt= pr->businesses;
		pr->businesses = pt->next;
		
			delete(pt);
	} while (pr->businesses!=0);
		p = pr->next;
		delete(pr);
		
	} while (p != 0);
	delete(p);


}



int main()
{
	setlocale(LC_ALL, "ru");
	int i;
	Tcity* p;
	Tbusinesses* h;
	init(h, p);
	char number;
	do
	{
		cout << "1. Добавить элемент " << endl;
		cout << "2. Вывести элемент" << endl;
		cout << "3. Удалить  элементы" << endl;
		cout << "8. Выйти\n\n";
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{
		case '1':
			
			AddL(h, p);
			break;
		case '2':if (p->next == 0) cout << endl << "Дек пуст\n\n";
				else cout << "\nПервый элемент: " << Output(h, p) << "\n\n";;
			break;
		case '3':
			if (p->next == 0) cout << endl << "Дек пуст\n\n";
			else
			{
				Delete(p);
				cout << endl << "Элемент удален из дека\n\n";
				init(h, p);
			} break;
		
		case '8':
			break;
		default: cout << endl << "Команда не определена\n\n";
			break;
		}
	} while (number != '8');




}



