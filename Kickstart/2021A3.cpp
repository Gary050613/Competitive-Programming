#include <bits/stdc++.h>
using namespace std;
int g[301][301] = {0}, T, R, C, ans =0;
bool v[301][301] = {0};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int x, int y){
	if(v[x][y] == 1){
		return;
	}
	for(int i = 0;i<4;i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > R || ny > C){
			continue;
		}
		v[x][y] = 1;
		if(abs(g[nx][ny]-g[x][y])>1){
			if(g[nx][ny] > g[x][y]){
				ans += g[nx][ny] - g[x][y] -1;
				g[x][y] += g[nx][ny] - g[x][y] - 1;
			}else{
				ans += g[x][y] - g[nx][ny] - 1;
				g[nx][ny] += g[x][y] - g[nx][ny] - 1;
				v[nx][ny] = 0;
			}
		}
		dfs(nx, ny);
	}
}

int main(){
	int cnt=1;
	cin >> T;
	while(T--){
		memset(g, 0, sizeof(g));
		memset(v, 0, sizeof(v));
		ans=0;
		int startx, starty, m=0;
		cin >> R >> C;
		for(int i = 1;i<=R;i++){
			for(int j = 1;j<=C;j++){
				cin >> g[i][j];
			}
		}
		for(int i = 1;i<=R;i++){
			for(int j = 1;j<=C;j++){
				dfs(i, j);
			}
		}
//		for(int i = 1;i<=R;i++){
//			for(int j = 1;j<=C;j++){
//				cout << g[i][j] << " ";
//			}
//			cout << endl;
//		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
	return 0;
}


