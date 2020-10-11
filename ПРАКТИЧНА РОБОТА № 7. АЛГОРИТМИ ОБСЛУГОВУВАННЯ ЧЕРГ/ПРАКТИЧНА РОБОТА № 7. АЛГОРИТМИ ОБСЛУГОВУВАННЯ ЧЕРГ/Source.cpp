#include <iostream>
using namespace std;
struct Dek
{
	int data; //������ ������
	
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



void AddL(Dek*& p, Dek*& t) //���������� �������� � ������
{
	
	int value;
	cout << "\n�������� > "; cin >> value;

	Dek* h ;
	
	h = (Dek*)malloc(sizeof(Dek));
	h->data = value;
	h->next = p->next;
	p->next->prev = h;
	p->next = h;
	h->prev = p;

	cout << endl << " ��������o\n\n";
}
void AddR(Dek*& p, Dek*& t) //���������� �������� � �����
{
	int value;
	cout << "\n�������� > "; cin >> value;
	Dek* h;
	h = (Dek*)malloc(sizeof(Dek));
	h->data = value;
	h->prev = t->prev;
	t->prev->next = h;
	t->prev = h;
	h->next = t;
	

	cout << endl << " ��������o\n\n";
}
void DeleteL(Dek*& D, Dek*& t) //�������� ������� ��������
{
	//�������� ���������
	Dek* spod = D->next;
	Dek* temp;
	Dek* p = D;
	temp = p->next;
	p->next = temp->next;
	temp->next->prev = p;

	free(temp);

}
void DeleteR(Dek*& D, Dek*& t) //�������� ���������� ��������
{
	Dek* temp;
	Dek* p = t;
	temp = p->prev;
	p->prev = temp->prev;
	temp->prev->next = p;

	free(temp);

}
int OutputL(Dek*& D, Dek*& t) //����� ������� ��������
{
	Dek* p = D->next;
	return p->data;
}
int OutputR(Dek* D, Dek*& t) //����� ���������� ��������
{
	Dek* p = t->prev;
	return p->data;
}


int main() //������� �������
{
	setlocale(LC_ALL, "Rus");
	Dek* h,*t;
	int i=0;
	init(h,t);
	char number;
	do
	{
		cout << "1. �������� ������� � ������" << endl;
		cout << "2. �������� ������� � �����" << endl;
		cout << "3. ������� ������ �������" << endl;
		cout << "4. ������� ��������� �������" << endl;
		cout << "5. ������� ������ �������" << endl;
		cout << "6. ������� ��������� �������" << endl;
		cout << "7. ������ ����" << endl;
		cout << "8. �����\n";
		cout << "9. ������ �������\n" << endl;
		cout << "����� ������� > "; cin >> number;
		switch (number)
		{
		case '1': AddR(h,t);
			break;
		case '2': AddL(h, t);
			break;
		case '3':
			if (h->next==0) cout << endl << "��� ����\n\n";
			else
			{
				DeleteR(h, t);
				cout << endl << "������� ������ �� ����\n\n";
			} break;
		case '4':
			if (h->next == 0) cout << endl << "��� ����\n\n";
			else
			{
				DeleteL(h, t);
				cout << endl << "������� ������\n\n";
			} break;
		case '5':
			if (h->next == 0) cout << endl << "��� ����\n\n";
			else cout << "\n������ �������: " << OutputL(h, t) << "\n\n";
			break;
		case '6':
			if (h->next == 0) cout << endl << "��� ����\n\n";
			else cout << "\n��������� �������: " << OutputR(h, t) << "\n\n";
			break;
		case '7':
			if (h->next == 0) cout << endl << "��� ����\n\n";
			 i = 0;
			while (h->next!=0)
			{
				h = h->next;
				i++;
			}
			cout << "������ ���� " << i-1 << endl;
			break;
		case '8':
			break;
		case '9':AddL(h, t);
			break;
		default: cout << endl << "������� �� ����������\n\n";
			break;
		}
	} while (number != '8');
	system("pause");
}




