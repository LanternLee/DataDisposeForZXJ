#include<string>
#include<stdio.h>
#include"date.h"

using namespace std;

class Dorm{
public:
	int id;
	bool out;
	Date date;

	Dorm(string s){
		id = atoi(s.c_str());

		//parase time
		size_t pos = s.find(",", 0) + 2;
		size_t end = s.find(",", pos);
		date = Date(s.substr(pos, end - pos));

		//parase io
		pos = end + 2;
		int io = atoi(s.substr(pos, 1).c_str());
		out == io == 1;
	}
};