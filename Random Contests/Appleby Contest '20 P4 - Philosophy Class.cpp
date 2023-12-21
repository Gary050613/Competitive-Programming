#include <bits/stdc++.h>
using namespace std;
int g[3001][3001] = {0}, next[3001]={0};
int main(){
	
	int N, M, a, b, ans = 3001, ostart=0;
	memset(g, 0, sizeof(g));
	scanf("%d %d", &N, &M);
	while(M--){
		scanf("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	for(int k = 1;k<=N;k++){
		for(int i = 1;i<=N;i++){
			for(int j = 1;j<=N;j++){
				if(g[i][j] > g[i][k] + g[k][j] || g[i][j] == 0){
					g[i][j] = g[i][k] + g[k][j];
					next[i] = k;
					next[k] = j;
				}
			}
		}
	}
	for(int i = 1;i<=N;i++){
		int counter = 1;
		if(next[i] == 0){
			continue;
		}
		int cur = i, start = i;
		while(next[cur] != 0 && counter <= N){
			counter++;
			start = min(start, next[cur]);
			if(next[cur] == i){
				if(ans > counter){
					ans = counter;
					ostart = start;
				}
				break;
			}
			cur = next[cur];
		}
	}
	if(ostart == 0){
		printf("-1");
	}else{
		printf("%d\n", ans);
		int cur = ostart;
		while(next[cur] != ostart){
			printf("%d ", cur);
			cur = next[cur];
		}
		printf("%d", next[cur]);
	}
	
	return 0;
}


