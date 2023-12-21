#include <bits/stdc++.h>
using namespace std;
int n, w[201], g[201][201], re[201], m[201];

int dp(int i){
	if(i == n){
		return w[i];
	}
	if(m[i] != 0){
		return m[i];
	}
	for(int j = 1;j<=n;j++){
		if(g[i][j] == 1){
			int b = dp(j);
			if(b + w[i] > m[i]){
				m[i] = b + w[i];
				re[i] = j;
			}
		}
	}
	return m[i];
}

int main(){
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> w[i];
		m[i] = 0;
	}
	int a, b;
	while(cin >> a >> b && a!=0 && b!=0){
		g[a][b] = 1;
	}
	m[n] = w[n];
	for(int i = 1;i<=n;i++){
		if(m[i] == 0){
			dp(i);
		}
	}
	int ans = 0, start = 1;
	for(int i = 1;i<=n;i++){
		if(m[i] > ans){
			ans = m[i];
			start = i;
		}
	}
	while(start != n){
		cout << start << "-";
		start = re[start];
	}
	cout << start << "\n";
	cout << ans << endl;
	
	return 0;
}

/*
6
5 10 20 5 4 5
1 2
1 4
2 4
3 4
4 5
4 6
5 6
0 0
*/
