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
	int hour = -1;

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

		//add hour prase
		size_t beg = s.find(' ', p);
		if (beg != -1){
			size_t end = s.find(':', beg);
			if (end != -1){
				hour = atoi(s.substr(beg, end - beg).c_str());
			}
		}
	}

	Date nextDay(){
		Date ret;
		ret.weekday = weekday + 1;
		ret.weekday = ret.weekday > 7 ? 1 : ret.weekday;

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

	bool operator==(Date d){
		return this->year == d.year && this->mon == d.mon && this->day == d.day;
	}

	Date operator=(Date d){
		this->year = d.year;
		this->mon = d.mon;
		this->day = d.day;
		this->weekday = d.weekday;
		this->hour = d.hour;

		return *this;
	}

	int compare(Date d){
		if (this->year != d.year){
			if (this->year > d.year){
				return 1;
			}
			else return -1;
		}
		else if (this->mon!=d.mon){
			if (this->mon > d.mon){
				return 1;

			}
			else return -1;
		}
		else if (this->day != d.day){
			if (this->day > d.day){
				return 1;
			}
			else return -1;
		}
		else return 0;
	}
};

#endif