#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#define N 10
using namespace std;

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
};
unsigned char Height(node* p)
{
	return p ? p->height : 0;
}
int Bfactor(node* p)
{
	return Height(p->right) - Height(p->left);
}
void FixHeight(node* p)
{
	unsigned char hl = Height(p->left);
	unsigned char hr = Height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}
node* RotateRight(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}
node* RotateLeft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}
node* Balance(node* p) // балансировка узла p
{
	FixHeight(p);
	if (Bfactor(p) == 2)
	{
		if (Bfactor(p->right) < 0)
			p->right = RotateRight(p->right);
		return RotateLeft(p);
	}
	if (Bfactor(p) == -2)
	{
		if (Bfactor(p->left) > 0)
			p->left = RotateLeft(p->left);
		return RotateRight(p);
	}
	return p; // балансировка не нужна
}

node* Insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p)
	{
		p = new node;
		p->key = k; p->left = p->right = 0;
		p->height = 1;
		return p;
	}
	if (k < p->key)
		p->left = Insert(p->left, k);
	else
		p->right = Insert(p->right, k);
	return Balance(p);
}
node* FindMin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? FindMin(p->left) : p;
}
node* RemoveMin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = RemoveMin(p->left);
	return Balance(p);
}
node* Remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = Remove(p->left, k);
	else if (k > p->key)
		p->right = Remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = FindMin(r);
		min->right = RemoveMin(r);
		min->left = q;
		return Balance(min);
	}
	return Balance(p);
}

node* DeleteNode(node* p, int key)
{
	if (p == NULL)
		return p;

	if (key == p->key&& p->key!=11) {

		node* tmp;
		if (p->right == NULL)
			tmp = p->left;
		else {

			node* ptr = p->right;
			if (ptr->left == NULL) {
				ptr->left = p->left;
				tmp = ptr;
			}
			else {

				node* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = p->left;
				pmin->right = p->right;
				tmp = pmin;
			}
		}

		delete p;
		return tmp;
	}
	else if (key < p->key)
		p->left = DeleteNode(p->left, key);
	else
		p->right = DeleteNode(p->right, key);
	return p;

}

node* DeleteONe(node* p)
{
	node* pr=p;
	//node*pr= p->left;
	if (!p) return 0;
	if (p->right != NULL)
	{
		pr = p->right;
		int k = pr->key;
		p->right = Remove(p->right, k);
	}
	else if (p->left != NULL)
	{
		pr = p->left;
		int k = pr->key;
		p->left = Remove(p->left, k);

	}
	
}

void Print(node* tree, int level)
{
	int i;
	if (tree == NULL)  return;
	Print(tree->left, level - 2);
	for (i = 0; i < level; i++)
		printf(" ");
	printf("%d\n", tree->key);
	Print(tree->right, level - 2);
}
void Delete(node* tree)  //удаление дерева
{
	if (tree == NULL) return;
	Delete(tree->left);
	Delete(tree->right);
	free(tree);
}



int main()
{
	setlocale(LC_ALL, "rus");
	node* tree = NULL;
	for (int i = 0; i < N; i++)
	{
		int nom = rand() % N;
		tree = Insert(tree, nom);
	}  //построение дерева


	Print(tree, 30);
	printf("\n\n");
	
		int numer = 0;
	
		cout << "видалення вузлів за значенням:";
		cin >> numer;
		DeleteNode(tree, numer);
		Print(tree, 30);//30 відступ від лівого краю
	cout << "Скільки видалити вузлів :";
	cin >> numer;
	for (int i = 0; i < numer; i++)
	{
		DeleteONe(tree);
		//Print(tree, 30);//30 відступ від лівого краю
		//printf("\n\n");
	}
	Print(tree, 30);
	Delete(tree);

	int ram = _CrtDumpMemoryLeaks();

	std::cout << "\nВитоку памятi:" << ram << std::endl;

	return 0;
}