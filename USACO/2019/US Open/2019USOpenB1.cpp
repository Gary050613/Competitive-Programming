#include <bits/stdc++.h>
using namespace std;
char g[11][11];
bool v[11][11] = {0};
int x, y, ans = 0;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//int test[11][11] = {0};

struct coord{
	int x, y, steps;
} que[101];

void bfs(){
	int head=0,tail=0;
	que[tail].x = x;
	que[tail].y = y;
	que[tail].steps = 0;
	tail++;
	v[x][y] = 1;
	while(head < tail){
		for(int k = 0;k < 4;k++){
			int tx = que[head].x + dir[k][0];
			int ty = que[head].y + dir[k][1];
			if(tx < 0 || ty < 0 || tx > 9 || ty > 9){
				continue;
			}
//			cout << tx << " " << ty << endl;
			if(g[tx][ty] == 'L'){
				ans = que[head].steps;
				return;
			}
			if(g[tx][ty] == '.' && v[tx][ty] == 0){
				v[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].steps = que[head].steps + 1;
//				test[tx][ty] = que[tail].steps;
				tail++;
			}
		}
		head++;
	}
}

int main(){
	
	ifstream cin ("buckets.in");
	ofstream cout ("buckets.out");
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++){
			cin >> g[i][j];
			if(g[i][j] == 'B'){
				x = i, y = j;
			}
		}
	}
	bfs();
//	for(int i = 0;i<10;i++){
//		for(int j = 0;j<10;j++){
//			cout << test[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << ans << endl;
	
	return 0;
}


