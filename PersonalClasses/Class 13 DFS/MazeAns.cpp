#include<iostream>
using namespace std;
const int maxn = 30;
int dx[]  = {-1,0,1,0},dy[] = {0,1,0,-1};
int G[maxn][maxn],vis[maxn][maxn],A[maxn*maxn][3];
int n,m,sx,sy,ex,ey;
bool f = false;
bool inside(int x,int y){
	return x >=1 && x <=n && y>=1 && y <= m && G[x][y];
}
void dfs(int x,int y,int d){
	if(x == ex && y == ey){
		for(int i = 0; i < d-1; i++){
			cout << "(" << A[i][0]<<","<<A[i][1] << ")->";
		}
		cout << "("<<ex<<","<<ey<<")"<<endl;
		f = true;
		return;
	}
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],yy = y+dy[i];
		if(inside(xx,yy) && !vis[xx][yy]){
			vis[xx][yy] = 1;
			A[d][0] = xx;
			A[d][1] = yy;
			dfs(xx,yy,d+1);
			vis[xx][yy] = 0;
		}
	}
}
int main(){

	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		for(int j = 1; j<= m; j++){
			cin >> G[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	if(sx == ex && sy == ey){
		cout << -1;
		return 0;
	}
	A[0][0] = sx,A[0][1] = sy;
	vis[sx][sy] = 1;
	dfs(sx,sy,1);
	if(!f) cout << -1; return 0;

	return 0;
}
