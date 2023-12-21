#include <bits/stdc++.h>
using namespace std;
int n, m, a, dx, dy, ans;
char f[21][21];
bool v[21][21];

void dfs(int x, int y){
	if(f[x][y] == '#' || x <= 0 || y <= 0 || x > n || y > m || v[x][y]){
		return;
	}
	ans++;
	v[x][y] = 1;
	dfs(x, y+1);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x-1, y);
}

int main(){
	
	while(cin >> m >> n, (m||n)){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				cin >> f[i][j];
				if(f[i][j]=='@'){
					dx = i, dy = j;
				}
			}
		}
		dfs(dx,dy);
		cout << ans << endl;
		ans=0;
	}
	
	return 0;
}


