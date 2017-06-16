//#include<fstream>
//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<string>
//#define POWER 12
//#define LABEL1 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\label1.txt"
//#define LABEL2 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\label2.txt"
//#define DATA1 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\cardParaseGraph1.txt"
//#define DATA2 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\cardParaseGraph2.txt"
//#define OUTD1 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\expendData1.txt"
//#define OUTD2 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\expendData2.txt"
//#define OUTL1 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\expendLabel1.txt"
//#define OUTL2 "C:\\Users\\root\\Desktop\\TensorFlow\\精准资助\\output_train\\expendLabel2.txt"
//
//using namespace std;
//const string label[2] = { LABEL1, LABEL2 };
//const string data[2] = { DATA1, DATA2 };
//const string outd[2] = { OUTD1, OUTD2 };
//const string outl[2] = { OUTL1, OUTL2 };
//
//int main(){
//	for (int i = 0; i < 1; i++){
//		ifstream label(label[i], ios::in | ios::binary);
//		ifstream data(data[i], ios::in | ios::binary);
//		ofstream oData(outd[i], ios::out);
//		ofstream oLabel(outl[i], ios::out);
//		string lineL, lineD;
//
//		if (!label || !data || !oData || !oLabel){
//			cout << "open file fail" << endl;
//			return 0;
//		}
//
//		while (getline(label, lineL) && getline(data, lineD)){
//			switch (atoi(lineL.c_str())){
//			case 0:
//				oData << lineD << endl;
//				oLabel << lineL << endl;
//				break;
//			case 1:
//				for (int i = 0; i < 12; i++){
//					oData << lineD << endl;
//					oLabel << lineL << endl;
//				}
//				break;
//			case 2:
//				for (int i = 0; i < 24; i++){
//					oData << lineD << endl;
//					oLabel << lineL << endl;
//				}
//				break;
//			case 3:
//				for (int i = 0; i < 36; i++){
//					oData << lineD << endl;
//					oLabel << lineL << endl;
//				}
//				break;
//			}
//		}
//
//		label.close();
//		data.close();
//		oData.close();
//		oLabel.close();
//	}
//}