#include <queue>
#include <fstream>
#include <algorithm>
#include <climits>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#define chunk_count 3
#define chunk_size 10

int a[chunk_size];
#define K 1000 

int A[K], B[K], C[K];

struct MinHeapNode
{
	int element;
	int index;
};
struct Comparator
{
	bool operator() (const MinHeapNode lhs, const MinHeapNode rhs) const
	{
		return lhs.element > rhs.element;
	}
};

void create_chunks(std::string filename, std::string outfilename, int , int achunk_count);
void merge_chunks();
void generate_input_file(std::string filename, int length);


using namespace std;

//пираміда
void downHeap(int a[], int k, int n) // Процедура просеивания следующего элемента 
{ // До процедуры: a[k+1]...a[n]  - пирамида 
  // После:  a[k]...a[n]  - пирамида 
	int new_elem;
	int child;
	new_elem = a[k];
	while (k <= n / 2)  		// пока у a[k] есть дети 
	{
		child = 2 * k;
		// выбираем большего сына 
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		a[k] = a[child]; 	//  иначе переносим сына наверх 
		k = child;
	}
	a[k] = new_elem;
}
void HeapSort(int a[],int N)
{
	int i;
	// строим пирамиду
	for (i = N / 2 - 1; i >= 0; i--) downHeap(a, i, N - 1);
	// теперь a[0]...a[size-1] пирамида
	for (i = N - 1; i > 0; i--)
	{ // меняем первый с последним
		swap(a[i], a[0]);
		// восстанавливаем пирамидальность a[0]...a[i-1]
		downHeap(a, 0, i - 1);
		
	}
}

void merge_chunks(std::string filename, int achunk_count)
{
	{ char str[10];
	std::ifstream input_files[chunk_count];
	for (int i = 0; i < achunk_count; i++)//преобразовать в строку
	{
		_itoa_s(i, str, 10);
		input_files[i] = std::ifstream(str);
	}
	std::ofstream output_file(filename);
	MinHeapNode harr[chunk_count];
	std::priority_queue<MinHeapNode, std::vector<MinHeapNode>, Comparator> pq;
	int i;
	for (i = 0; i < achunk_count; i++)//х""ре в очередь 
	{
		if (!(input_files[i] >> harr[i].element))
			break;
		harr[i].index = i;
		pq.push(harr[i]);
	}
	
	for (int g = 0; g < chunk_count * chunk_size; g++)//Сортировка 
	{
		MinHeapNode root = pq.top();
		pq.pop();
		
		output_file << root.element << ' ';
		if (!(input_files[root.index] >> root.element))
			root.element = INT_MAX;//закінчилась очередь
		pq.push(root);
	}

	for (int i = 0; i < chunk_count; i++)
		input_files[i].close();
	output_file.close();
	 	}
}


