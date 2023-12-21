#include <bits/stdc++.h>
using namespace std;
int g[101][101], n, a[101], re[101];
int main(){
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> g[i][j];
		}
		a[i] = 999;
	}
	a[n] = 0;
	for(int i = n-1;i>=1;i--){
		for(int j = i+1;j<=n;j++){
			if(g[i][j] != 0){
				if(a[j] + g[i][j] < a[i]){
					a[i] = a[j] + g[i][j];
					re[i] = j;
				}
			}
		}
	}
	cout << "minlong=" << a[1] << "\n";
	int cur = 1;
	while(cur != n){
		cout << cur << " ";
		cur = re[cur];
	}
	cout << cur << "\n";
	
	return 0;
}

/*
10
0 2 5 1 0 0 0 0 0 0
0 0 0 0 12 14 0 0 0 0
0 0 0 0 6 10 4 0 0 0
0 0 0 0 13 12 11 0 0 0
0 0 0 0 0 0 0 3 9 0
0 0 0 0 0 0 0 6 5 0
0 0 0 0 0 0 0 0 10 0
0 0 0 0 0 0 0 0 0 5
0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0
*/
