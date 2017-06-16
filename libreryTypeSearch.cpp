//#include<fstream>
//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<sstream>
//#include<vector>
//#define INPUTFILE "C:\\Users\\root\\Desktop\\TensorFlow\\¾«×¼×ÊÖú\\train\\library_train.txt"
//
//using namespace std;
//
//int main(){
//	ifstream file(INPUTFILE, ios::in | ios::binary);
//	vector<string> doorType;
//
//	if (!file){
//		cout << "file open fail" << endl;
//		return 0;
//	}
//
//	string str;
//	string door;
//	int cnt = 0;
//
//	while (getline(file, str)){
//		size_t pos = 0;
//		size_t beg = 0;
//
//		pos = str.find(',', pos) + 1;	//skip id
//
//		beg = pos;
//		pos = str.find(',', pos);
//		door = str.substr(beg, pos - beg);
//
//		if (find(doorType.begin(), doorType.end(), door) == doorType.end()){
//			doorType.push_back(door);
//		}
//
//		cnt++;
//		if ((cnt % 3000) == 0){
//			cout << cnt << endl;
//			cout << "door " << doorType.size() << endl;
//		}
//
//		if (cnt == 200000) break;
//	}
//
//	file.close();
//
//	cout << "door type" << endl;
//	for (int i = 0; i < doorType.size(); i++){
//		cout << doorType[i] << ' ';
//	}
//	cout << endl;
//}