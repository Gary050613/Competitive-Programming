#include <bits/stdc++.h>
using namespace std;
int g[101][101], n, m, ans = 0, Mtaken[101] = {0};

void dfs(int f, int m, int c){
	ans = max(ans, c);
	for(int i = 1;i<=n;i++){
		if(f+1 <= n && g[f+1][i] == 1 && !Mtaken[i]){
			Mtaken[i] = 1;
			dfs(f+1, i, c+1);
			Mtaken[i] = 0;
		}
	}
}

int main(){
	
	scanf("%d %d", &n, &m);
	int a, b;
	while(m--){
		cin >> a >> b;
		g[a][b] = 1;
	}
	for(int i = 1;i<=n;i++){
		if(g[1][i] == 1){
			Mtaken[i] = 1;
			dfs(1, i, 1);
			Mtaken[i] = 0;
		}
	}
	cout << ans << endl;
	
	return 0;
}


