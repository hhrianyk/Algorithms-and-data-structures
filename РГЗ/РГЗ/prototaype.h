#define kon  clock()/60000///< час у хвилини
#define kon2  (clock()/1000)%60///< час у секунди

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
#define _CRTDBG_MAP_ALLOC



using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
using std::ifstream;


	typedef /*short*/ int number;

    typedef /*short*/ int number_SR;
	typedef string words_SR;
	typedef bool boo_SR;







class RGZ;

class SR;
class Scientific_SR;
class Kolektsiyj_SR;

int Start_Menu(number);

int yes_and_no(number&,string);///Вибір
