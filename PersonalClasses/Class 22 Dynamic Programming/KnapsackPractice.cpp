#include <bits/stdc++.h>
using namespace std;
int dp[6001];
int main(){
	
	int n, m, v[501], w[501], s[501];
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> v[i] >> w[i] >> s[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = m;j>=0;j--){
			for(int k = 0;k<=s[i];k++){
				if(k*v[i]<=j){
					dp[j] = max(dp[j], dp[j-v[i]*k]+k*w[i]);
				}
			}
		}
	}
	cout << dp[m];
	
	return 0;
}

/*
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
*/
