
#include "prototaype.h"


struct ElHashTabl
{
	int key;
	int idn;
	int age;
	string name;
	string stan;
	ElHashTabl* next;
};



void Init(ElHashTabl*& p) {
	p = new ElHashTabl;
	p->next = NULL;
}

void Riad_FL(ElHashTabl* h)
{
	
	ElHashTabl* p = h;
	std::ifstream fOpen;
	int value, temp = 0;
	std::string text, adresa;

	fOpen.open("Arzt.txt", std::ios_base::in);
	if (!fOpen)
	{
		std::cout << "File is not open\n\n";
		return;
	}
	while (!fOpen.eof()) {
		ElHashTabl* add = new ElHashTabl;
		add->next = p->next;
		p->next = add;
		fOpen >> add->idn;
		fOpen >> add->age;
		fOpen >> add->name;
		fOpen >> add->stan;
		p = p->next;
		kol++;
	}

	fOpen.close();
}


int Hash(int x)		//функція хешування
{
	/*x = 4*x;*/

	return x % kol;
}


int Insert(int adr, int key , int v2,string t1,string t2, ElHashTabl* hashTabl)	//додавання ключа у хеш-таблицю
{
	int addr, a1;
	addr = Hash(key);
	if (/*hashTabl[addr].adr != EMPTY &&*/ hashTabl[addr].idn != EMPTY && hashTabl[addr].age != EMPTY)
	{
		a1 = addr;
		do
		{
			addr = Hash(addr + 1);
		} while (!((addr == a1) || (hashTabl[addr].idn == EMPTY)));
		if (hashTabl[addr].idn != EMPTY && hashTabl[addr].age )
			return 0;
	}
	hashTabl[addr].key = key;
	hashTabl[addr].idn = adr;
	hashTabl[addr].age = v2;
	hashTabl[addr].name = t1;
	hashTabl[addr].stan = t2;

	return 1;
}
int Search(int key, ElHashTabl* hashTabl)		//функція пошука ключа
{
	int addr, a1;
	addr = Hash(key);
	if (hashTabl[addr].idn == EMPTY)
		return EMPTY;	//місце вільне – ключа немає в таблиці
	else
		if (hashTabl[addr].key == key)
			return addr;	//ключ знайдений на своєму місці
		else     			//місце зайняте іншим ключем
		{
			a1 = Hash(addr + 1);
			//Пошук, поки не знайдений ключ чи не зроблене повне обертання
			while ((hashTabl[a1].key != key) && (a1 != addr))
				a1 = Hash(a1 + 1);
			if (hashTabl[a1].key != key)
				return EMPTY;
			else
				return a1;
		}
}



void saveFL(ElHashTabl* hashTabl)
{
	std::fstream fOpen,key;
	string adressa;
	cout << "Введіть назву файлу куди хочете зберегти данні: ";
	cin >> adressa;
	fOpen.open(adressa+".txt", std::ios_base::out);
	key.open("key.txt", std::ios_base::out);

	for(int i=0;i<kol;i++) {
		fOpen   <<hashTabl[i].idn<<" " << hashTabl[i].age << " "
			<< hashTabl[i].name << " " << hashTabl[i].stan << " " << std::endl;
		key << hashTabl[i].key << endl;
	}
	fOpen.close();
	key.close();
}

void poshuk(ElHashTabl* hashTabl)
{
	int key = 0;
	cout << "введіть ключ" << endl;
		cin >> key;
	
			int res = Search(key, hashTabl);
			if (res == EMPTY)	  cout << " not search \n";
			else	cout <<"idn   age name  stan"<<endl << hashTabl[res].idn << " " << hashTabl[res].age 
				<< " " << hashTabl[res].name << " " << hashTabl[res].stan << " " << std::endl;
			system("pause");

}


void hoho(ElHashTabl*& h, ElHashTabl*& hashTabl)
{
	int i = 0;
	ElHashTabl* p = h->next;
	if (hashTabl != nullptr)	delete[] hashTabl;

	 hashTabl = new ElHashTabl [kol];
	for (int i = 0; i < kol; i++)
		hashTabl[i].idn = EMPTY;
	while (p!=NULL)
	{
		int value1 = p->idn;
		int value2 = p->age;
		string text1 = p->name;
		string text2 = p->stan;
		i++;
		Insert(value1, i*22, value2,text1, text2, hashTabl);
		p = p->next;

	}
	saveFL(hashTabl);


}

void print(ElHashTabl* hashTabl)
{
	cout << ".key << .idn  << .age  <<.name <<.stan <<  " << std::endl;
	for(int i=0;i<kol;i++)
		cout << hashTabl[i].key << " " << hashTabl[i].idn << " " << hashTabl[i].age << " " << hashTabl[i].name << " " << hashTabl[i].stan << " " << std::endl;
	system("pause");
}
void add(ElHashTabl*& h,ElHashTabl*&hashTabl)
{
	ElHashTabl* p = h;
	while (p->next != 0)
	{
		p = p->next;
	}

		ElHashTabl* add = new ElHashTabl;
		add->next = p->next;
		p->next = add;
		cout << "\n Введіть idn:";
		cin >> add->idn;
		cout << "\n Введіть вік паціента :";
		cin >> add->age;
		cout << "\n Введіть имя паціента або прізвище :";
		cin >> add->name;
		cout << "\n Введіть стан паціента :";
		cin >> add->stan;
		kol++;
		hoho(h, hashTabl);
}

int delet(ElHashTabl* h ,ElHashTabl*& hashTabl)
{
	int key = 0;
	cout << "введіть ключ";
	cin >> key;

	int res = Search(key, hashTabl);
	if (res == EMPTY|| hashTabl[res].key == EMPTY)	  cout << " not search \n",system("pause");
	else {
		 hashTabl[res].key = EMPTY;
		 hashTabl[res].idn = EMPTY;
		hashTabl[res].age = EMPTY;
		hashTabl[res].name = EMPTY;
		 hashTabl[res].stan = EMPTY;
	}
	return 0;
}

void menu()
{
	system("cls");
	cout << "  1. Вивести на екран\n 2.Додати елемент\n  3.Пошук по ключу\n 4. Зберегти у файл\n  5.Видалити елемент\n 6. Nach Hause\n\n  Ваш вибір:";
}


int run()
{
	ElHashTabl* p,* hashTabl=nullptr;
	
	Init(p);
	Riad_FL(p);
	hoho(p, hashTabl);

	while (true)
	{
		int a;
		menu();
		cin >> a;
		switch (a)
		{
		case 1:print(hashTabl);
			break;
		case 2:add(p, hashTabl);
			break;
		case 3:poshuk(hashTabl);;
			break;
		case 4: saveFL( hashTabl);
			break;
		case 5:delet(p, hashTabl);
			break;
		case 6:return 0;
			break;
		}
			


	}


}

int main()
{
	setlocale(LC_CTYPE, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	run();

	return 0;
}