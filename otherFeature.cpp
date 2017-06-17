#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"library.h"
#include"OtherDataModel.h"
#include"dormparase.h"
#include"borrowParase.h"
#define SIZE 40000
#define LIBRARYFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\library_trainANSI.txt"
#define DORMFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\dorm_train.txt"
#define BORROWFILE "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\borrow_train.txt"
#define OUTPUT "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\train\\OtherFeature1.txt"

using namespace std;
OtherDataModel* dataModel[SIZE];

int main(){
	ifstream libraryFile = ifstream(LIBRARYFILE, ios::in | ios::binary);
	ifstream dormFile = ifstream(DORMFILE, ios::in | ios::binary);
	ifstream borrowFile = ifstream(BORROWFILE, ios::in | ios::binary);
	ofstream of = ofstream(OUTPUT, ios::out | ios::binary);

	if (!libraryFile || !dormFile || !borrowFile || !of){
		cout << "file open fail" << endl;
		return 0;
	}

	Date startDate;
	Date globalDate;
	Date endDate;
	startDate.year = 2013;
	startDate.mon = 9;
	startDate.day = 1;
	startDate.weekday = 7;
	endDate.year = 2014;
	endDate.mon = 9;
	endDate.day = 1;

	string str;
	int cnt = 0;
	globalDate = startDate;

	//deal with library record
	while (getline(libraryFile, str)){
		Library lib(str);

		//deal with library record
		int id = lib.id;
		Date date = lib.date;

		//cout << id << " :";
		//cout << date.year << date.mon << date.day << endl;
		if (date.compare(globalDate) == -1){
			cnt++;
			continue;
		}
		while (!(globalDate == date)){
			globalDate = globalDate.nextDay();
		}
		date.weekday = globalDate.weekday;
		if (globalDate == endDate){
			break;
		}

		if (dataModel[id] == NULL){
			dataModel[id] = new OtherDataModel();
		}
		if (date.hour == -1){
			cout << "phrase hour fail id: " << id << endl;
			continue;
		}
		dataModel[id]->ioLibrary(date.mon, date.day, date.hour, date.weekday);

		cnt++;
		if ((cnt % 10000) == 0){
			cout << "deal with library" << cnt << endl;
		}
	}


	cnt = 0;
	globalDate = startDate;

	//deal with dorm record
	while (getline(dormFile, str)){
		Dorm dorm(str);
		
		int id = dorm.id;
		if (dorm.date.compare(globalDate) == -1){
			cnt++;
			continue;
		}
		while (!(globalDate == dorm.date)){
			globalDate = globalDate.nextDay();
		}
		dorm.date.weekday = globalDate.weekday;
		if (globalDate == endDate){
			break;
		}

		if (dataModel[id] == NULL){
			dataModel[id] = new OtherDataModel();
		};
		if (dorm.date.hour == -1){
			cout << "dormio hour parase fail id: " << id << endl;
			continue;
		}
		dataModel[id]->ioDorm(dorm.out, dorm.date.mon, dorm.date.hour, dorm.date.weekday);

		cnt++;
		if ((cnt % 10000) == 0){
			cout << "deal with dorm" << cnt << endl;
		}
	}

	cnt = 0;
	globalDate = startDate;

	//deal with borrow record
	while (getline(borrowFile, str)){
		Borrow bor(str);
		int id = bor.id;
		Date date = bor.date;

		if (date.compare(globalDate) == -1){
			cnt++;
			continue;
		}
		while (!(globalDate == date)){
			globalDate = globalDate.nextDay();
		}
		date.weekday = globalDate.weekday;
		if (globalDate == endDate){
			break;
		}

		if (dataModel[id] == NULL){
			dataModel[id] = new OtherDataModel();
		}
		dataModel[id]->borrowBook(date.mon);

		cnt++;
		if ((cnt % 10000) == 0){
			cout << "deal with borrow" << cnt << endl;
		}
	}

	//output to file
	for (int i = 0; i < SIZE; i++){
		if (dataModel[i] != NULL){
			of << i << ' ';
			//output library
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getLibraryDay(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getLibraryNight(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getLibraryWeekend(j) << ' ';
			}
			//output dorm
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getDormNight(j) << ' ';
			}
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getDormWeekend(j) << ' ';
			}
			//output borrow
			for (int j = 0; j < 12; j++){
				of << dataModel[i]->getBorrowNum(j) << ' ';
			}
			of << endl;
		}
	}

	//close io
	libraryFile.close();
	dormFile.close();
	borrowFile.close();
	of.close();
}