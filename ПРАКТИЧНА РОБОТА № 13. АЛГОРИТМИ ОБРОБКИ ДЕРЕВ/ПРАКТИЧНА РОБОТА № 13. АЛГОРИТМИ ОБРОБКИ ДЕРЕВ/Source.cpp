#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class CtreeNode
{public:
	int key;				//����
	int info;			//�������������� ����
	CtreeNode* LLink, * RLink; //��������� �� ����� � ������ ����	

	CtreeNode() { key = 0; LLink = RLink = NULL; } //����������� �� ���������
	CtreeNode(int k, int info_c)	     //����������� � ��������
	{
		key = k;
		info = info_c;
		LLink = RLink = NULL;
	}
	~CtreeNode()			//����������
	{
	}
	//������� ���������� �������� � ������. ���������� ��������� �� ������
	void Insert(int number, int info, CtreeNode* ptr);
	void PrintTree(CtreeNode* ptr, int n);
	void DeleteTree(CtreeNode* ptr);
};
void preOrder(CtreeNode*& root,int& n, int k_elem)//������� ����������� ������.
{
	CtreeNode* current = root;
	if (!root) return;
	//for (int i = 0; i < current->info; i++)   // ��������� ����
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
			cout << "����� ������� ��� ���������� " << endl;
			flag = 0;//����� �� ����� WHILE
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

void main()		//������� ���������
{
	setlocale(LC_ALL, "Rus"); // ��� ������ � ���������
	int k_elem;
	char rand_elem;
	cout << "  ������� ��������� ���������?  ";
	cin >> k_elem;
	cout << "  ������������ ��������� ��������? (y/n) ";
	cin >> rand_elem;
	int num, inf;
	if (rand_elem == 'n')
	{
		cout << endl << "������: ";	//������� � ����������
		cin >> num;
		cout << "��������: ";
		cin >> inf;
	}
	else
	{
		num = rand() % 100 + 1;//��������� ��������
		inf = rand() % 100 + 1;
	}
	CtreeNode* root = new CtreeNode(num, inf);	//��������� �� ������
	for (int tr_i = 1; tr_i < k_elem; tr_i++)
	{
		if (rand_elem == 'n')
		{
			cout << endl << "������: ";	//������� � ����������
			cin >> num;
			cout << "��������: ";
			cin >> inf;
		}
		else
		{
			num = rand() % 100 + 1;//��������� ��������
			inf = rand() % 100 + 1;
		}
		root->Insert(num, inf, root);
	}int n = 0;
	preOrder(root,n, k_elem);
	cout <<"\n\nK � ������� ����i�, ���� ���� �i���� �������� ����� N : " << n << endl<<endl;

		root->Insert(n, 666, root);
	
	root->PrintTree(root, 5);
	root->DeleteTree(root);		//������������ ������
	int ram = _CrtDumpMemoryLeaks();

	std::cout << "\n������ �����i:" << ram << std::endl;
}
