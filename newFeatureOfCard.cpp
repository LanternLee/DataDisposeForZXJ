#include"CardParase.h"
#include"dataModel.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#define SIZE 40000
#define INPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\card_train10.txt"
#define OUTPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\cardFeature2.txt"

using namespace std;
vector<string> inputRecord;
bool isRepeated(string str);
DataModel* student[SIZE];

int main(){
	ifstream file = ifstream(INPUTFILE, ios::in | ios::binary);
	ofstream of = ofstream(OUTPUTFILE, ios::out | ios::binary);
	string str;
	int cnt = 0;
	Date globalDate;
	globalDate.year = 2013;
	globalDate.mon = 9;
	globalDate.day = 1;
	globalDate.weekday = 7;
	
	Date endDate;
	endDate.year = 2014;
	endDate.mon = 9;
	endDate.day = 1;

	if (!file||!of){
		cout << "file open fail" << endl;
		return 0;
	}


	while (getline(file, str)){
		if (isRepeated(str)){
			continue;
		}

		Card card(str);

		if (card.consume != "POS消费"){
			continue;
		}
		Date* date = card._date;
		while (!(globalDate==*date)){
			globalDate = globalDate.nextDay();
		}
		if (globalDate == endDate){
			break;
		}

		date->weekday = globalDate.weekday;

		if (student[card.id] == NULL){
			student[card.id] = new DataModel();
		}
		student[card.id]->consume(date->mon, card.money, card.remain, card.good, date->weekday);

		cnt++;
		if ((cnt % 3000) == 0){
			cout << cnt << endl;
		}
	}

	file.close();

	cnt = 0;

	for (int i = 0; i < SIZE; i++){
		if (student[i] != NULL){
			if (student[i]->isAvailable() == false){
				continue;
			}
			of << i << ' ';
			//total consume money
			DataModel* data = student[i];
			for (int j = 0; j < 12; j++){
				of << data->getTotalConsume(j) << ' ';
			}
			//consume time
			for (int j = 0; j < 12; j++){
				of << data->getConsumeTime(j) << ' ';
			}
			//average consume money
			for (int j = 0; j < 12; j++){
				of << data->getAvgConsume(j) << ' ';
			}
			//max consume
			for (int j = 0; j < 12; j++){
				of << data->getMaxConsume(j) << ' ';
			}
			//min consume
			for (int j = 0; j < 12; j++){
				of << data->getMinConsume(j) << ' ';
			}
			//max remain
			for (int j = 0; j < 12; j++){
				of << data->getMaxRemain(j) << ' ';
			}
			//min remain
			for (int j = 0; j < 12; j++){
				of << data->getMinRemain(j) << ' ';
			}
			//average remain
			for (int j = 0; j < 12; j++){
				of << data->getAvgRemain(j) << ' ';
			}
			//12 kinds of good
			for (int j = 0; j < 12; j++){
				for (int k = 0; k < 12; k++){
					of << data->getGootTime(j, data->Good[k]) << ' ';
				}
			}
			for (int j = 0; j < 12; j++){
				for (int k = 0; k < 12; k++){
					of << data->getGoodConsume(j, data->Good[k]) << ' ';
				}
			}
			//weekday consume
			for (int j = 0; j < 12; j++){
				of << data->getWeekdayConsume(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << data->getWeekdayCnt(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << data->getWeekdayAvg(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << data->getWeekendConsume(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << data->getWeekendCnt(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << data->getWeekendAvg(j) << ' ';
			}
			of << endl;
			cnt++;
		}
	}
	of.close();
}

bool isRepeated(string str){
	vector<string>::iterator it;
	it = find(inputRecord.begin(), inputRecord.end(), str);
	if (it == inputRecord.end()){
		if (inputRecord.size() > 10){
			inputRecord.erase(inputRecord.begin());
		}
		return false;;
	}
	else{
		inputRecord.erase(it);
		return true;
	}
}