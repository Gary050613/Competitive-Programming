#include<bits/stdc++.h>
using namespace std;
struct note{
	int x;
	int y;
	int s;
}; 
struct note que[2051];
int ans = 0, a[51][51], visited[51][51] = {0};
int endx, endy;
int go[4][2] = {{0,1},
					  {1,0},
					  {0,-1},
					  {-1,0}
					 };

void bfs(int x, int y, int n){
	if(x == endx && y == endy){
		ans = min(ans, n);
		return;
	}
	for(int i = 0;i<4;i++){
		if(visited[x+go[i][1]][y+go[i][2]] == 0){
			visited[x+go[i][1]][y+go[i][2]] = 1;
			if(a[x+go[i][1]][y+go[i][2]] == 0){
				n++;
			}
		}
	}
	for(int i = 0;i<4;i++){
		bfs(x+go[i][1], y+go[i][2], n);
	}
	return;
}

int main(){

	int head,tail;
	int a[51][51] = {0};
	int book[51][51] = {0}; 
	
	int n,m,i,j,startx,starty;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= n; i++){
		for(j =1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	cin >> startx >> starty >> endx >> endy;
	bfs(startx, starty, 0);
	cout << ans;
	

	return 0;
}
