#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class CtreeNode
{public:
	int key;				//ключ
	int info;			//информационное поле
	CtreeNode* LLink, * RLink; //указатель на левый и правый узел	

	CtreeNode() { key = 0; LLink = RLink = NULL; } //конструктор по умолчанию
	CtreeNode(int k, int info_c)	     //конструктор с параметр
	{
		key = k;
		info = info_c;
		LLink = RLink = NULL;
	}
	~CtreeNode()			//Деструктор
	{
	}
	//функция добавления элемента в дерево. Возвращает указатель на корень
	void Insert(int number, int info, CtreeNode* ptr);
	void PrintTree(CtreeNode* ptr, int n);
	void DeleteTree(CtreeNode* ptr);
};
void preOrder(CtreeNode*& root,int& n, int k_elem)//функции нисходящего обхода.
{
	CtreeNode* current = root;
	if (!root) return;
	//for (int i = 0; i < current->info; i++)   // обработка узла
		//printf("   ");
	if(k_elem< current->key) n++;
	if (current->LLink)preOrder(current->LLink,n, k_elem);
	if (current->RLink)preOrder(current->RLink,n, k_elem);
}



void CtreeNode::Insert(int n, int inf, CtreeNode* ptr)
{
	
	int flag = 1;
	CtreeNode* p, * q;
	p = ptr;
	while (flag)
	{
		if (n < p->key)
		{
			q = p->LLink;	 //a3
					
			if (q == NULL)
			{
				flag = 0;
				
				q = new CtreeNode(n, inf);
				
				p->LLink = q;
			}
			else p = q;
		}
		else if (n > p->key)
		{
			q = p->RLink;		 //a4
			
			if (q == NULL)
			{
				flag = 0;
				
				q = new CtreeNode(n, inf);
				
				p->RLink = q;
			}
			else p = q;
		}
		else if (n == p->key)
		{
			cout << "Такой элемент уже существует " << endl;
			flag = 0;//выход из цикла WHILE
		}
	}
}
void CtreeNode::PrintTree(CtreeNode* ptr, int n)
{
	if (ptr)
	{
		PrintTree(ptr->RLink, n + 3);
		for (int i = 1; i < n; i++)
			cout << " ";
		cout << ptr->key << endl;
		PrintTree(ptr->LLink, n + 3);
	}
}
void CtreeNode::DeleteTree(CtreeNode* ptr)
{
	if (ptr != NULL)
	{
		DeleteTree(ptr->LLink);
		DeleteTree(ptr->RLink);
		delete(ptr);
	}
}

void main()		//главная программа
{
	setlocale(LC_ALL, "Rus"); // для работи з кирилицей
	int k_elem;
	char rand_elem;
	cout << "  Сколько элементов добавлять?  ";
	cin >> k_elem;
	cout << "  Генерировать случайные элементы? (y/n) ";
	cin >> rand_elem;
	int num, inf;
	if (rand_elem == 'n')
	{
		cout << endl << "Индекс: ";	//вводить с клавиатуры
		cin >> num;
		cout << "Значение: ";
		cin >> inf;
	}
	else
	{
		num = rand() % 100 + 1;//случайные значения
		inf = rand() % 100 + 1;
	}
	CtreeNode* root = new CtreeNode(num, inf);	//указатель на корень
	for (int tr_i = 1; tr_i < k_elem; tr_i++)
	{
		if (rand_elem == 'n')
		{
			cout << endl << "Индекс: ";	//вводить с клавиатуры
			cin >> num;
			cout << "Значение: ";
			cin >> inf;
		}
		else
		{
			num = rand() % 100 + 1;//случайные значения
			inf = rand() % 100 + 1;
		}
		root->Insert(num, inf, root);
	}int n = 0;
	preOrder(root,n, k_elem);
	cout <<"\n\nK – кількість вузлiв, ключ яких бiльше заданого числа N : " << n << endl<<endl;

		root->Insert(n, 666, root);
	
	root->PrintTree(root, 5);
	root->DeleteTree(root);		//освобождение памяти
	int ram = _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;
}
