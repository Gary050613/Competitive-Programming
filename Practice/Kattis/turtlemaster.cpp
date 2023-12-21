#include <bits/stdc++.h>
using namespace std;
const int MM = 8+1;
char board[MM][MM]; string seq; int x=8, y=1, dir=1, ans=1;
// dir: 
//   N      0
// W   E  3   1
//   S      2
int main(){
	for(int i = 1;i<=8;i++){
		for(int j = 1;j<=8;j++){
			cin >> board[i][j];
		}
	}
	cin >> seq;
	for(int i = 0;i<seq.length();i++){
		switch(seq[i]){
			case 'F':
				if(dir == 1) y++;
				else if(dir == 2) x++;
				else if(dir == 3) y--;
				else if(dir == 0) x--;
				if(x>8 || x<1 || y>8 || y<1 || board[x][y] == 'C' || board[x][y] == 'I') ans=0;
				break;
			case 'R':
				dir = (dir+1)%4;
				break;
			case 'L':
				dir = (dir+3)%4;
				break;
			case 'X':
				int bx = x, by = y;
				if(dir == 1) by++;
				else if(dir == 2) bx++;
				else if(dir == 3) by--;
				else if(dir == 0) bx--;
				if(board[bx][by]=='I') board[bx][by] = '.';
				else ans=0;
				break;
		}
	}
	if(!ans || board[x][y] != 'D') cout << "Bug!\n";
	else cout << "Diamond!\n";
	return 0;
}


