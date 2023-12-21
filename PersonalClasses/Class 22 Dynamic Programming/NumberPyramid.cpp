#include <bits/stdc++.h>
using namespace std;
int g[1001][1001]={0};
int main(){
	
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			cin >> g[i][j];
		}
	}
	for(int i = n-1;i>=1;i--){
		for(int j = 1;j<=i;j++){
			g[i][j] = max(g[i+1][j], g[i+1][j+1]) + g[i][j];
		}
	}
	cout << g[1][1] << endl;
	
	return 0;
}


