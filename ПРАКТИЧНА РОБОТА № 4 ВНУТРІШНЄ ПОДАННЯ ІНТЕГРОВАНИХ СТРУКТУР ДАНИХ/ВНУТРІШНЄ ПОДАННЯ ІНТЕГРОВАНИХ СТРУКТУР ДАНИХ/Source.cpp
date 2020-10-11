#include <iostream>
#include <conio.h>
#include <ctime>
#include "time.h"
#define kon  clock()//час

using namespace std;
void BYTE(unsigned char);

struct Tstruct1
{
	char s[15];	/*  bytes */
	short flip : 1;

	union
	{

		struct
		{
			char b[13] = "завантажений";
			bool dl = true;
		} prim2;

	} un;
};
struct Tstruct2
{
	char s[7];	/* 2 bytes */
	short flip : 1;

};

int main()
{
	setlocale(LC_ALL, "rus");
	Tstruct1 obj1 = { "суховантажник" };
	Tstruct2 obj2 = { "танкер" };

	unsigned char* p = (unsigned char*)&obj1;//запис данних в тип сhar	
	int t = kon;
	for (int byte = 0; byte < sizeof(Tstruct1); byte++, p++)
	{
		if (byte && !(byte % 8)) cout << endl;
		BYTE(*p);
	}
	cout << "\nТривалість роботи з варiативною: " << kon - t << " ms";
	cout << endl;
	cout << endl;

	p = (unsigned char*)&obj2;//запис данних в тип сhar
	t = kon;
	for (int byte = 0; byte < sizeof(Tstruct2); byte++, p++)
	{
		if (byte && !(byte % 8))cout << endl;
		BYTE(*p);
	}
	cout << "\nТривалість роботи без варiативної: " << kon - t << " ms";
	cout << endl;  cout << endl;
	return 0;
}
void BYTE(unsigned char A) // виведення вмісту байта
{
	for (int bit = 128; bit >= 1; bit >>= 1)
		cout << (A & bit ? "1" : "0");
	cout << " ";
}