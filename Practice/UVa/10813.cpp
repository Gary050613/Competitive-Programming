#include <bits/stdc++.h>
using namespace std;
int n, order[80], card[6][6], flag[6][6];

bool check(){
	// horizontal
	for(int i = 1;i<=5;i++){
		bool bingo=true;
		for(int j = 1;j<=5;j++){
			if(!flag[i][j]) bingo = false;
		}
		if(bingo) return true;
		bingo = true;
		for(int j = 1;j<=5;j++){
			if(!flag[j][i]) bingo = false;
		}
		if(bingo) return true;
	}
	// diagnal
	bool bingo = true;
	for(int i = 1;i<=5;i++){
		if(!flag[i][i]) bingo = false;
	}
	if(bingo) return true;
	bingo = true;
	for(int i = 1;i<=5;i++){
		if(!flag[i][6-i]) bingo = false;
	}
	return bingo;
}

int main(){
	cin >> n;
	while(n--){
		memset(flag, 0, sizeof(flag));
		for(int i = 1;i<=5;i++){
			if(i != 3){
				for(int j=1;j<=5;j++){
					cin >> card[i][j];
				}
			}else{
				cin >> card[i][1] >> card[i][2] >> card[i][4] >> card[i][5];
			}
		}
		for(int i = 1;i<=75;i++) cin >> order[i];
		flag[3][3] = 1;
		for(int i = 1;i<=75;i++){
			bool b = false;
			for(int x = 1;x<=5;x++){
				for(int y = 1;y<=5;y++){
					if(order[i] == card[x][y]){
						flag[x][y] = 1;
						b = 1;
					}
				}
			}
			if(b){
				if(check()){
					printf("BINGO after %d numbers announced\n", i);
					break;
				}
			}
		}
	}
	return 0;
}


