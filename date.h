#ifndef DATE_H
#define DATE_H
#include<string>
#include<stdio.h>
using namespace std;
int dayOfMon[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

class Date{
public:
	int year;
	int day;
	int mon;
	int weekday = 0;

	Date(){}

	Date(string s){
		char tmp[10];
		int p = 0;
		int i = 0;

		//parase year
		while (s[p+i] != '/'){
			tmp[i] = s[p + i];
			i++;
		}
		p += i + 1;
		tmp[i] = '\0';
		year = atoi(tmp);

		//parase mon
		i = 0;
		while (s[p + i] != '/'){
			tmp[i] = s[p + i];
			i++;
		}
		p += i + 1;
		tmp[i] = '\0';
		mon = atoi(tmp);

		//parase day
		i = 0;
		while (p + i < s.length()&&s[p + i] != ' '){
			tmp[i] = s[p + i];
			i++;
		}
		tmp[i] = '\0';
		day = atoi(tmp);
	}

	Date nextDay(){
		Date ret;
		ret.weekday = weekday + 1;
		ret.weekday > 7 ? 1 : ret.weekday;

		if (day == dayOfMon[mon]){
			ret.day = 1;

			if (mon == 12){
				ret.year = year + 1;
				ret.mon = 1;
			}
			else{
				ret.year = year;
				ret.mon = mon + 1;
			}
		}
		else{
			ret.year = year;
			ret.mon = mon;
			ret.day = day + 1;
		}

		return ret;
	}

};

#endif