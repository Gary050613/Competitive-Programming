#include <bits/stdc++.h>
using namespace std;

struct athlete{
	int size, number;
};

int main(){
	
	int j, a, ans=0;
	cin >> j >> a;
	int jersey[j+1];
	athlete ath[a+1];
	char ch;
	for(int i = 1;i<=j;i++){
		cin >> ch;
		switch(ch){
			case 'S':
				jersey[i] = 1;
				break;
			case 'M':
				jersey[i] = 2;
				break;
			case 'L':
				jersey[i] = 3;
				break;
		}
	}
	for(int i = 1;i<=a;i++){
		cin >> ch;
		switch(ch){
			case 'S':
				ath[i].size = 1;
				break;
			case 'M':
				ath[i].size = 2;
				break;
			case 'L':
				ath[i].size = 3;
				break;
		}
		cin >> ath[i].number;
		if(jersey[ath[i].number] == ath[i].size){
			ans++;
			jersey[ath[i].number] = 0;
		}
	}
	for(int i = 1;i<=a;i++){
		if(jersey[ath[i].number] - ath[i].size == 1){
			ans++;
			jersey[ath[i].number] = 0;
		}
	}
	for(int i = 1;i<=a;i++){
		if(jersey[ath[i].number] >= ath[i].size){
			ans++;
			jersey[ath[i].number] = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}


