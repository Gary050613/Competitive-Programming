#include <bits/stdc++.h>
using namespace std;

int n, pOfQrow[11]={0}, pOfQDR[22]={0}, pOfQDL[22]={0}, ans = 0; 

void bt(int col){
	if(col == n+1){
		ans++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(pOfQrow[col] != i && pOfQDR[col-i+10] != 1 && pOfQDL[col+i] != 1){
			pOfQrow[col] = i;
			pOfQDR[col-i+10] = pOfQDL[col+i] = 1;
			bt(col+1);
			pOfQrow[col] = 0;
			pOfQDR[col-i+10] = pOfQDL[col+i] = 0;
		}
	}
}

int main(){
	
	cin >> n;
	bt(1);
	cout << ans;
	
	return 0;
}


