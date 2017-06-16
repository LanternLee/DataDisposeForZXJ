//#include<fstream>
//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<string>
//#define DATA1 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\expendLabel3.txt"
//#define DATA2 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\label2.txt"
//
//using namespace std;
//
//int main(){
//	ifstream in1;
//	ifstream in2;
//	int v[4];
//	int sum;
//	string line;
//	in1.open(DATA1, ios::in | ios::binary);
//	in2.open(DATA2, ios::in | ios::binary);
//
//	if (!in1 || !in2){
//		cout << "open file fail" << endl;
//		return 0;
//	}
//
//	cout << "train data:" << endl;
//	memset(v, 0, sizeof(v));
//	while (getline(in1, line)){
//		int tmp = atoi(line.c_str());
//		v[tmp]++;
//	}
//	
//	sum = v[0] + v[1] + v[2] + v[3];
//	for (int i = 0; i < 4; i++){
//		cout << "V[" << i << "] :" << v[i] << ' '
//			<< setprecision(2) << std::fixed<<(float)((1.0*v[i]) / (1.0*sum)) << endl;
//	}
//
//	in1.close();
//
//	cout << "test data:" << endl;
//	memset(v, 0, sizeof(v));
//	while (getline(in2, line)){
//		int tmp = atoi(line.c_str());
//		v[tmp]++;
//	}
//
//	sum = v[0] + v[1] + v[2] + v[3];
//	for (int i = 0; i < 4; i++){
//		cout << "V[" << i << "] :" << v[i] << ' '
//			<< setprecision(2) << std::fixed << (float)((1.0*v[i]) / (1.0*sum)) << endl;
//	}
//
//	in2.close();
//}