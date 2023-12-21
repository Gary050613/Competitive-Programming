#include <bits/stdc++.h>
using namespace std;
int visited[6][6] = {0}, ans = 0;
int horsex[8] = {1,2,2,1,-1,-2,-2,-1},
	horsey[8] = {-2,-1,1,2,2,1,-1,-2};
int steps[6][6];

void print(){
	ans++;
	if(ans<= 5){
		for(int i = 1;i<=5;i++){
			for(int j = 1;j<=5;j++){
				cout << steps[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void bfs(int x, int y, int count){
	if(count > 25){
		print();
		return;
	}
	for(int i = 0;i<8;i++){
		int nx = x + horsex[i], ny = y + horsey[i];
		if(nx > 0 && nx <= 5 && ny > 0 && ny <=5 && visited[nx][ny] == 0){
			steps[nx][ny] = count;
			visited[nx][ny] = 1;
			bfs(nx, ny, count+1);
			visited[nx][ny] = 0;
			steps[nx][ny] = 0;
		}
	}
}

int main(){
	steps[1][1] = 1;
	visited[1][1] = 1;
	bfs(1,1,2);
	cout << ans << endl;
	return 0;
}


