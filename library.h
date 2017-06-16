#include<string>
#include<stdio.h>
#include<vector>
#include"date.h"

using namespace std;

class Library{
public:
	int id;
	string door;
	Date date;

	Library(string s){
		id = atoi(s.c_str());
		size_t pos = 0;
		size_t end = 0;
		pos = s.find('\"', pos) + 1;
		end = s.find('\"', pos);
		door = s.substr(pos, end - pos);

		pos = end + 3;
		end = s.find('\"', pos);
		date = Date(s.substr(pos, end - pos));
	}
};