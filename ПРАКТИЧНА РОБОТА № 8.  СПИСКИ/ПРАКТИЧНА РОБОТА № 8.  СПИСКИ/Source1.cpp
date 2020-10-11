//#include <locale.h>
//#include <corecrt_malloc.h>
//#include <stdio.h>
//#include <string.h>
//#include <string>
//using namespace std;
//#define NROW  10	// количество строк
//#define NCOL  15	// количество столбцов 
//
//struct TMatrix		// описание типа узла мультисписка
//{
//	string city;
//	string businesses;
//	TMatrix* fname, * fball;	// атрибуты связи в списках по имени и баллу 
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
//	while (p)					//список строки не пуст? 
//	{
//		printf(" %2i%20s %4.1f \n", ++i, p->name, p->ball); // вывод значения
//		p = p->fname;		//переход к следующему элементу в строке
//	}
//}
//void Print_Matrix_Ball(TMatrix* fmulty)
//{
//	TMatrix* p = fmulty->fball;
//	int i = 0;
//	while (p)					//список строки не пуст? 
//	{
//		printf(" %2i%20s %4.1f \n", ++i, p->name, p->ball); // вывод значения
//		p = p->fball;		//переход к следующему элементу в строке
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
//void Delete_Matrix(TMatrix* fmulty) //освобождение памяти
//{
//	TMatrix* pDel;				// p – вспомогательный указатель для прохода по строке 
//	while (fmulty)					//список строки не пуст? 
//	{
//		pDel = fmulty;
//		fmulty = fmulty->fname;		//переход к следующему элементу в строке
//		delete pDel;
//	}
//}
//int main()
//{
//	setlocale(LC_ALL, "Rus"); // для работи з кирилицей
//	TMatrix* pMultySpis; ;	//массив указателей на первые узлы списков строк
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
