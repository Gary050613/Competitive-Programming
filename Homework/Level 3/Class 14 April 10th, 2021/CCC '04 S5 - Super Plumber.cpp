#include <bits/stdc++.h>
using namespace std;
int m,n,ans,dp[101][101]={0}; char g[101][101];

void update(int x, int y, int prevx, int prevy){
	if(g[x][y] == '*')	dp[x][y] = -1;
	else if(g[x][y] != '.' && dp[prevx][prevy] != -1) dp[x][y] = max(dp[x][y], dp[prevx][prevy] + g[x][y] - '0');
	else dp[x][y] = max(dp[x][y], dp[prevx][prevy]);
}

void printdp(){
	for(int i = m;i>=1;i--){
		for(int j = 1;j<=n;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	while(cin >> m >> n && (m||n)){
		for(int i=m;i>=1;i--){
			for(int j=1;j<=n;j++){
				cin >> g[i][j];
			}
		}
//		printdp();
		memset(dp, 0, sizeof(dp));
		// bu[i][j] is already the best case to reach i, j from bottom up
		// td[i][j] is the best case to reach i, j from top down
		// dp[i][j] is the best case to reach i, j from all three directions
		// dp[i][j] = max(bu[i][j], dp[i+1][j]+g[i][j])
		for(int i=1;i<=n;i++){
			update(i, 1, i-1, 1);
		}
		for(int k = 2;k<=n;k++){
			for(int i = 1;i<=m;i++){
				update(i, k, i, k-1);
				for(int j = i+1;j<=m;j++){
					update(j, k, j-1, k);
				}
				for(int j = i-1;j>=1;j--){
					update(j, k, j+1, k);
				}
			}
		}
		printdp();
		cout << dp[m][n] << endl;
	}
	
	
	return 0;
}


