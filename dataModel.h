#ifndef DATAMOCEL
#define DATAMODEL
#include<fstream>

using namespace std;

class DataModel{
private:
	//������ ���Ѵ��� ������� ��С
	//���������� ��С ��
	float _data[12][7];

public:
	DataModel(){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 7; j++){
				_data[i][j] = 0;
			}
		}

		for (int i = 0; i < 12; i++){
			//init the min
			_data[i][3] = (float)10000;
			_data[i][5] = (float)10000;
		}
	}

	void consume(int month,float money,float remain);

	void outputData(ofstream& of);
};

#endif