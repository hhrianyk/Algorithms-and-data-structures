#include "stdlib.h"
#include "iostream"

#define PB(value)(byte*)(value)
using namespace std;
typedef unsigned char byte;
typedef unsigned int qword;
#define N 4;
template <class T> void machine_code(const T& value)
{
	for (int i = 0; i < sizeof(T); i++)
	{
		byte Byte = *(PB(&value)+i );
		for (int j = 0; j < 8; j++)
			
			cout << int((Byte >> (7 - j)) );
		cout << " ";
	}
	cout << endl;
}
void main()
{
	setlocale(LC_CTYPE, "rus");
	short int val1 = 0 ;
	double b = 0;
		short int mas[4];
	cout << "¬вед≥ть число :",cin >> val1;
	cout << "short int:";
	machine_code(val1);
	cout << "¬вед≥ть число :";
	cin >> b;
	cout << "double:";
	machine_code(b);
	;
	for (int i=0;i<4;i++) cout << "¬вед≥ть число :",cin >> mas[i];
	cout << "short int масив :";
	machine_code(mas);

}
