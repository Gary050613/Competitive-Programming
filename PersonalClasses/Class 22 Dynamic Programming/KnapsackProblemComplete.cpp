#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m, w[31], c[31],dp[31][201];
	cin >> m >> n;
	for(int i = 1;i<=n;i++){
		cin >> w[i] >> c[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(j < w[i]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]]+c[i]);
			}
		}
	}
	printf("max=%d", dp[n][m]);
	
	return 0;
}


