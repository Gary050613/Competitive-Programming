#include <bits/stdc++.h>
using namespace std;
int n, m, visited[100001], g[100001][100001] = {0}, x=0;

void bfs(int i){
	x = max(x, i);
	visited[i] = 1;
	for(int j = 1;j<=n;j++){
		if(g[i][j] == 1 && visited[j] == 0){
			bfs(j);
		}
	}
	visited[i] = 0;
}

int main(){
	
	cin >> n >> m;
	while(m--){
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
	}
	for(int i = 1;i<=n;i++){
		bfs(i);
		cout << x << " ";
		x = 0;
	}
	
	return 0;
}


