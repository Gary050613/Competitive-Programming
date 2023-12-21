#include <bits/stdc++.h>
using namespace std;
int x1, y1, x2, y2, ans = 999999, visited[101][101] = {0};
int go[12][2] = {{-1,-2},{-2,-2},{-2,-1},{2,-1},{2,-2},{1,-1},{-2,1},{-2,2},{-1,2},{1,2},{2,2},{2,1}};

void bfs(int x, int y, int s){
	if(x == 1 && y == 1){
		ans = min(ans, s);
		return;
	}
	visited[x][y] = 1;
	for(int i = 0;i<12;i++){
		int xx = x + go[i][0], yy = y + go[i][1];
		if(xx > 0 && yy > 0 && xx <=100 && yy <= 100 && visited[xx][yy] == 0){
			bfs(xx, yy, s+1);
		}
	}
}

int main(){

	cin >> x1 >> y1 >> x2 >> y2;
	bfs(x1, y1, 0);
	cout << ans << endl;
	ans = 999999;
	for(int i = 1;i<=100;i++){
		for(int j = 1;j<=100;j++){
			visited[i][j] = 0;
		}
	}
	bfs(x2, y2, 0);
	cout << ans << endl;

	return 0;
}


