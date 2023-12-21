#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5; const ll inf = 1e18;
int N; vector<tuple<ll, ll, ll>> v; ll s, f, h, dp[MM];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N; v.emplace_back(0, 0, 0);
	for(int i = 1;i<=N;i++){
		cin >> s >> f >> h;
		v.emplace_back(s+f, s, h);
	}
	sort(v.begin(), v.end());
	for(int i = 1;i<=N;i++){
		s = get<1>(v[i]);
		h = get<2>(v[i]);
		int pos = upper_bound(v.begin(), v.end(), make_tuple(s, inf, inf)) - v.begin() - 1;
		dp[i] = max(dp[i-1], h + dp[pos]);
	}
	cout << dp[N] << endl;
	return 0;
}


