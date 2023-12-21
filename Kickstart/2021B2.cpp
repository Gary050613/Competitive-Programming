#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5;
int T, N, dp[MM]={0}, arr[MM], diff[MM]; string str;
int main(){
	cin >> T;
	for(int cnt = 1;cnt<=T;cnt++){
		cin >> N;
		for(int i = 0;i<N;i++) cin >> arr[i];
		for(int i = 1;i<N;i++) diff[i] = arr[i]-arr[i-1];
		
		printf("Case #%d: %d\n", cnt, ans);
	}
	return 0;
}


