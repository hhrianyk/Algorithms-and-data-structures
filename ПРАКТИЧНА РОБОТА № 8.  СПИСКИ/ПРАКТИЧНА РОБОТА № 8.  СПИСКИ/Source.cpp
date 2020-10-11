//#include <stdio.h>
//#include<fstream>
//#include <malloc.h>
//#define NROW  15	// количество строк 10
//#define NCOL  15	// количество столбцов 
//
//struct TMatrix		// описание типа узла мультисписка
//{
//	int  val;		// значение элемента 
//	int row, col;	// номер строки, номер столбца 
//	TMatrix* frow, * fcol;// атрибуты св€зи в списках по строке и по столбцу 
//};
//void Read_File(TMatrix frow[], TMatrix fcol[])
//{
//	TMatrix* temp;
//	TMatrix* p;
//	FILE* file;
//	file = fopen("Text.txt", "r");
//	if (file == NULL)
//	{
//		printf("FiLE no Open");
//		return ;
//	}
//int po=0;
//while (!feof(file))
//{
//	po++;
//	temp = (TMatrix*)malloc(sizeof(TMatrix));
//	fscanf(file, "%i%i%i", &temp->row, &temp->col, &temp->val);
//	p = &frow[temp->row];
//	while (p->frow)			// перемещение до конца списка по столбцу
//		p = p->frow;		//переход к элементу в след. строке
//	temp->frow = p->frow;
//	p->frow = temp;
//	while (p->fcol)			// перемещение до конца списка по строке
//		p = p->fcol;		//переход к элементу в след. столбце
//	temp->fcol = p->fcol;
//	p->fcol = temp;
//	p = &fcol[temp->col];
//	
//}
//
//}
//
//void Init(TMatrix frow[], TMatrix fcol[])
//{
//	for (int i = 0; i < NROW; i++)
//	{
//		frow[i].fcol = 0;
//		frow[i].frow = 0;
//		frow[i].row = 0;
//	}
//	for (int i = 0; i < NCOL; i++)
//	{
//		fcol[i].fcol = 0;
//		fcol[i].frow = 0;
//		fcol[i].col = 0;
//	}
//}
//void Print_Matrix(TMatrix frow[])	//fr Ц массив указателей на списки строк
//{
//	TMatrix* p;	// p Ц вспомогательный указатель дл€ прохода по строке 
//	for (int i = 0; i < NROW; i++)	// просмотр строк 
//	{
//		p = frow[i].fcol; //установка указ. на первый элемент списка строки
//		while (p)	//список строки не пуст? 
//		{
//			printf(" [%2i,%3i ] = %2i\n", p->row, p->col, p->val); 			      p = p->fcol;	//переход к следующему элементу в строке
//		}
//	}
//}
//void Delete_Matrix(TMatrix frow[]) //освобождение пам€ти
//{
//	TMatrix* p, * pDel;	// p Ц вспомогательный указатель дл€ прохода по строке 
//	for (int i = 0; i < NROW; i++)	// просмотр строк 
//	{
//		p = frow[i].fcol;
//		while (p)			//список строки не пуст? 
//		{
//			pDel = p;
//			p = p->fcol;	//переход к следующему элементу в строке
//			delete pDel;
//		}
//	}
//}
//int main()
//{
//	TMatrix* pRow; 	//массив указателей на первые узлы списков строк
//	pRow = (TMatrix*)malloc(NROW * sizeof(TMatrix));
//	TMatrix* pCol; 	//массив указателей на первые узлы списков столбцов
//	pCol = (TMatrix*)malloc(NCOL * sizeof(TMatrix));
//	//Init(&pRow, &pCol);
//
//	for (int i = 0; i < NROW; i++)
//	{
//		pRow[i].fcol = 0;
//		pRow[i].frow = 0;
//		pRow[i].row = 0;
//	}
//	for (int i = 0; i < NCOL; i++)
//	{
//		pCol[i].fcol = 0;
//		pCol[i].frow = 0;
//		pCol[i].col = 0;
//	}
//	
//	Read_File(pRow, pCol);
//	Print_Matrix(pRow);
//	Delete_Matrix(pRow);
//	delete pRow;
//	delete pCol;
//}
