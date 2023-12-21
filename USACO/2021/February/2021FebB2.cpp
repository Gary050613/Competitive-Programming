#include <bits/stdc++.h>
using namespace std;
bool isCow[1001][1001] = {0};
int surround[1001][1001] = {0};
int main(){
	
	int n, x, y, ans = 0;
	cin >> n;
	while(n--){
		cin >> x >> y;
		isCow[x][y] = 1;
		if(surround[x][y] == 3){
			ans++;
		}
		if(x-1>=0){
			if(surround[x-1][y]==3 && isCow[x-1][y] == 1){
				ans--;
			}
			surround[x-1][y]++;
			if(surround[x-1][y]==3 && isCow[x-1][y] == 1){
				ans++;
			}
		}
		if(y-1>=0){
			if(surround[x][y-1]==3 && isCow[x][y-1] == 1){
				ans--;
			}
			surround[x][y-1]++;
			if(surround[x][y-1]==3 && isCow[x][y-1] == 1){
				ans++;
			}
		}
		if(x+1<=1000){
			if(surround[x+1][y]==3 && isCow[x+1][y] == 1){
				ans--;
			}
			surround[x+1][y]++;
			if(surround[x+1][y]==3 && isCow[x+1][y] == 1){
				ans++;
			}
		}
		if(y+1<=1000){
			if(surround[x][y+1]==3 && isCow[x][y+1] == 1){
				ans--;
			}
			surround[x][y+1]++;
			if(surround[x][y+1]==3 && isCow[x][y+1] == 1){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}


