#include <bits/stdc++.h>
using namespace std;
int g[101][101], ans = 0, visited[101] = {0}, minn[101];
int main(){
	
	int n, e;
	cin >> n >> e;
	int a, b, w;
	while(e--){
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = w;
	}
	memset(minn, 999999, sizeof(minn));
	minn[1] = 0;
	for(int i = 1;i<=n;i++){
		visited[i] = 1;
		for(int j = 1;j<=n;j++){
			if(g[i][j] != 0 && !visited[j]){
				minn[j] = min(minn[j], g[i][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		ans += minn[i];
	}
	cout << ans << endl;
	
	return 0;
}

/*
5 8
1 2 2
2 5 9
5 4 7
4 1 10
1 3 12
4 3 6
5 3 3
2 3 8
*/


