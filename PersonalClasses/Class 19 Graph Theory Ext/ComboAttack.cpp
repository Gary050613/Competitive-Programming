#include <bits/stdc++.h>
using namespace std;
int n, g[1000001][2], ans = 0, used[1000001] = {0};

void dfs(int c){
	ans = max(ans, c-1);
	for(int i = 1;i<=n;i++){
		if(!used[i] && (g[i][0] == c || g[i][1] == c)){
			used[i] = 1;
			dfs(c+1);
			used[i] = 0;
		}
	}
}

int main(){
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> g[i][0] >> g[i][1];
	}
	dfs(1);
	cout << ans << endl;
	
	return 0;
}


