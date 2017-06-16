#include"dataModel.h"

const string DataModel::Good[12] = {
	"淋浴",
	"开水",
	"其他",
	"洗衣房",
	"文印中心",
	"教务处",
	"图书馆",
	"食堂",
	"校车",
	"超市",
	"校医院",
	"",
};

void DataModel::consume(int month, float money, float remain,string goodType,int weekDay){
	month = month - 1;
	if (month < 0 || money < 0 || remain < 0){
		return;
	}

	_data[month][0] += money;	//total consume
	_data[month][1]++;			//consume count
	_data[month][6] += remain;	//remain sum
	//max consume
	_data[month][2] = money  > _data[month][2] ? money : _data[month][2];
	//min consyme
	_data[month][3] = money  < _data[month][3] ? money : _data[month][3];
	//max remain
	_data[month][4] = remain > _data[month][4] ? remain : _data[month][4];
	//min remain
	_data[month][5] = remain < _data[month][5] ? remain : _data[month][5];

	int type = search(goodType);
	if (type != -1){
		this->goodType[month][type] += money;
		this->goodCnt[month][type]++;
	}
	if (weekDay <= 0 || weekDay > 7){
		return;
	}
	else{
		if (weekDay <= 5){
			weekCnt[month][0]++;
			weekConsume[month][0] += money;
		}
		else{
			weekCnt[month][1]++;
			weekConsume[month][1] += money;
		}
	}
}

void DataModel::outputData(ofstream& of){
	int cnt = 0;
	int ret[12][8];
	for (int i = 0; i < 12; i++){
		if (_data[i][0] == 0) cnt++;
	}
	if (cnt >= 4) return;

	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 4; j++){
			ret[i][j] = _data[i][j];
		}

		for (int j = 0; j < 2; j++){
			ret[i][5 + j] = _data[i][4 + j];
		}

		if (_data[i][1] != 0){
			ret[i][4] = _data[i][0] / _data[i][1];
			ret[i][7] = _data[i][6] / _data[i][1];
		}
		else{
			ret[i][4] = 0;
			ret[i][7] = 0;
			//consume min
			ret[i][3] = 0;
			//remain min
			ret[i][6] = 0;
		}
	}

	//output
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 8; j++){
			of << ret[i][j] << ' ';
		}
	}
	of << endl;
}