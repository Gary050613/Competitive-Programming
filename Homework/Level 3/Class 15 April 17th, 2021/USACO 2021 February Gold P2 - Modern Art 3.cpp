#include <bits/stdc++.h>
using namespace std;
const int MM = 301;
int n, dp[MM][MM], color[MM];
int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> color[i];
		dp[i][i] = 1;
	}
	for(int len = 1;len<=n;len++){
		for(int L = 1;L+len<=n;L++){
			int R = L + len;
			dp[L][R] = INT_MAX;
			for(int m = L; m<R;m++){
				dp[L][R] = min(dp[L][R], dp[L][m]+dp[m+1][R]);
			}
			if(color[L] == color[R]){
				dp[L][R] = min(dp[L+1][R], dp[L][R-1]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}


