#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int v, e, x, y, a;
	cin >> v >> e;
	int matrix[v+1][v+1] = {0};
	while(e--){
		cin >> x >> y >> a;
		matrix[x][y] = a;
		matrix[y][x] = a;
	}
	for(int i = 1;i<=v;i++){
		for(int j = 1;j<=v;j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}


