#include <bits/stdc++.h>
using namespace std;

int m, n, e[16][16], visited[16][16] = {0};
int x2, y2;

void dfs(int x, int y, string str){
	if(x == x2 && y == y2){
		cout << str << endl;
		return;
	}
	if(visited[x][y] || e[x][y] == 0){
		return;
	}
	str += "->("+to_string(x)+","+to_string(y)+")";
	visited[x][y] = 1;
	if(x-1>0){
		dfs(x-1, y, str);
	}
	if(x+1<=x2){
		dfs(x+1, y, str);
	}
	if(y-1>0){
		dfs(x, y-1, str);
	}
	if(y+1<=y2){
		dfs(x, y+1, str);
	}
}

int main(){

	cin >> m >> n;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			cin >> e[i][j];
		}
	}
	int x1, y1;
	cin >> x1 >> y1 >> x2 >> y2;
	dfs(x1, y1, "("+to_string(x1)+","+to_string(y1)+")");

	return 0;
}


