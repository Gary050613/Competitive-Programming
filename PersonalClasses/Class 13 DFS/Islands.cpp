#include <bits/stdc++.h>
using namespace std;

int g[101][101] = {0}, been[101], sum=0, n, m;

void dfs(int x){
	if(sum == n){
		return;
	}
	cout << x << " ";
	for(int i = 1;i<=n;i++){
		if(g[x][i] == 1 && been[i] == 0){
			been[i] = 1;
			sum++;
			dfs(i);
		}
	}
}

int main(){

	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	been[1] = 1;
	dfs(1);

	return 0;
}


