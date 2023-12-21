#include <bits/stdc++.h>
using namespace std;
const int MM = 72;
struct E {
	int k, p, f;
};
int N, cost, dp[MM][MM][MM], psa[MM]; E a[MM];
bool cmpPriority(E x, E y){ return x.p < y.p; }
bool cmpKey(E x, E y){ return x.k < y.k; }
int fun(int l, int r, int w){
	if(l > r) return 0;
	if(dp[l][r][w] != -1) return dp[l][r][w];
	int ans = INT_MAX, sum = psa[r]-psa[l-1];
	for(int m = l;m <= r;m++) {
		ans = min(ans, fun(l, m-1, w) + fun(m+1, r, w) + sum +cost);
		if(a[m].p >= w) ans = min(ans, fun(l, m-1, a[m].p) + fun(m+1, r, a[m].p) + sum);
	}
	return dp[l][r][w] = ans;
}
int main(){
	cin >> N >> cost;
	for(int i=1;i<=N;i++) cin >> a[i].k;
	for(int i=1;i<=N;i++) cin >> a[i].p;
	for(int i=1;i<=N;i++) cin >> a[i].f;
	sort(a+1, a+N+1, cmpPriority);
	for(int i=1;i<=N;i++) a[i].p = i;
	sort(a+1, a+N+1, cmpKey);
	for(int i=1;i<=N;i++) psa[i] = psa[i-1] + a[i].f;
	memset(dp, -1, sizeof(dp));
	cout << fun(1, N, 0) << endl;
	return 0;
}


