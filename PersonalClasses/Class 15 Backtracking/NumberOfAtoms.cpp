#include <bits/stdc++.h>
using namespace std;
int n, m, e[51][51], visited[51][51]={0}, ans = 0;
void bfs(int x, int y){
	if(e[x][y] == 0 || visited[x][y] == 1){
		return;
	}
	visited[x][y] = 1;
	if(y+1<=m){
		bfs(x, y+1);
	}
	if(x+1<=n){
		bfs(x+1, y);
	}
	if(y-1>0){
		bfs(x, y-1);
	}
	if(x-1>0){
		bfs(x-1, y);
	}
}

int main(){

	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> e[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(e[i][j] != 0 && visited[i][j] == 0){
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	

	return 0;
}


