#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int m, n, k, a[1001], b[1001], w[1001], dp[22][80] = {0};
	memset(dp,127,sizeof(dp));
	dp[0][0] = 0;
	cin >> m >> n >> k;
	for(int i = 1;i<=k;i++){
		cin >> a[i] >> b[i] >> w[i];
	}
	for(int i = 1;i<=k;i++){
		for(int j = m;j>=0;j--){
			for(int l = n;l>=0;l--){
				int t1 = j + a[i], t2 = l + b[i];
				if(t1 > m) t1 = m;
				if(t2 > n) t2 = n;
				dp[t1][t2] = min(dp[t1][t2], dp[j][l] + w[i]);
			}
		}
	}
	cout << dp[m][n] << endl;
	
	return 0;
}

/*
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
*/
