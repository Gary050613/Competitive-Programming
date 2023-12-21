#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, visited[101][101] = {0};
char e[101][101];

void dfs(int x, int y){
	if(e[x][y] == '.'){
		return;
	} 
	for(int i = -1;i<=1;i++){
		for(int j = -1;j<=1;j++){
			int dx = x + i, dy = y + j;
			if(visited[dx][dy] == 0 && e[dx][dy] == 'W' /*&& dx > 0 && dy > 0 && dx <= m && dy <= n && (i != 0 && j != 0)*/){
				visited[dx][dy] = 1;
				dfs(dx, dy);
			}
		}
	}
}

void solve(){
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			if(visited[i][j] == 0 && e[i][j] == 'W'){
				dfs(i, j);
				ans++;
			}
		}
	}
}

int main(){

	cin >> m >> n;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			cin >> e[i][j];
		}
	}
	solve();
	cout << ans << endl;
	

	return 0;
}


