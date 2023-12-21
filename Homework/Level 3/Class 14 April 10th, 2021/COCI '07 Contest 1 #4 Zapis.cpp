#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 202, mod = 1e5;
int n; ll dp[MM][MM]; string s;
int get(char a, char b){
	if(a == b && a == '?') return 3;
	if((a == '?' && (b==')'||b==']'||b=='}')) || ((a=='('||a=='['||a=='{')&&b=='?')
		|| (a=='('&&b==')') || (a=='{'&&b=='}') || (a=='['&&b==']')){
			return 1;
		}
	return 0;
}
ll fun(int L, int R){
	if(L >= R) return 1;
	if(dp[L][R] != -1) return dp[L][R];
	ll &ret = dp[L][R]; ret = 0;
	for(int m = L+1; m<=R;m+=2){
		int coef = get(s[L], s[m]);
		ret += fun(L+1, m-1)*fun(m+1, R)*coef;
		if(ret >= mod) ret = ret % mod + mod;
	}
	return ret;
}

int main(){
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	ll ans = fun(0, n-1);
	if(ans >= mod) cout << setw(5) << setfill('0') << ans % mod << endl;
	else cout << ans << endl;
	return 0;
}


