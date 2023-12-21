#include<iostream>
using namespace std;
const int maxn = 101;
//?????? 
char field[maxn][maxn] ;
int n,m;
//??for ??,????8???,????????,????? 
void dfs(int x, int y){
	field[x][y] = '.';
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1;dy++){
			int nx = x + dx,ny = y + dy;
			if(0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W'){
				dfs(nx,ny);
			}
		}
	} 
}
//???????,???????DFS
//??????,res(????) + 1 
void solve(){
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			if(field[i][j] == 'W'){
				dfs(i,j);
				res++;
			}
		}
	}
	cout << res << endl;
}
int main(){

	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> field[i][j];
		}
	}
	solve();
	return 0;
}
