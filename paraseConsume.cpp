//#include<iostream>
//#include<fstream>
//#include<set>
//#include<string>
//#include<math.h>
//#include"CardParase.h"
//#define YEAR_L 2013
//#define MON_L  9
//#define YEAR_R 2014
//#define MON_R 8
//#define VERSION 1
//#define SIZE 40000
//#define INPUT_FILE  "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\card_train.txt"
//#define OUTPUT_FILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\cardParase1.txt"
//#define SUBSIDY  "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\subsidy_train.txt"
//
//using namespace std;
//float monRec[SIZE][12];
//float consumeRec[SIZE][3];	//max min count
//float remainRec[SIZE][3];	//max min sum
//bool visited[SIZE];
//short subsidyRec[SIZE];
//bool isRepeated(set<string>& s, const string str);
//
//
//int main(){
//	//	ifstream file(INPUT_FILE, ios::in | ios::binary);
//	ifstream file;
//	ifstream subFile;
//	file.open(INPUT_FILE, ios::in | ios::binary);
//	subFile.open(SUBSIDY, ios::in | ios::binary);
//	if (!file||!subFile){
//		cout << "open failed" << endl;
//		return 0;
//	}
//	string s;
//	memset(visited, false, SIZE);
//	set<string> tmp;
//
//	//input card data
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
//		float money = c.money > 0 ? c.money : -c.money;
//		//if (year == YEAR_L && (mon >= MON_L&&mon <= MON_R)){
//		if ((year == YEAR_L&&mon >= MON_L) || (year == YEAR_R&&mon <= MON_R)){
//			visited[c.id] = true;
//			//consume monthly
//			if (year == YEAR_L){
//				monRec[c.id][mon - MON_L] += money;
//			}
//			else{
//				monRec[c.id][mon + 3] += money;
//			}
//			//consume every time
//			if (money > consumeRec[c.id][0]){
//				consumeRec[c.id][0] = money;
//			}
//			if (consumeRec[c.id][1] == 0 || money < consumeRec[c.id][1]){
//				consumeRec[c.id][1] = money;
//			}
//			consumeRec[c.id][2]++;
//			//remain
//			if (c.remain > remainRec[c.id][0]){
//				remainRec[c.id][0] = c.remain;
//			}
//			if (remainRec[c.id][1] == 0 || c.remain < remainRec[c.id][1]){
//				remainRec[c.id][1] = c.remain;
//			}
//			remainRec[c.id][2] += c.remain;
//
//		}
//		else if (year == YEAR_R&&mon > MON_R) break;
//	}
//
//	//input subsidy data
//	while (getline(subFile, s)){
//		int id, subsidy;
//		id = atoi(s.c_str());
//		size_t p = s.find(',') + 1;
//		int size = s.length() - p;
//		subsidy = atoi(s.substr(p, size).c_str());
//
//		switch (subsidy)
//		{
//		case 1000:
//			subsidyRec[id] = 1;
//			break;
//		case 1500:
//			subsidyRec[id] = 2;
//			break;
//		case 2000:
//			subsidyRec[id] = 3;
//			break;
//		case 0:
//		default:
//			break;
//		}
//	}
//	//output
//	ofstream of(OUTPUT_FILE, ios::out);
//
//	for (int i = 1; i < SIZE; i++){
//		float total = 0;
//		int cnt = 0;
//		if (visited[i] == true){
//			for (int j = 0; j < 12; j++){
//				if (monRec[i][j] == 0)cnt++;
//			}
//			if (cnt >= 6) continue;
//
//			of << i << ' ';
//			for (int j = 0; j < 12; j++){
//				of << floor(monRec[i][j]) << ' ';
//				total += monRec[i][j];
//			}
//			of << floor(total) << ' ';
//			for (int j = 0; j < 3; j++){
//				of << floor(consumeRec[i][j]) << ' ';
//			}
//			of << floor(total / consumeRec[i][2]) << ' ';
//			of << floor(remainRec[i][0])<<' ';
//			of << floor(remainRec[i][1]) << ' ';
//			of << floor(remainRec[i][2] / consumeRec[i][2]) << ' ';
//			of << subsidyRec[i] << ' ';
//			
//			of << endl;
//		}
//	}
//
//	of.close();
//	subFile.close();
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