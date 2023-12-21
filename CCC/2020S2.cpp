#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[1001][1001] = {0}, visited[1001][1001]={0};
bool ans = 0;

void dfs(int x, int y){
	if(ans){
		return;
	}
	if(x == 1 && y == 1){
		ans = 1;
		return;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(g[i][j] == x*y && !visited[i][j]){
				visited[i][j] = 1;
				dfs(i, j);
			}
		}
	}
}

void dfs2(int x, int y){
	if(ans) return;
	if(x == n && y == m){
		ans = 1;
		return;
	}
	for(int i = 1;i<=sqrt(g[x][y]);i++){
		if(g[x][y] % i == 0){
			int j = g[x][y] / i;
			if(i <= n && j <= m){
				if(!visited[i][j]){
					visited[i][j] = 1;
					dfs2(i, j);
				}
			}
			if(i <= m && j <= n){
				if(!visited[j][i]){
					visited[j][i] = 1;
					dfs2(j, i);
				}
			}
		}
	}
}

int main(){
	
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> g[i][j];
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++){
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
//	dfs(n, m);
	dfs2(1, 1);
	if(ans){
		cout << "yes\n";
	}else{
		cout << "no\n";
	}
	
	return 0;
}


