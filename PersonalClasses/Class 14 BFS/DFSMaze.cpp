#include <bits/stdc++.h>
using namespace std;

int n, m, e[101][101], startx, starty, endx, endy, visited[101][101] = {0};
bool ans = 0;

void dfs(int x, int y, string str){
	if(e[x][y] == -1 || visited[x][y] == 1){
		return;
	}
	visited[x][y] = 1;
	str += to_string(x) + "," + to_string(y) + "\n"; 
	if(x == endx && y == endy){
		cout << str;
		ans = 1;
		return;
	}
	if(x-1>0){
		dfs(x-1, y, str);
	}
	if(x+1<=n){
		dfs(x+1, y, str);
	}
	if(y-1>0){
		dfs(x, y-1, str);
	}
	if(y+1<=n){
		dfs(x, y+1,str);
	}
}

int main(){

	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> e[i][j];
		}
	}
	cin >> startx >> starty >> endx >> endy;
	dfs(startx,starty,"");
	if(!ans){
		cout << "no way." << endl;
	}

	return 0;
}


