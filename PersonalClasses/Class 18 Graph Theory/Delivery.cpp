#include <bits/stdc++.h>
using namespace std;
int n, g[201][201], ans = 0, visited[201]={0};

void dfs(int i, int c){
	if(c >= n){
		ans++;
		return;
	}
	visited[i] = 1;
	for(int j = 1;j<=n;j++){
		if(g[i][j] == 1 && visited[j] == 0){
			dfs(j, c+1);
		}
	}
	visited[i] = 0;
}

int main(){
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> g[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		dfs(i, 1);
	}
	cout << ans << endl;
	
	return 0;
}


