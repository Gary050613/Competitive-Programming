#include <bits/stdc++.h>
using namespace std;

int g[201][201]={0}, n, m, a, b, c, dest;
int visited[201] = {0}, ans = 99999;

void dfs(int i, int dis){
	if(dis >= ans){
		return;
	}
	if(i == dest){
		ans = min(ans, dis);
		return;
	}
	for(int j = 1;j<=n;j++){
		if(g[i][j] != 0 && visited[j] == 0){
			visited[j] = 1;
			dfs(j, dis+g[i][j]);
			visited[j] = 0;
		}
	}
}

int main(){
	
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> c;
		g[a][b] = c;
		g[b][a] = c;
	}
	int start;
	cin >> start >> dest;
	dfs(start, 0);
	cout << ans << endl;
	
	return 0;
}


