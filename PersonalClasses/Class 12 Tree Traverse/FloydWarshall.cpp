#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int e[n+1][n+1];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin >> e[i][j];
		}
	}
	// Floyd-Warshall Shortest Path Algorithm
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(e[i][j] > e[i][k] + e[k][j]){
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout << e[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


