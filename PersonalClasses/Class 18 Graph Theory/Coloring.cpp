#include <bits/stdc++.h>
using namespace std;

int n, m, k, g[201][201]={0}, color[201]={0}, num=0;

bool check(int sum){
	for(int i = 1;i<=sum;i++){
		if(g[i][sum] == 1 && color[i] == color[sum]){
			return false;
		}
	}
	return true;
}

void dfs(int s){
	if(s > n){
		num++;
		return;
	}
	for(int i = 1;i<=m;i++){
		color[s] = i;
		if(check(s)){
			dfs(s+1);
		}else{
			color[s] = 0;
		}
	}
}

int main(){
	
	cin >> n >> k >> m;
	while(k--){
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	dfs(1);
	cout << num << endl;
	
	return 0;
}


