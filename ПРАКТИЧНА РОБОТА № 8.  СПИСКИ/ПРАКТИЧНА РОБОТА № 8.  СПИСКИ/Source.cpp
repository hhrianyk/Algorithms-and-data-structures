//#include <stdio.h>
//#include<fstream>
//#include <malloc.h>
//#define NROW  15	// ���������� ����� 10
//#define NCOL  15	// ���������� �������� 
//
//struct TMatrix		// �������� ���� ���� ������������
//{
//	int  val;		// �������� �������� 
//	int row, col;	// ����� ������, ����� ������� 
//	TMatrix* frow, * fcol;// �������� ����� � ������� �� ������ � �� ������� 
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
//	while (p->frow)			// ����������� �� ����� ������ �� �������
//		p = p->frow;		//������� � �������� � ����. ������
//	temp->frow = p->frow;
//	p->frow = temp;
//	while (p->fcol)			// ����������� �� ����� ������ �� ������
//		p = p->fcol;		//������� � �������� � ����. �������
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
//void Print_Matrix(TMatrix frow[])	//fr � ������ ���������� �� ������ �����
//{
//	TMatrix* p;	// p � ��������������� ��������� ��� ������� �� ������ 
//	for (int i = 0; i < NROW; i++)	// �������� ����� 
//	{
//		p = frow[i].fcol; //��������� ����. �� ������ ������� ������ ������
//		while (p)	//������ ������ �� ����? 
//		{
//			printf(" [%2i,%3i ] = %2i\n", p->row, p->col, p->val); 			      p = p->fcol;	//������� � ���������� �������� � ������
//		}
//	}
//}
//void Delete_Matrix(TMatrix frow[]) //������������ ������
//{
//	TMatrix* p, * pDel;	// p � ��������������� ��������� ��� ������� �� ������ 
//	for (int i = 0; i < NROW; i++)	// �������� ����� 
//	{
//		p = frow[i].fcol;
//		while (p)			//������ ������ �� ����? 
//		{
//			pDel = p;
//			p = p->fcol;	//������� � ���������� �������� � ������
//			delete pDel;
//		}
//	}
//}
//int main()
//{
//	TMatrix* pRow; 	//������ ���������� �� ������ ���� ������� �����
//	pRow = (TMatrix*)malloc(NROW * sizeof(TMatrix));
//	TMatrix* pCol; 	//������ ���������� �� ������ ���� ������� ��������
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
