#include <bits/stdc++.h>
using namespace std;
const int maxn = 999999;

int main(){

	int n, m, a, b;
	cin >> n >> m;
	int map[n+1][n+1], record[n+1][n+1] = {0};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j){
				map[i][j] = 0;
			}else{
				map[i][j] = maxn;
			}
		}
	}
	for(int i = 0;i<m;i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
					record[i][j] = k;
				}
			}
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << record[i][j] << " ";
//		}
//		cout << endl;
//	}
	int i=1;
	cout << "1->";
	while(record[i][n]!=0){
		cout << record[i][n] << "->";
		i = record[i][n];
	}
	cout << "8";
	return 0;
}


