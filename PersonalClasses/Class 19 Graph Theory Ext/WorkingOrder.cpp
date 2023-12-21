#include <bits/stdc++.h>
using namespace std;
int n, m, g[101][101] = {0}, t[101] = {0}, visited[101] = {0}, ans[101] = {0};

int main(){
	
	cin >> n;
	memset(g, 0, sizeof(g));
	int num, len, pre;
	for(int i = 1;i<=n;i++){
		cin >> num >> len;
		t[num] = len;
		while(cin >> pre && pre != 0){
			g[pre][num] = 1;
		}
	}
	ans[1] = t[1];
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
						ans[a] = max(ans[a], t[a]+ans[k]);
					}
				}
				visited[k] = 1;
				k = 0;
			}
		}
	}
	cout << ans[n] << endl;
	
	return 0;
}

/*
7
1 5 0
2 2 1 0
3 3 2 0
4 6 1 0
5 4 2 4 0
6 8 2 4 0
7 4 3 5 6 0
*/
