#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int destx, desty, horsex, horsey;
int visited[16][16] = {0};
int hx[8] = {1,2,2,1,-1,-2,-2,-1},
	hy[8] = {-2,-1,1,2,2,1,-1,-2};

void dfs(int x, int y){
	if(x == destx && y == desty){
		ans++;
		return;
	}
	if(x+1<=destx && visited[x+1][y] == 0){
		visited[x+1][y] = 1;
		dfs(x+1,y);
		visited[x+1][y] = 0;
	}
	if(y+1<=desty && visited[x][y+1] == 0){
		visited[x][y+1] = 1;
		dfs(x,y+1);
		visited[x][y+1] = 0;
	}
}

int main(){
	
	cin >> destx >> desty >> horsex >> horsey;
	visited[horsex][horsey] = 1;
	for(int i = 0;i<8;i++){
		visited[horsex+hx[i]][horsey+hy[i]] = 1;
	}
	dfs(0,0);
	cout << ans;
	return 0;
}


