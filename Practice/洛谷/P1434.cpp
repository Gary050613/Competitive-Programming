#include <bits/stdc++.h>
using namespace std;
int g[101][101], dp[101][101]={0}, v[101][101]={0};
int r, c, ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
	for(int i = 0;i<4;i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > r || ny > c){
			continue;
		}
		if(g[nx][ny]<g[x][y]){
			if(v[nx][ny]==0){
				dfs(nx, ny);
				v[nx][ny] = 1;
			}
			dp[x][y] = max(dp[x][y], dp[nx][ny]+1);
		}
	}
}

int main(){
	
	cin >> r >> c;
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			cin >> g[i][j];
			dp[i][j] = 1;
		}
	}
	for(int i = 1;i<=r;i++){
		for(int j = 1;j<=c;j++){
			dfs(i, j);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}


