#include <bits/stdc++.h>
using namespace std;

//bool comp(int a[], int b[]){
//	if(a[])
//}

int main(){
	
	int notes[1001][21], intervals[1001][21];
	int M, N, K, ans = 0;
	cin >> M >> N >> K;
	for(int i = 1;i<=M;i++){
		for(int j = 1;j<=N;j++){
			cin >> notes[i][j];
			if(j>=2){
				intervals[i][j-1] = notes[i][j] - notes[i][j-1];
			}
		}
	}
//	sort(intervals, intervals+M);
	for(int i = 1;i<=M;i++){
		for(int j = 1;j<=N-1;j++){
			cout << intervals[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 1;i<=N-1;i++){
		for(int j = 1;j<=M-1;j++){
			if(intervals[j][i] == intervals[j+1][i] && abs(notes[j+1][i] - notes[j][i]) == K){
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}


