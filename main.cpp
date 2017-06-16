//#include<iostream>
//#include<string.h>
//#include<string>
//#include<cstdlib>
//#include<fstream>
//#define SIZE 40000
//#define BOUND 10000
//int Count = 0;
//
//float record[SIZE][12];
//bool visited[SIZE];
//
//using namespace std;
//
//int main(){
//	ifstream file("C:\\Users\\root\\Desktop\\final_test\\card_final_test2.txt",ios::in|ios::binary);
//	if (!file){
//		cout << "open failed";
//		return 0;
//	}
//	memset(visited, false, SIZE);
//	string s;
//	while (getline(file, s)){
//		//parse data
//		float money;
//		int year;
//		int mon;
//		int id = atoi(s.c_str());
//		int p = 0;
//		int q;
//
//		for (int c=0; p < s.length(); p++){
//			if (s[p] == ',') c++;
//			if (c == 4) break;
//		}
//		if (p != s.length()){
//			p += 2;
//			char tmp[5];
//			for (int i = 0; i < 4; i++){
//				tmp[i] = s[p + i];
//			}
//			tmp[4] = 0;
//			year = atoi(tmp);
//			if (year == 2014){
//				p += 5;
//			}
//			else continue;
//
//			for (int i = 0; i < 2; i++){
//				tmp[i] = s[p + i];
//			}
//			tmp[2] = 0;
//			mon = atoi(tmp);
//
//			for (int c=0; p < s.length(); p++){
//				if (s[p] == ',') c++;
//				if (c == 2)break;
//			}
//			if (p != s.length()){
//				p += 2;
//				q = p;
//				while (s[q] != '\"') q++;
//				money = atof(s.substr(p, q).c_str());
//
//				visited[id] = true;
//				record[id][mon-1] += money;
//				Count++;
////				if (Count == BOUND) break;
////				cout << id << ' ' << mon << ' ' << money << endl;
//			}
//		}
//
//	}
//	
//	//output
//	//int p = 0;
//	//int c = 0;
//	//while (1){
//	//	if (p == SIZE) break;
//	//	if (visited[p] == true){
//	//		for (int i = 0; i < 12; i++){
//	//			cout << record[p][i] << ' ';
//	//		}
//	//		cout << endl;
//	//		c++;
//	//	}
//
//	//	p++;
//	//}
//
//	ofstream of("C:\\Users\\root\\Desktop\\final_test\\output\\card2014.txt", ios::out);
//	for (int i = 0; i < SIZE; i++){
//		if (visited[i] == true){
//			of << i << ' ';
//			for (int j = 0; j < 12; j++){
//				of << record[i][j] << ' ';
//			}
//			of << endl;
//		}
//	}
//
//	of.close();
//	file.close();
//}