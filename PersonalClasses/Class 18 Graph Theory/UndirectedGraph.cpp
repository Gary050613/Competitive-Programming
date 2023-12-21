#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int v, e, x, y;
	cin >> v >> e;
	int matrix[v+1][v+1] = {0};
	while(e--){
		cin >> x >> y;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}
	for(int i = 1;i<=v;i++){
		for(int j = 1;j<=v;j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	
	return 0;
}


