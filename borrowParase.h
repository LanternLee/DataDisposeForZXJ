#include<string>
#include<stdio.h>
#include"date.h"

using namespace std;

class Borrow{
public:
	int id;
	Date date;

	Borrow(string s){
		id = atoi(s.c_str());

		//parase date
		size_t pos = s.find(",", 0) + 2;
		size_t end = s.find(",", pos);
		date = Date(s.substr(pos, end - pos));
	}
};