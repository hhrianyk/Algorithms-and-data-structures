#define kon  clock()/60000//хвилини
#define kon2  (clock()/1000)%60//секунди
#define For_konsol  setlocale(LC_CTYPE, "ru") SetConsoleCP(1251) SetConsoleOutputCP(1251)



#include <ctime>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include <crtdbg.h>
#include <fstream>
#include <string>
#include "time.h"
#include <random> 
#include <iostream>
#include <ostream> 
#include <sstream> 
#include <iomanip>
#include <Windows.h>
#include <regex>
#include <cstddef>
#include <stddef.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <Windows.h>


#define EMPTY -1
#define __CRTDBG_MAP_ALLOC
int kol = 0;

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::out_of_range;
using std::vector;

//class without_fields;
struct ElHashTabl;
void menu();
void Init(ElHashTabl*&);
void Riad_FL(ElHashTabl*);
int Hash(int);
int Insert(int, int, int, string, string, ElHashTabl*);
int Search(int, ElHashTabl*);
void saveFL(ElHashTabl*);
void poshuk(ElHashTabl*);
void hoho(ElHashTabl*&, ElHashTabl*&);
void print(ElHashTabl*);
void add(ElHashTabl*&, ElHashTabl*&);
int delet(ElHashTabl* h, ElHashTabl*&);
void menu();
int run();