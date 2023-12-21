#include <bits/stdc++.h>
using namespace std;
bool space[201][201]={0};

void bfs(int x, int y){
	if(space[x][y] == 1){
		return;
	}
	space[x][y] = 1;
	if(x-1 >= 0){
		bfs(x-1, y);
	}
	if(y-1 >= 0){
		bfs(x, y-1);
	}
	if(x+1 <= 201){
		bfs(x+1, y);
	}
	if(y+1 <= 201){
		bfs(x, y+1);
	}
}

int main(){
	int x = 100, y = 100;
	space[x][y] = 1;
	int n;
	char str[101];
	cin >> n;
	while(n--){
		memset(space, 0, sizeof(space));
		cin >> str;
		int len = strlen(str);
		for(int i = 0;i<len;i++){
			if(str[i] == 'W'){
				space[x][y-1] = 1;
				space[x][y-2] = 1;
				y -= 2;
			}else if(str[i] == 'E'){
				space[x][y+1] = 1;
				space[x][y+2] = 1;
				y += 2;
			}else if(str[i] == 'N'){
				space[x-1][y] = 1;
				space[x-2][y] = 1;
				x -= 2;
			}else if(str[i] == 'S'){
				space[x+1][y] = 1;
				space[x+2][y] = 1;
				x += 2;
			}
		}
		bfs(200,200);
		x = 100, y = 100;
		if(str[0] == 'N'){
			if(space[x-1][y+1] == 0){
				cout << "CW\n";
			}else if(space[x-1][y-1] == 0){
				cout << "CCW\n";
			}
		}else if(str[0] == 'S'){
			if(space[x+1][y-1] == 0){
				cout << "CW\n";
			}else if(space[x+1][y+1] == 0){
				cout << "CCW\n";
			}
		}else if(str[0] == 'W'){
			if(space[x-1][y-1] == 0){
				cout << "CW\n";
			}else if(space[x+1][y-1] == 0){
				cout << "CCW\n";
			}
		}else if(str[0] == 'E'){
			if(space[x+1][y+1] == 0){
				cout << "CW\n";
			}else if(space[x-1][y+1] == 0){
				cout << "CCW\n";
			}
		}
//		for(int i = 90;i<=110;i++){
//			for(int j = 90;j<=110;j++){
//				cout << space[i][j] << " ";
//			}
//			cout << endl;
//		}
	}
	return 0;
}


