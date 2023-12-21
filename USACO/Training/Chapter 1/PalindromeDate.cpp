#include <bits/stdc++.h>
using namespace std;

int reverse(int a){
	int result = 0;
	while(a>0){
		result = result*10 + a%10;
		a/=10;
	}
	return result;
}

bool valid(int year, int month, int day){
	if(day > 31 || month > 12){
		return false;
	}
	if(month == 4 || month == 6 || month == 9 || month == 11){
		if(day > 30){
			return false;
		}
	}
	if(month == 2){
		if(day > 28){
			if(!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
				return false;
			}
		}
	}
	return true;
}

int main(){
	
	int start, end, ans = 0, cur;
	cin >> start >> end;
	int startyear = start/10000, endyear = end/10000;
	for(int i = startyear;i<=endyear;i++){
		cur = i*10000 + reverse(i);
		if(cur >= start && cur <= end && valid(i, (cur%10000)/100, cur%100)){
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}


