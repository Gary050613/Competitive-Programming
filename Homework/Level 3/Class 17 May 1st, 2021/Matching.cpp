#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7, MM = 21;
int n, a[MM][MM], dp[1<<MM]; 

int fun(int i, int mask){
	if(i >= n) return 1;
	if(dp[mask] != -1) return dp[mask];
	dp[mask] = 0;
	for(int j = 0;j<n;j++){
		if(a[i][j] && !(mask & 1<<j))
			dp[mask] = (dp[mask] + fun(i+1, mask | 1<<j)) % MOD; 
	}
	return dp[mask];
}

int main(){
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++) 
			cin >> a[i][j];
	cout << fun(0,0);
	return 0;
}


