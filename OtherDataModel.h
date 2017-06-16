#include<iostream>
#include<string>
#include<vector>

using namespace std;

class OtherDataModel{
private:
	//12 去图书馆天数 周末去图书馆天数 晚上去图书馆天数
	int libRecord[12][3];
	//12 借书数量
	int bookRecord[12];
	//12 晚上10点后进出宿舍次数 周末进出宿舍次数
	int dormRecord[12][2];

	int tmpMon;
	int tmpDay;
public:
	OtherDataModel(){
		memset(libRecord, 0, sizeof(libRecord));
		memset(bookRecord, 0, sizeof(bookRecord));
		memset(dormRecord, 0, sizeof(dormRecord));
		tmpDay = 0;
		tmpMon = 0;
	}

	void borrowBook(int mon){
		if (mon>12||mon<=0) return;
		bookRecord[mon-1]++;
	}

	void ioDorm(bool out, int mon, int hour,int weekday){
		if (mon>12||mon<=0||weekday<=0||weekday>7) return;
		if (hour >= 22) dormRecord[mon-1][0]++;
		if (weekday > 5) dormRecord[mon-1][1]++;
	}

	void ioLibrary(int mon,int day,int hour,int weekday){
		if (mon <= 0 || mon > 12 || day <= 0||weekday<=0||weekday>7||hour<0)	return;
		if (mon != tmpMon || day != tmpDay){
			tmpMon = mon;
			tmpDay = day;
			libRecord[mon][0]++;
			if (weekday > 5){
				libRecord[mon][1]++;
			}
			if (hour >= 19){
				libRecord[mon][2]++;
			}
		}
	}
};