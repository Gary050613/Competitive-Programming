#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 1e5+5;
ll n, dp[MM]={0};
// DP state: dp[i] = sum dp[i/2~i]
int main(){
	dp[0]=0;
	dp[1]=1;
	cin >> n;
	for(int i = 2;i<=n;i++){
		for(int j = i;j>=2;j--){
			dp[i] += dp[(i/j)];
		}
	}
	cout << dp[n] << endl;
	return 0;
}


