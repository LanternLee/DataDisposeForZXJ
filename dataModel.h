#ifndef DATAMOCEL
#define DATAMODEL
#include<fstream>
#define BOUNDCHECK i>=12||i<0

using namespace std;

class DataModel{
private:
	//总消费 消费次数 单笔最大 最小
	//卡内余额最大 最小 和
	float _data[12][7];
	//12种消费 每种的总额
	float goodType[12][12];
	//12种消费 次数
	int goodCnt[12][12];
	//平时消费与周末消费 平时 周末
	float weekConsume[12][2];
	//平时与周末消费金额
	int weekCnt[12][2];


public:
	//12种消费
	static const string Good[12];

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
		memset(goodType, 0, sizeof(goodType));
		memset(goodCnt, 0, sizeof(goodCnt));
		memset(weekConsume, 0, sizeof(weekConsume));
		memset(weekCnt, 0, sizeof(weekCnt));
	}

	void consume(int month,float money,float remain,string goodType,int weekDay);

	void outputData(ofstream& of);

	bool isAvailable(){
		int cnt = 0;
		for (int i = 0; i < 12; i++){
			if (_data[i][0] == 0){
				cnt++;
			}
		}

		if (cnt >= 5){
			return false;
		}
		else
		{
			return true;
		}
	}

	int getTotalConsume(int i){
		if (BOUNDCHECK)	return 0;
		return _data[i][0];
	}
	int getConsumeTime(int i){
		if (BOUNDCHECK)	return 0;
		return _data[i][1];
	}
	int getMaxConsume(int i){
		if (BOUNDCHECK)	return 0;
		return _data[i][2];
	}
	int getMinConsume(int i){
		if (BOUNDCHECK)	return 0;
		if (_data[i][3] == 10000) return 0;
		return _data[i][3];
	}
	int getMaxRemain(int i){
		if (BOUNDCHECK)	return 0;
		return _data[i][4];
	}
	int getMinRemain(int i){
		if (BOUNDCHECK)	return 0;
		if (_data[i][5] == 10000) return 0;
		return _data[i][5];
	}
	int getAvgConsume(int i){
		if (getConsumeTime(i) == 0){
			return 0;
		}
		else{
			return getTotalConsume(i) / getConsumeTime(i);
		}
	}
	int getAvgRemain(int i){
		if (getConsumeTime(i) == 0){
			return 0;
		}
		else{
			return _data[i][6] / getConsumeTime(i);
		}
	}
	int getGootTime(int i,string good){
		if(BOUNDCHECK) return 0;
		int type = search(good);
		if (type == -1)	return 0;
		return goodCnt[i][type];
	}
	int getGoodConsume(int i, string good){
		if (BOUNDCHECK)	return 0;
		int type = search(good);
		if (type == -1)	return 0;
		return goodType[i][type];
	}
	int getWeekdayCnt(int i){
		if (BOUNDCHECK) return 0;
		return weekCnt[i][0];
	}
	int getWeekendCnt(int i){
		if (BOUNDCHECK) return 0;
		return weekCnt[i][1];
	}
	int getWeekdayConsume(int i){
		if (BOUNDCHECK)	return 0;
		return weekConsume[i][0];
	}
	int getWeekendConsume(int i){
		if (BOUNDCHECK)	return 0;
		return weekConsume[i][1];
	}
	int getWeekdayAvg(int i){
		if (getWeekdayCnt(i) == 0){
			return 0;
		}
		else{
			return getWeekdayConsume(i) / getWeekdayCnt(i);
		}
	}
	int getWeekendAvg(int i){
		if (getWeekendCnt(i) == 0){
			return 0;
		}
		else{
			return getWeekendConsume(i) / getWeekendCnt(i);
		}
	}
private:
	int search(string s){
		for (int i = 0; i < 12; i++){
			if (s.compare(Good[i]) == 0){
				return i;
			}
		}
		return -1;
	}
};

#endif