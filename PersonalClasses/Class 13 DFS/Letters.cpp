#include <bits/stdc++.h>
using namespace std;

int row, col, ans = 0;
char e[101][101];
bool visited[26]={0};

void dfs(int x, int y, int a){
	if(visited[e[x][y]-'A'] == true){
		ans = max(ans, a);
		return;
	}
	visited[e[x][y]-'A'] = true;
	a++;
	if(x-1 > 0){
		dfs(x-1,y,a);
	}
	if(x+1 <= row){
		dfs(x+1,y,a);
	}
	if(y-1 > 0){
		dfs(x, y-1,a);
	}
	if(y+1 <= col){
		dfs(x, y+1,a);
	}
}

int main(){

	cin >> row >> col;
	for(int i = 1;i<=row;i++){
		for(int j = 1;j<=col;j++){
			cin >> e[i][j];
		}
	}
	dfs(1,1,0);
	cout << ans << endl;

	return 0;
}