/*/*слияниє в файл
void merge_chunks()
{
	FILE* f, * f1, * f2,* f3; // файловые переменные     
	int a, b; // для чтения из исходного файла 
	int x, y,z;
	int flag;
	x = y =z= 1;
	while (x > 0 && y > 0&&z>0)
	{
		flag = 1;
		x = 0;
		y = 0;
		f = fopen("output.txt", "r"); //"r" Режим открытия файла для чтения. 
		f1 = fopen("0", "r"); //"w" Режим создания пустого файла для записи. Если файл с таким именем уже существует его содержимое стирается, и файл рассматривается как новый пустой файл.
		f2 = fopen("1", "r");
		f3 = fopen("2", "r");
		fscanf(f, "%d", &a); // 
		if (!feof(f))
		{  // 
			fprintf(f1, "%d ", a);
		}
		if (!feof(f)) // пока не конец файла
			fscanf(f, "%d", &b);
		
		while (!feof(f))
		{
			if (b < a)
			{
				switch (flag)
				{
				case 1: {fprintf(f1, "' "); flag = 2; x++; break; }
				case 2: {fprintf(f2, "' "); flag = 1; y++; break; }
				case 3: {fprintf(f3, "' "); flag = 0; z++; break; }
				}
			}
			if (flag == 1) { fprintf(f1, "%d ", b); x++; }
			else if (flag == 2) { fprintf(f2, "%d ", b); y++; }
			else { fprintf(f3, "%d ", b); z++; }
			a = b;
			fscanf(f, "%d", &b);
		}
		if (y > 0 && flag == 2) { fprintf(f2, "'"); }
		if (x > 0 && flag == 1) { fprintf(f1, "'"); }
		if (z > 0 && flag == 0) { fprintf(f3, "'"); }
		fclose(f2);
		fclose(f1);
		fclose(f);
		fclose(f3);

		//слияние
		f = fopen("output.txt", "w");
		f1 = fopen("1", "r");
		f2 = fopen("2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a);
		if (!feof(f2)) fscanf(f2, "%d", &b);
		if (!feof(f3)) fscanf(f3, "%d", &b);
		bool X1, X2;
		//system ("pause");
		while (!feof(f1) && !feof(f2))
		{
			X1 = X2 = false;
			while (!X1 && !X2)
			{
				if (a <= b)
				{
					fprintf(f, "%d ", a);
					X1 = move(f1);
					fscanf(f1, "%d", &a);
				}
				else
				{
					fprintf(f, "%d ", b);
					X2 = move(f2);
					fscanf(f2, "%d", &b);
				}
			}
			while (!X1)
			{
				fprintf(f, "%d ", a);
				X1 = move(f1);
				fscanf(f1, "%d", &a);
			}
			while (!X2)
			{
				fprintf(f, "%d ", b);
				X2 = move(f2);
				fscanf(f2, "%d", &b);
			}
		}
		X1 = X2 = false;
		while (!X1 && !feof(f1))
		{
			fprintf(f, "%d ", a);
			X1 = move(f1);
			fscanf(f1, "%d", &a);
		}
		while (!X2 && !feof(f2))
		{
			fprintf(f, "%d ", b);
			X2 = move(f2);
			fscanf(f2, "%d", &b);
		}
		FILE* fO = fopen("output.txt", "w+");
		fscanf(fO, "%d", &f);

		fclose(f2);
		fclose(f1);
		fclose(f);
		fclose(fO);
		//system ("pause");
	}
}
*/
void create_chunks(std::string filename, std::string outfilename,  int achunk_count)
{
	std::ifstream input_file(filename);
	char str[10];
	std::ofstream output_files[chunk_count];
	for (int i = 0; i < achunk_count; ++i)
	{
		_itoa_s(i, str, 10);
		output_files[i] = std::ofstream(str);
	}
	int* arr = new int[chunk_size];
	int output_file_index = 0;
	bool is_finised = false;
	while (!is_finised)
	{
		int current_chunk_size = 0;
		while (current_chunk_size < chunk_size)
		{
			if (!(input_file >> arr[current_chunk_size]))
			{
				is_finised = true;
				break;
			}
			else
				++current_chunk_size;
		}
		HeapSort(arr, current_chunk_size);
		for (int i = 0; i < current_chunk_size; i++)
		{
			output_files[output_file_index] << arr[i] << ' ';
		}
		++output_file_index;
	}
	for (int i = 0; i < chunk_count; i++)
		output_files[i].close();
	input_file.close();
}
void generate_input_file(std::string filename, int length)
{
	std::ofstream input_file(filename);
	std::srand(time(NULL));
    for (int i = 0; i < length; i++)
		input_file << rand()%15 << ' ';
	input_file.close();
}

int main()
{
	std::string input_filename = "input.txt";
	std::string output_filename = "output.txt";
	generate_input_file(input_filename, chunk_count * chunk_size);
	create_chunks(input_filename, output_filename, chunk_count);
	merge_chunks((char*)output_filename.c_str(),  chunk_count);
	
	return 0;
}