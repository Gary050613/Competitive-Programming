#include <bits/stdc++.h>
using namespace std;
char board[20][20];
bool taken[20][20]={0};

void update(int x, int y, int i, int j){
	x+=i, y+=j;
	while(x <= 12 && y <= 12 && x >= 5 && y >= 5){
		if(board[x][y]==' '){
			taken[x][y] = 1;
			x+=i, y+=j;
		}else{
			taken[x][y] = 1;
			break;
		}
	}
}

int main(){
	
	string input;
	int ans;
	while(cin >> input){
		for(int i = 5;i<=12;i++){
			for(int j = 5;j<=12;j++){
				board[i][j] = ' ';
				taken[i][j] = 0;
			}
		}
		int curx = 5, cury=5;
		for(int i = 0;i<input.length();i++){
			if(input[i]=='/'){
				curx++;
				cury=5;
				continue;
			}else if(isalpha(input[i])){
				board[curx][cury++] = input[i];
			}else{
				cury+=input[i]-'0';
			}
		}
		// Output Board status
//		for(int i = 5;i<=12;i++){
//			for(int j = 5;j<=12;j++){
//				cout << board[i][j] << " ";
//			}
//			cout << endl;
//		}
		for(int i = 5;i<=12;i++){
			for(int j = 5;j<=12;j++){
				if(board[i][j]==' ') continue;
				else if(board[i][j]=='P'){
					taken[i][j]=1, taken[i-1][j+1]=1, taken[i-1][j-1]=1;
				}else if(board[i][j]=='p'){
					taken[i][j]=1, taken[i+1][j+1]=1, taken[i+1][j-1]=1;
				}else if(board[i][j]=='N' || board[i][j]=='n'){
					taken[i][j]=1;
					taken[i-2][j+1]=1; 
					taken[i-1][j+2]=1; 
					taken[i+1][j+2]=1; 
					taken[i+2][j+1]=1; 
					taken[i+2][j-1]=1; 
					taken[i+1][j-2]=1; 
					taken[i-1][j-2]=1; 
					taken[i-2][j-1]=1;
				}else if(board[i][j]=='B' || board[i][j]=='b'){
					taken[i][j]=1;
					update(i, j, 1, 1);
					update(i, j, 1, -1);
					update(i, j, -1, -1);
					update(i, j, -1, 1);
				}else if(board[i][j]=='R' || board[i][j]=='r'){
					taken[i][j]=1;
					update(i, j, 1, 0);
					update(i, j, 0, 1);
					update(i, j, -1, 0);
					update(i, j, 0, -1);
				}else if(board[i][j]=='Q' || board[i][j]=='q'){
					taken[i][j]=1;
					update(i, j, 1, 1);
					update(i, j, 1, -1);
					update(i, j, -1, -1);
					update(i, j, -1, 1);
					update(i, j, 1, 0);
					update(i, j, 0, 1);
					update(i, j, -1, 0);
					update(i, j, 0, -1);
				}else if(board[i][j]=='K' || board[i][j]=='k'){
					taken[i][j]=1;
					taken[i-1][j]=1;
					taken[i-1][j+1]=1;
					taken[i][j+1]=1;
					taken[i+1][j+1]=1;
					taken[i+1][j]=1;
					taken[i+1][j-1]=1;
					taken[i][j-1]=1;
					taken[i-1][j-1]=1;
				}
//				for(int i = 5;i<=12;i++){
//					for(int j = 5;j<=12;j++){
//						cout << taken[i][j] << " ";
//					}
//					cout << endl;
//				}
//				cout << endl;
			}
		}
		ans = 0;
		for(int i = 5;i<=12;i++){
			for(int j = 5;j<=12;j++){
				if(!taken[i][j]) ans++;
//				cout << taken[i][j] << " ";
			}
//			cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}


