#include <bits/stdc++.h>
using namespace std;
int n, m, g[101][101] = {0}, ans[101] = {0}, visited[101] = {0};

int main(){
	
	cin >> n >> m;
	memset(g, 0, sizeof(g));
	int a, b;
	while(m--){
		cin >> a >> b;
		g[a][b] = 1;
	}
	ans[1] = 1;
	for(int k = 1;k<=n;k++){
		if(visited[k]){
			continue;
		}
		for(int j = 1;j<=n;j++){
			if(g[j][k] == 1){
				j = n;
				continue;
			}
			if(j == n){
				for(int a = 1;a<=n;a++){
					if(g[k][a] == 1){
						g[k][a] = 0;
						ans[a] += ans[k];
					}
				}
				visited[k] = 1;
				k = 0;
			}
		}
	}
	cout << ans[n]%80112002;
	
	return 0;
}

/*
5 7
1 2
1 3
2 3
3 5
2 5
4 5
3 4
*/


