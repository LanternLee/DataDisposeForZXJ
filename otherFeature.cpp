//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include"library.h"
//#define LIBRARYFILE "C:\\Users\\root\\Desktop\\TensorFlow\\¾«×¼×ÊÖú\\train\\library_trainANSI.txt"
//
//using namespace std;
//
//int main(){
//	ifstream file = ifstream(LIBRARYFILE, ios::in | ios::binary);
//	if (!file){
//		cout << "file open fail" << endl;
//		return 0;
//	}
//	vector<string> doorRecord;
//
//	string str;
//	int cnt = 0;
//	while (getline(file, str)){
//		Library lib(str);
//
//		if (find(doorRecord.begin(), doorRecord.end(), lib.door) == doorRecord.end()){
//			doorRecord.push_back(lib.door);
//		}
//		cnt++;
//		if ((cnt % 3000) == 0){
//			cout << cnt << endl;
//		}
//	}
//
//	for (int i = 0; i < doorRecord.size(); i++){
//		cout << doorRecord[i] << endl;
//	}
//}