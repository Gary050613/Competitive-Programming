#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	int family[n+1][n+1];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == j){
				family[i][j] = 1;
			}else{
				family[i][j] = 9;
			}
		}
	}
	int a, b;
	for(int i = 1;i<=m;i++){
		cin >> a >> b;
		family[a][b] = 1;
		family[b][a] = 1;
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(family[k][i] == 1 && family[k][j] == 1){
					family[i][j] = 1;
					family[j][i] = 1;
				}
			}
		}
	}
	int q, c, d;
	cin >> q;
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << family[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i<=q;i++){
		cin >> c >> d;
		if(family[c][d] == 1){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}


