#ifndef CARDPARASE_H
#define CARDPARASE_H
#include<string>
#include<stdio.h>
#include"date.h"

using namespace std;

class Card{
public:
	int id;
	Date* _date;
	bool kind;
	double money;
	double remain;
	string consume;
	string place;
	string good;

	Card(string s){
		string::size_type startP=0;
		string::size_type endP;
		int i;
		string tmp;
		char subS[10];

		//parase id
		id = atoi(s.c_str());

		//parase kind
		//skip id
		startP = s.find(',', startP);
		startP += 1;    //s[startP]==\"
		endP = s.find('\"', ++startP);
		tmp = s.substr(startP, endP - startP);
		if (tmp.compare("POS消费") == 0){
			kind = true;
		}
		else{
			kind == false;
		}
		consume = tmp;

		//parase date
		//startP = endP + 2;    //s[startP] is location
		//startP = s.find(',', startP) + 1;    //s[startP] is pattern
		//startP = s.find(',', startP) + 2;	 //s[startP] is date
		//place info
		startP = endP + 2;
		endP = s.find('\"', ++startP);
		tmp = s.substr(startP, endP - startP);
		place = tmp;

		//good type
		startP = endP + 2;
		endP = s.find('\"', ++startP);
		tmp = s.substr(startP, endP - startP);
		good = tmp;

		startP = endP + 2;
		endP = s.find(',', ++startP);
		tmp = s.substr(startP, endP - startP);
		_date = new Date(tmp);

		//parase money
		startP = endP + 2;    //s[startP] is consume money
		endP = s.find('\"', startP);
		tmp = s.substr(startP, endP - startP);
		money = atof(tmp.c_str());

		//remain
		startP = endP + 3;
		endP = s.find('\"', startP);
		tmp = s.substr(startP, endP - startP);
		remain = atof(tmp.c_str());
	}
};


#endif