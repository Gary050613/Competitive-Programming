#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int sum[9][9];
int res[15][9][9][9][9];

int sumOfBoard(int x1, int y1, int x2, int y2){
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

int fun(int n, int x1, int y1, int x2, int y2){
	int t, MIN = INT_MAX;
	if(n==1){
		return sumOfBoard(x1, y1, x2, y2);
	}
	for(int i = x1;i<x2;i++){
		
	}
	
}

int main(){

	int n;
	

	return 0;
}


