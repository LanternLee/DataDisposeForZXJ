//#include"CardParase.h"
//#include"dataModel.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#define SIZE 40000
//#define INPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\card_train10.txt"
//#define OUTPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\testOutput.txt"
//
//using namespace std;
//vector<string> inputRecord;
//bool isRepeated(string str);
//DataModel* student[SIZE];
//
//int main(){
//	ifstream file = ifstream(INPUTFILE, ios::in | ios::binary);
//	string str;
//	int cnt = 0;
//	Date globalDate;
//	globalDate.year = 2013;
//	globalDate.mon = 9;
//	globalDate.day = 1;
//	globalDate.weekday = 7;
//
//	if (!file){
//		cout << "file open fail" << endl;
//		return 0;
//	}
//	
//
//	while (getline(file, str)){
//		if (isRepeated(str)){
//			continue;
//		}
//
//		Card card(str);
//
//		if (card.consume != "POS消费"){
//			continue;
//		}
//		Date* date = card._date;
//		while (globalDate.year != date->year || globalDate.mon != date->mon || globalDate.day != date->day){
//			globalDate = globalDate.nextDay();
//		}
//		date->weekday = globalDate.weekday;
//		
//		if (student[card.id] == NULL){
//			student[card.id] = new DataModel();
//		}
//		student[card.id]->consume(date->mon, card.money, card.remain, card.good, date->weekday);
//
//		cnt++;
//		if ((cnt % 3000) == 0){
//			cout << cnt << endl;
//		}
//		if (cnt == 200000) break;
//	}
//
//	file.close();
//
//	cnt = 0;
//	ofstream of = ofstream(OUTPUTFILE, ios::out | ios::binary);
//	for (int i = 0; i < SIZE; i++){
//		if (student[i] != NULL){
//			of << i << ' ';
//			DataModel* data = student[i];
//			for (int j = 0; j < 12; j++){
//				of << data->getAvgConsume(j) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getAvgRemain(j) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getConsumeTime(j) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getGoodConsume(j,data->Good[7]) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getGootTime(j,data->Good[7]) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getMaxConsume(j) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getWeekendCnt(j) << ' ';
//			}
//			for (int j = 0; j < 12; j++){
//				of << data->getWeekendConsume(j) << ' ';
//			}
//			of << endl;
//			cnt++;
//		}
//
//		if (cnt >= 100) break;
//	}
//	of.close();
//}
//
//bool isRepeated(string str){
//	vector<string>::iterator it;
//	it = find(inputRecord.begin(), inputRecord.end(), str);
//	if (it == inputRecord.end()){
//		if (inputRecord.size() > 10){
//			inputRecord.erase(inputRecord.begin());
//		}
//		return false;;
//	}
//	else{
//		inputRecord.erase(it);
//		return true;
//	}
//}