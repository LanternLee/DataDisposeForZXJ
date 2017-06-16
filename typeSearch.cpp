//#include<fstream>
//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<sstream>
//#include<vector>
//#define SIZE 40000
//#define INPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\¾«×¼×ÊÖú\\train\\card_train.txt"
//
//using namespace std;
//
//int main(){
//	ifstream file(INPUTFILE, ios::in | ios::binary);
//	vector<string> consumeType;
//	vector<string> placeType;
//	vector<string> goodType;
//
//	if (!file){
//		cout << "file open fail" << endl;
//		return 0;
//	}
//
//	string str;
//	string consume;
//	string place;
//	string good;
//	int cnt = 0;
//
//	while (getline(file, str)){
//		size_t pos = 0;
//		size_t beg = 0;
//
//		pos = str.find(',', pos) + 1;	//skip id
//
//		beg = pos;
//		pos = str.find(",", pos);
//		consume = str.substr(beg, pos - beg);
//
//		beg = pos + 1;
//		pos = str.find(",", beg);
//		place = str.substr(beg, pos - beg);
//
//		beg = pos + 1;
//		pos = str.find(",", beg);
//		good = str.substr(beg, pos - beg);
//
//		if (find(consumeType.begin(), consumeType.end(), consume) == consumeType.end()){
//			consumeType.push_back(consume);
//		}
//
//		if (find(placeType.begin(), placeType.end(), place) == placeType.end()){
//			placeType.push_back(place);
//		}
//
//		if (find(goodType.begin(), goodType.end(), good) == goodType.end()){
//			goodType.push_back(good);
//		}
//
//		cnt++;
//		if ((cnt % 3000) == 0){
//			cout << cnt << endl;
//			cout << "consume " << consumeType.size() << " place " << placeType.size() << " good " << goodType.size() << endl;
//		}
//
//		if (cnt >= 200000) break;
//}
//
//	file.close();
//
//	cout << "consume type" << endl;
//	for (int i = 0; i < consumeType.size(); i++){
//		cout << consumeType[i] << ' ';
//	}
//	cout << endl;
//
//	cout << "place type" << endl;
//	for (int i = 0; i < placeType.size(); i++){
//		cout << placeType[i] << ' ';
//	}
//	cout << endl;
//
//	cout << "good type" << endl;
//	for (int i = 0; i < goodType.size(); i++){
//		cout << goodType[i] << ' ';
//	}
//	cout << endl;
//}