//#include<fstream>
//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<sstream>
//#define SIZE 40000
//#define SUBSIDY  "C:\\Users\\root\\Desktop\\精准资助\\train\\subsidy_train.txt"
//#define CARD     "C:\\Users\\root\\Desktop\\精准资助\\output_train\\card"
//#define OUTFILE  "C:\\Users\\root\\Desktop\\精准资助\\output_train\\test_data.txt"
//
//using namespace std;
//int record[SIZE][13];
//bool visited[SIZE];
//int getSubStr(string s, char arr[], int beg);
//
//int main(){
//	ifstream subsidy(SUBSIDY, ios::in | ios::binary);
//	string s;
//	int id;
//	memset(visited, false, SIZE);
//
//	if (!subsidy){
//		cout << "subsidy open err" << endl;
//		return 0;
//	}
//
//	while (getline(subsidy, s)){
//		id = atoi(s.c_str());
//		size_t p = s.find(',') + 1;
//		int count = s.length() - p;
//		int money = atoi(s.substr(p, count).c_str());
//		switch (money){
//		case 0:
//			record[id][12] = 0;
//			break;
//		case 1000:
//			record[id][12] = 1;
//			break;
//		case 1500:
//			record[id][12] = 2;
//			break;
//		case 2000:
//			record[id][12] = 3;
//			break;
//		}
//	}
//	subsidy.close();
//
//	//input card mess
//	for (int a = 3,base = 0; a <= 4; a++){
//		stringstream ss;
//		ss << CARD << a << ".txt";
//		ifstream card;
//		card.open(ss.str(), ios::in | ios::binary);
//		if (!card){
//			cout << "card open err" << endl;
//			return 0;
//		}
//
//		char tmp[10];
//		while (getline(card, s)){
//			int p = 0;
//			p = getSubStr(s, tmp, p);
//			id = atoi(tmp);
//			visited[id] = true;
//			for (int i = 0; i < 6; i++){
//				p = getSubStr(s, tmp, p);
//				record[id][base+i] = atof(tmp);
//			}
//		}
//
//		base += 6;
//		card.close();
//	}
//
//	//output
//	fstream of(OUTFILE, ios::out);
//	for (int i = 0; i < SIZE; i++){
//		if (visited[i]){
//			int cnt = 0;
//			for (int j = 0; j < 12; j++){
//				if (record[i][j] == 0)    cnt++;
//			}
//			if (cnt >= 6) continue;
//
//			of << i << ' ';
//			for (int j = 0; j < 13; j++){
//				of << record[i][j] << ' ';
//			}
//			of << endl;
//		}
//	}
//
//	of.close();
//}
//
//int getSubStr(string s,char arr[], int beg){
//	int i = 0;
//	while (s[beg + i] != '\0'){
//		if (s[beg + i] == ' '){
//			arr[i] = '\0';
//			return beg + i + 1;
//		}
//		else{
//			arr[i] = s[beg + i];
//		}
//		i++;
//	}
//	arr[i] = '\0';
//	return i;
//}