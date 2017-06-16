//#include<iostream>
//#include<fstream>
//#include<set>
//#include<string>
//#include"CardParase.h"
//#define YEAR_L 2015
//#define MON_L  3
//#define YEAR_R 2015
//#define MON_R 8
//#define VERSION 1
//#define SIZE 40000
//#define INPUT_FILE  "C:\\Users\\root\\Desktop\\精准资助\\train\\card_train6.txt"
//#define OUTPUT_FILE "C:\\Users\\root\\Desktop\\精准资助\\output_train\\card4.txt"
//
//using namespace std;
//int data[SIZE][6];
//bool visited[SIZE];
//bool isRepeated(set<string>& s, const string str);
//
//
//int main(){
////	ifstream file(INPUT_FILE, ios::in | ios::binary);
//	ifstream file;
//	file.imbue(locale("chs"));
//	file.open(INPUT_FILE, ios::in | ios::binary);
//	if (!file){
//		cout << "open failed" << endl;
//		return 0;
//	}
//	string s;
//	memset(visited, false, SIZE);
//	set<string> tmp;
//
//	//input
//	while (getline(file, s)){
//		if (isRepeated(tmp, s)){
//			continue;
//		}
//
//		//new data
//		Card c(s);
//		if (c.kind == false) continue;	//not consume
//
//		int year = c._date->year;
//		int mon = c._date->mon;
//		if (year == YEAR_L&&(mon >= MON_L&&mon<=MON_R)){
//		//if ((year == YEAR_L&&mon >= MON_L) || (year==YEAR_R&&mon<=MON_R)){
//		//	visited[c.id] = true;
//		//	if (year == YEAR_L){
//		//		data[c.id][mon - MON_L] += c.money;
//		//	}
//		//	else{
//		//		data[c.id][mon + 3] = c.money;
//		//	}
//			visited[c.id] = true;
//			data[c.id][mon - MON_L] += c.money;
//		}
//		else if (year == YEAR_R&&mon > MON_R) break;
//	}
//
//	//output
//	ofstream of(OUTPUT_FILE, ios::out);
//
//	for (int i = 1; i < SIZE; i++){
//		if (visited[i] == true){
//			of << i << ' ';
//			for (int j = 0; j < 6; j++){
//				of << data[i][j] << ' ';
//			}
//			of << endl;
//		}
//	}
//
//	of.close();
//	file.close();
//}
//
//bool isRepeated(set<string>& s, const string str){
//	set<string>::iterator it;
//	bool ret = false;
//	for (it = s.begin(); it != s.end(); it++){
//		if (it->compare(str) == 0){
//			s.erase(it);
//			ret = true;
//			break;
//		}
//	}
//	if (ret == false){
//		s.insert(str);
//		if (s.size() > 10){
//			s.erase(s.begin());
//		}
//	}
//
//	return ret;
//}