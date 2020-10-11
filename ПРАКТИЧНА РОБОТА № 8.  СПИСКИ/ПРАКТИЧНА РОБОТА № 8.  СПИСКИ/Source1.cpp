//#include <locale.h>
//#include <corecrt_malloc.h>
//#include <stdio.h>
//#include <string.h>
//#include <string>
//using namespace std;
//#define NROW  10	// ���������� �����
//#define NCOL  15	// ���������� �������� 
//
//struct TMatrix		// �������� ���� ���� ������������
//{
//	string city;
//	string businesses;
//	TMatrix* fname, * fball;	// �������� ����� � ������� �� ����� � ����� 
//};
//void Read_File(TMatrix* fmulty)
//{
//	TMatrix* temp;
//	TMatrix* p = fmulty;
//	FILE* file;
//	file = fopen("Text.txt", "r");
//	while (!feof(file))
//	{
//		temp = (TMatrix*)malloc(sizeof(TMatrix));
//		fscanf(file, "%s%f", temp->name, &temp->ball);
//		temp->fname = p->fname;
//		temp->fball = p->fball;
//		p->fname = temp;
//		p->fball = temp;
//		p = temp;
//	}
//}
//void Print_Matrix_Name(TMatrix* fmulty)
//{
//	TMatrix* p = fmulty->fname;
//	int i = 1;
//	while (p)					//������ ������ �� ����? 
//	{
//		printf(" %2i%20s %4.1f \n", ++i, p->name, p->ball); // ����� ��������
//		p = p->fname;		//������� � ���������� �������� � ������
//	}
//}
//void Print_Matrix_Ball(TMatrix* fmulty)
//{
//	TMatrix* p = fmulty->fball;
//	int i = 0;
//	while (p)					//������ ������ �� ����? 
//	{
//		printf(" %2i%20s %4.1f \n", ++i, p->name, p->ball); // ����� ��������
//		p = p->fball;		//������� � ���������� �������� � ������
//	}
//}
//void Sort_Name(TMatrix* fmulty)
//{
//	TMatrix* p, * p1, * p2;
//	int priz;
//	do
//	{
//		p = fmulty;
//		p1 = p->fname;
//		p2 = p1->fname;
//		priz = 0;
//		while (p2)
//			if (strcmp(p1->name, p2->name) > 0)
//			{
//				p->fname = p2;
//				p1->fname = p2->fname;
//				p2->fname = p1;
//				priz = 1;
//				p = p2;
//				p2 = p1->fname;
//			}
//			else
//			{
//				p = p1;
//				p1 = p2;
//				p2 = p2->fname;
//			}
//	} while (priz);
//}
//void Sort_Ball(TMatrix* fmulty)
//{
//	TMatrix* p, * p1, * p2;
//	int priz;
//	do
//	{
//		p = fmulty;
//		p1 = p->fball;
//		p2 = p1->fball;
//		priz = 0;
//		while (p2)
//			if (p1->ball < p2->ball)
//			{
//				p->fball = p2;
//				p1->fball = p2->fball;
//				p2->fball = p1;
//				priz = 1;
//				p = p2;
//				p2 = p1->fball;
//			}
//			else
//			{
//				p = p1;
//				p1 = p2;
//				p2 = p2->fball;
//			}
//	} while (priz);
//}
//void Delete_Matrix(TMatrix* fmulty) //������������ ������
//{
//	TMatrix* pDel;				// p � ��������������� ��������� ��� ������� �� ������ 
//	while (fmulty)					//������ ������ �� ����? 
//	{
//		pDel = fmulty;
//		fmulty = fmulty->fname;		//������� � ���������� �������� � ������
//		delete pDel;
//	}
//}
//int main()
//{
//	setlocale(LC_ALL, "Rus"); // ��� ������ � ���������
//	TMatrix* pMultySpis; ;	//������ ���������� �� ������ ���� ������� �����
//	pMultySpis = (TMatrix*)malloc(sizeof(TMatrix));
//	pMultySpis->fball = 0;
//	pMultySpis->fname = 0;
//	Read_File(pMultySpis);
//	Sort_Name(pMultySpis);
//	Sort_Ball(pMultySpis);
//	Print_Matrix_Name(pMultySpis);
//	printf("\n");
//	Print_Matrix_Ball(pMultySpis);
//	Delete_Matrix(pMultySpis);
//}
