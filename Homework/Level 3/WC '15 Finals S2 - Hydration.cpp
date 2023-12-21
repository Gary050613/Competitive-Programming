#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, M, K, c[MM], t[MM];
bool check(int limit){
	for(int i = 1,j=1, cnt=0;j<=M;j++){
		while(i <= N && cnt < limit && c[i] - K <= t[j] && t[j] <= c[i]){
			i++; cnt++;
		}
		cnt = 0;
		if(i > N) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i <= N;i++) cin >> c[i];
	for(int j = 1; j <= M;j++) cin >> t[j];
	sort(c+1, c+N+1); sort(t+1, t+M+1);
	int lo = 1, hi = N, ans = -1;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}


