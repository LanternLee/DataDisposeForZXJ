//#include<iostream>
//#include<fstream>
//#include<set>
//#include<string>
//#include<math.h>
//#include"CardParase.h"
//#include"dataModel.h"
//#define YEAR_L 2014
//#define MON_L  9
//#define YEAR_R 2015
//#define MON_R 8
//#define VERSION 1
//#define SIZE 40000
//#define INPUT_FILE  "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\card_train5.txt"
//#define OUTPUT_FILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\cardParaseGraph2.txt"
//#define OUTPUT_LABEL "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\label2.txt"
//#define SUBSIDY  "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\subsidy_train.txt"
//
//
//using namespace std;
//DataModel* record[SIZE];
//int subsidyRec[SIZE];
//bool isRepeated(set<string>& s, const string str);
//
//int main(){
//	ifstream file;
//	ifstream subFile;
//	file.open(INPUT_FILE, ios::in | ios::binary);
//	subFile.open(SUBSIDY, ios::in | ios::binary);
//	if (!file || !subFile){
//		cout << "open failed" << endl;
//		return 0;
//	}
//
//	string s;
//	set<string> cache;
//
//	//input card info
//	while (getline(file, s)){
//		if (isRepeated(cache, s)){
//			continue;
//		}
//
//		//parase card info
//		Card c(s);
//		int mon, year, id;
//		float money, remain;
//		if (c.kind == false) continue;
//
//		id = c.id;
//		mon = c._date->mon;
//		year = c._date->year;
//		money = c.money;
//		remain = c.remain;
//
//		//store card info
//		if ((year == YEAR_L&&mon >= MON_L) || (year == YEAR_R&&mon <= MON_R)){
//			if (record[id] == NULL){
//				record[id] = new DataModel();
//			}
//
//			if (year == YEAR_L){
//				record[id]->consume(mon - 9, money, remain);
//			}
//			else{	//year == YEAR_R
//				record[id]->consume(mon + 3, money, remain);
//			}
//		}
//		else if(year==YEAR_R&&mon>MON_R){
//			break;
//		}
//
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
//
//	file.close();
//	subFile.close();
//
//	ofstream ofData(OUTPUT_FILE, ios::out);
//	ofstream ofLabel(OUTPUT_LABEL, ios::out);
//	for (int i = 0; i < SIZE; i++){
//		if (record[i] == NULL) continue;
//		
//		record[i]->outputData(ofData);
//		ofLabel << subsidyRec[i] << endl;
//	}
//	ofData.close();
//	ofLabel.close();
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
