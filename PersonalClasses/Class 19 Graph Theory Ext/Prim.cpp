#include <bits/stdc++.h>
using namespace std;
int n, g[101][101]={0}, ans[101], visited[101]={0};
int main(){
	
	cin >> n;
	int a, b, w;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> g[i][j];
		}
	}
	memset(ans, 999999, sizeof(ans));
	ans[0] = 0;
	for(int i = 0;i<n;i++){
		if(!visited[i]){
			visited[i] = 1;
			for(int j = 0;j<n;j++){
				if(!visited[j] && g[i][j] != 0){
					ans[j] = min(ans[j], g[i][j]);
				}
			}
		}
	}
	int result = 0;
	for(int i = 0;i<n;i++){
		result += ans[i];
	}
	cout << result << endl;
	
	return 0;
}


