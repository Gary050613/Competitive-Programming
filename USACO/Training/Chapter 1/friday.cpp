/*
ID: gary0501
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int leapmonths[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[7] = {0, 0, 0, 0, 0, 0, 0};

int getDay(int year, int month, int day){
	int days = 0;
	for(int i = 1900;i<year;i++){
		if(i%4==0 && i%100!=0 || i%400==0){
			days += 366;
		}else{
			days += 365;
		}
	}
	for(int i = 1;i<month;i++){
		if(year%4==0 && year%100!=0 || year%400==0){
			days += leapmonths[i];
		}else{
			days += months[i];
		}
	}
	days += day;
	return (days+1)%7;
}

int main(){

	ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int n;
	fin >> n;
	for(int i = 1900;i<1900+n;i++){
		for(int j = 1;j<=12;j++){
			ans[getDay(i,j,13)]++;
//			fout << i << " " << j << " " << 13 << " " << getDay(i,j,13) << endl;
		}
	}
	for(int i = 0;i<7;i++){
		if(i==6){
			fout << ans[i] << endl;
		}else{
			fout << ans[i] << " ";
		}
	}
	return 0;
}

