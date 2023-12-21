#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, R, C, cnt=1;
	bool g[1001][1001] = {0};
	cin >> T;
	while(T--){
		cin >> R >> C;
		for(int i = 1;i<=R;i++){
			for(int j = 1;j<=C;j++){
				cin >> g[i][j];
			}
		}
	}
	return 0;
}


