/*
ID: gary0501
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ifstream cin("transform.in");
	ofstream cout("transform.out");
	
	int N, ans=7;
	char before[11][11], after[11][11], reflected[11][11];
	cin >> N;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> before[i][j];
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> after[i][j];
		}
	}
	
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(after[j][N-i-1] != before[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 1;
			}
		}
	}
	
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(after[N-i-1][N-j-1] != before[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 2;
			}
		}
	}
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(after[N-j-1][i] != before[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 3;
			}
		}
	}
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(after[i][N-j-1] != before[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 4;
			}
		}
	}
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			reflected[i][N-j-1] = before[i][j];
		}
	}
	// 4
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(reflected[j][N-i-1] != after[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 5;
			}
		}
	}
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(reflected[N-i-1][N-j-1] != after[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 5;
			}
		}
	}
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(reflected[N-j-1][i] != after[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 5;
			}
		}
	}
	if(ans == 7){
		for(int i = 0;i<N;i++){
			for(int j = 0;j<N;j++){
				if(after[i][j] != before[i][j]){
					i=N, j=N;
					break;
				}
				if(i == N-1 && j == N-1) ans = 6;
			}
		}
	}
//	for(int i = 0;i<N;i++){
//		for(int j = 0;j<N;j++){
//			cout << reflected[i][j];
//		}
//		cout << endl;
//	}
	cout << ans << endl;
	return 0;
}


