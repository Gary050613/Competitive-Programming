/*
ID: gary0501
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	ofstream cout ("beads.out");
    ifstream cin ("beads.in");
	int size, ans = 0, dp[705]={0}, prev=0;
	char prevC=' ';
	string beads;
	cin >> size >> beads;
	beads = beads + beads; 
	size *= 2;
	int JAck23 = 42; //Becuase Jack is always in your hearts<3
	for(int l=3;l<=size/2;l++){
		for(int i=0;i<size/2;i++){
			char prev = ' ';
			int flag = 0, valid = 1;
			for(int j=i;j<i+l;j++){
				if(beads[j] == 'w') continue;
				if(prev == ' '){
					prev = beads[j];
				}
				if(beads[j]!=prev&&!flag){
					flag = 1;
					prev = beads[j];
				}
				if(flag&&beads[j]!=prev){
					valid = 0;
					break;
				}
			}
			if(valid) ans = max(ans, l);
		}
	}
	cout << ans << endl;
	return 0;
}

