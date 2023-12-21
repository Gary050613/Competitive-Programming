#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
	string s;
} que[10001];

int main(){

	int n, m, e[101][101], visited[101][101] = {0};
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> e[i][j];
		}
	}
	int startx, starty, endx, endy;
	cin >> startx >> starty >> endx >> endy;
	int front = 1, back = 1, step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	que[back].x = startx;
	que[back].y = starty;
	que[back].s = to_string(startx) + "," + to_string(starty) + "\n";
	back++;
	visited[startx][starty] = 1;
	int t = 0;
	while(front < back){
		for(int k = 0;k<4;k++){
			int tx = que[front].x + step[k][0], ty = que[front].y + step[k][1];
			if(tx <= 0 || ty <= 0 || tx > n || ty > m){
				continue;
			}
			if(e[tx][ty] == 0 && visited[tx][ty] == 0){
				visited[tx][ty] = 1;
				que[back].x = tx;
				que[back].y = ty;
				que[back].s = que[front].s + to_string(tx)+","+to_string(ty)+"\n";
				back++;
			}
			if(tx == endx && ty == endy){
				t = 1;
				break;
			}
		}
		if(t == 1){
			break;
		}
		front++;
	}
	if(t==1){
		cout << que[back-1].s;
	}else{
		cout << "no way." << endl;
	}
	return 0;
}


