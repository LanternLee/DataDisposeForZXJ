#include"CardParase.h"
#include<iostream>
#include<fstream>
#include<string>
#define INPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\card_train10.txt"

using namespace std;

int main(){
	string s("1006,\"POS消费\",\"地点551\",\"淋浴\",\"2013/09/01 00:00 : 32\",\"0.5\",\"124.9\"");
	Card card(s);

	//output
	cout << "id: " << card.id<<endl;
	cout << "kind: " << card.kind << endl;
	cout << "money: " << card.money << endl;
	cout << "date: " << card._date->year << '/' << card._date->mon << '/' << card._date->day << endl;
	cout << "remain: " << card.remain << endl;
	cout << "consume: " << card.consume << endl;
	cout << "place: " << card.place << endl;
	cout << "good: " << card.good << endl;

	ifstream file = ifstream(INPUTFILE, ios::in | ios::binary);
	string str;
	int cnt = 0;

	if (!file){
		cout << "file open fail" << endl;
		return 0;
	}
	
	while (getline(file, str)){
		cout << str << endl;
		cnt++;
		if (cnt >= 20) break;
	}
}