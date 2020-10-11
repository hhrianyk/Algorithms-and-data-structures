#include <iostream>
using namespace std;
struct Dek
{
	int data; //массив данных
	
	Dek* next, *prev;
};
void init(Dek*& h, Dek*& t)
{
	h = (struct Dek*)malloc(sizeof(Dek) * 1);
	t = (struct Dek*)malloc(sizeof(Dek) * 1);
	h->next = t;
	t->prev = h;
	h->prev = NULL;
	t->next = NULL;
}



void AddL(Dek*& p, Dek*& t) //добавление элемента в начало
{
	
	int value;
	cout << "\nЗначение > "; cin >> value;

	Dek* h ;
	
	h = (Dek*)malloc(sizeof(Dek));
	h->data = value;
	h->next = p->next;
	p->next->prev = h;
	p->next = h;
	h->prev = p;

	cout << endl << " добавленo\n\n";
}
void AddR(Dek*& p, Dek*& t) //добавление элемента в конец
{
	int value;
	cout << "\nЗначение > "; cin >> value;
	Dek* h;
	h = (Dek*)malloc(sizeof(Dek));
	h->data = value;
	h->prev = t->prev;
	t->prev->next = h;
	t->prev = h;
	h->next = t;
	

	cout << endl << " добавленo\n\n";
}
void DeleteL(Dek*& D, Dek*& t) //удаление первого элемента
{
	//смещение элементов
	Dek* spod = D->next;
	Dek* temp;
	Dek* p = D;
	temp = p->next;
	p->next = temp->next;
	temp->next->prev = p;

	free(temp);

}
void DeleteR(Dek*& D, Dek*& t) //удаление последнего элемента
{
	Dek* temp;
	Dek* p = t;
	temp = p->prev;
	p->prev = temp->prev;
	temp->prev->next = p;

	free(temp);

}
int OutputL(Dek*& D, Dek*& t) //вывод первого элемента
{
	Dek* p = D->next;
	return p->data;
}
int OutputR(Dek* D, Dek*& t) //вывод последнего элемента
{
	Dek* p = t->prev;
	return p->data;
}


int main() //главная функция
{
	setlocale(LC_ALL, "Rus");
	Dek* h,*t;
	int i=0;
	init(h,t);
	char number;
	do
	{
		cout << "1. Добавить элемент в начало" << endl;
		cout << "2. Добавить элемент в конец" << endl;
		cout << "3. Удалить первый элемент" << endl;
		cout << "4. Удалить последний элемент" << endl;
		cout << "5. Вывести первый элемент" << endl;
		cout << "6. Вывести последний элемент" << endl;
		cout << "7. Размер дека" << endl;
		cout << "8. Выйти\n";
		cout << "9. Додати елемент\n" << endl;
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{
		case '1': AddR(h,t);
			break;
		case '2': AddL(h, t);
			break;
		case '3':
			if (h->next==0) cout << endl << "Дек пуст\n\n";
			else
			{
				DeleteR(h, t);
				cout << endl << "Элемент удален из дека\n\n";
			} break;
		case '4':
			if (h->next == 0) cout << endl << "Дек пуст\n\n";
			else
			{
				DeleteL(h, t);
				cout << endl << "Элемент удален\n\n";
			} break;
		case '5':
			if (h->next == 0) cout << endl << "Дек пуст\n\n";
			else cout << "\nПервый элемент: " << OutputL(h, t) << "\n\n";
			break;
		case '6':
			if (h->next == 0) cout << endl << "Дек пуст\n\n";
			else cout << "\nПоследний элемент: " << OutputR(h, t) << "\n\n";
			break;
		case '7':
			if (h->next == 0) cout << endl << "Дек пуст\n\n";
			 i = 0;
			while (h->next!=0)
			{
				h = h->next;
				i++;
			}
			cout << "размер дека " << i-1 << endl;
			break;
		case '8':
			break;
		case '9':AddL(h, t);
			break;
		default: cout << endl << "Команда не определена\n\n";
			break;
		}
	} while (number != '8');
	system("pause");
}




